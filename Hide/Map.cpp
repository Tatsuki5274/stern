﻿#include"Map.h"
#include"DxLib.h"
#include"CoreTask.h"
#include<fstream>
#include <string>
#include <sstream>
#include<algorithm>
#include "json11.hpp"
//1津のチップの大きさを30と考える(勝手)//チップサイズは32が妥当
#define chipsize 64

//----------------------------------
//マップデータ
//----------------------------------

Map::Map()
{
	
}

void Map::init(char* map_, char* chipdata_)
{
	std::ifstream mappath("img/mappath.json");
	if (mappath.fail())
	{
		throw std::runtime_error("mappath.json is not found.");	//ファイルが読み込めないと例外を返す
	}
	std::istreambuf_iterator<char> it(mappath);
	std::istreambuf_iterator<char> last;
	std::string json_str(it, last);		//string形式のjson
	std::string err;
	mapdata = json11::Json::parse(json_str, err);	//json11で利用できる形式に変換

	map = mapdata[map_]["chip"];
	chipdata = mapdata[chipdata_];


	//可変
	mapsizex = map["width"].int_value();
	mapsizey = map["height"].int_value();

	//使う画像決定
	graph = LoadGraph(chipdata["chipdata"].string_value().c_str());

	//csvを読み込む
	chipmap = map["data"].string_value().c_str();

	std::ifstream fin(chipmap);

	for (int y = 0; y < mapsizey / chipsize; ++y) {
		std::string lineText;
		getline(fin, lineText);
		std::istringstream ss_lt(lineText);
		for (int x = 0; x < mapsizex / chipsize; ++x) {
			std::string  tc;
			getline(ss_lt, tc, ',');
			std::stringstream ss;
			ss << tc;
			ss >> data[y][x]; //データを入れる
		}
	}
	mappath.close();	//ファイルを閉じる
	fin.close();

	////使う画像決定
	//graph = LoadGraph(chipfp);
	////ファイル読み込み
	//std::ifstream mapdata(mapfp);
	//if (!mapdata) { return; }
	//for (int y = 0; y < mapsizey / chipsize; ++y) {
	//	for (int x = 0; x < mapsizex / chipsize; ++x) {
	//		mapdata >> data[y][x];
	//	}
	//}
	////ファイル閉じ
	//mapdata.close();
}

void Map::draw()
{
	/*for (int y = 0; y < mapsizey / (mapsizey / chipsize); ++y) {
		for (int x = 0; x < mapsizex / (mapsizex / chipsize); ++x) {
		if (ct->gts->camera->get_range().x > x * chipsize ||
			ct->gts->camera->get_range().x + ct->gts->camera->get_range().w < x * chipsize + chipsize ||
			ct->gts->camera->get_range().y > y * chipsize ||
			ct->gts->camera->get_range().y + ct->gts->camera->get_range().h < y * chipsize + chipsize) {
			return;
			}
		}
	}*/
	


	isr.x = max(Camera::get_range().x, 0);
	isr.y = max(Camera::get_range().y, 0);
	isr.w = min(Camera::get_range().x + Camera::get_range().w, mapsizex);
	isr.h = min(Camera::get_range().y + Camera::get_range().h, mapsizey);

	sx = isr.x / chipsize;
	sy = isr.y / chipsize;
	ex = (isr.w - 1) / chipsize;
	ey = (isr.h - 1) / chipsize;

	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			DrawRectGraph((x * chipsize) - ct->gts->camera->get_range().x, y * chipsize, data[y][x] * chipsize % chipdata["width"].int_value(),
				data[y][x] * chipsize / chipdata["height"].int_value(), chipsize, chipsize, graph, FALSE);
			DrawRectGraph((x * chipsize) - Camera::get_range().x, y * chipsize, data[y][x] * chipsize, 0, chipsize, chipsize, graph, FALSE);
		}
	}
}

void Map::update()
{
	draw();
}
//-----------------------------------------------------------------------------------------------------------
//問題点　charaが二つのマップチップをまたいでいるとき左（または上)のチップのみリターンされ、ほかのチップが無視される
//-----------------------------------------------------------------------------------------------------------
/*int Map::get_left(Point chara_)
{
	int sx = (chara_.x-1 )/ chipsize;
	int sy = chara_.y / chipsize;
	int ex = chara_.x / chipsize;
	int ey = (chara_.y + chara_.h) / chipsize;
	for (int y = sy; y < ey; ++y) {
		for (int x = sx; sx < ex; ++x) {
			return data[y][x];
		}
	}
	return 0;
}

int Map::get_right(Point chara_)
{
	int sx = (chara_.x + chara_.w) / chipsize;
	int sy = chara_.y / chipsize;
	int ex = ((chara_.x + chara_.w) +1)/ chipsize;
	int ey = (chara_.y + chara_.h) / chipsize;
	for (int y = sy; y < ey; ++y) {
		for (int x = sx; sx < ex; ++x) {
			return data[y][x];
		}
	}
	return 0;
}

int Map::get_top(Point chara_)
{
	int sx = chara_.x/ chipsize;
	int sy = (chara_.y-1) / chipsize;
	int ex = (chara_.x + chara_.w) / chipsize;
	int ey = chara_.y / chipsize;
	for (int y = sy; y < ey; ++y) {
		for (int x = sx; sx < ex; ++x) {
			return data[y][x];
		}
	}
	return 0;
}

int Map::get_bottom(Point chara_)
{
	//マップタイル１つが30*30のため
	int sx = chara_.x / chipsize;
	int sy = (chara_.y + chara_.h) / chipsize;
	int ex = (chara_.x + chara_.w) / chipsize;
	int ey = ((chara_.y + chara_.h)+1) / chipsize;
	//範囲内の障害物を探す
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; sx <= ex; ++x) {
			return data[y][x];
		}
	}
	return 0;
}*/
//-----------------------------------------------------------------------------------------------------------
//仮処理　チップが当たり判定を持っているときのみ1を返す　今後ダメージ床は2を返すなどの拡張が可能
//-----------------------------------------------------------------------------------------------------------
int Map::get_left(Point chara_)
{
	int sx = chara_.x / chipsize;
	int sy = chara_.y / chipsize;
	int ex = chara_.x / chipsize;
	int ey = (chara_.y + chara_.h-1) / chipsize;
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			if (data[y][x] >= 1) {//今回の場合は１のチップのみに当たり判定を持たせる
				return 1;
			}
			
		}
	}
	return 0;
}

int Map::get_right(Point chara_)
{
	int sx = (chara_.x + chara_.w-1) / chipsize;
	int sy = chara_.y / chipsize;
	int ex = (chara_.x + chara_.w-1) / chipsize;
	int ey = (chara_.y + chara_.h-1) / chipsize;
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			if (data[y][x] >= 7) {//今回の場合は7のチップのみに当たり判定を持たせる
				return 1;
			}

		}
	}
	return 0;
}

int Map::get_top(Point chara_)
{
	int sx = chara_.x / chipsize;
	int sy = chara_.y / chipsize;
	int ex = (chara_.x + chara_.w-1) / chipsize;
	int ey = chara_.y / chipsize;
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			if (data[y][x] >= 7) {//今回の場合は7のチップのみに当たり判定を持たせる
				return 1;
			}

		}
	}
	return 0;
}

int Map::get_bottom(Point chara_)
{
	int sx = chara_.x / chipsize;
	int sy = (chara_.y + chara_.h-1) / chipsize;
	int ex = (chara_.x + chara_.w-1) / chipsize;
	int ey = (chara_.y + chara_.h-1) / chipsize;
	//範囲内の障害物を探す
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			if (data[y][x] >= 7) {//今回の場合は7のチップのみに当たり判定を持たせる
				return 1;
			}
		}
	}
	return 0;
}
int Map::get_circle(Point star_,int r_)
{
	/*int sx = (star_.x-r_) / chipsize;//本来はこのはずだが描画と当たり判定がずれている
	int sy = (star_.y-r_) / chipsize;
	int ex = (star_.x + r_ ) / chipsize;
	int ey = (star_.y + r_ ) / chipsize;*/
	int sx = (star_.x-1 ) / chipsize;
	int sy = (star_.y-1 ) / chipsize;
	int ex = (star_.x + r_*3) / chipsize;
	int ey = (star_.y + r_*3) / chipsize;
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			if (data[y][x] >= 7) {//今回の場合は7のチップのみに当たり判定を持たせる
				return 1;
			}

		}
	}
	return 0;
}
