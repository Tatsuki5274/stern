#include"GraphicResource.h" 
#include"DxLib.h" 
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include "json11.hpp"

void GraphicObject::set_default_to_empty()
{
	//未定義の項目に対していデフォルト値を設定する
	if (column == 0) column = 1;
	if (line == 0) line = 1;
	if (width == 0) width = 32;
	if (height == 0) height = 32;
	//if (speed == 0) speed = 0;
	//if (loop == false) loop = false;
	if (sheets == 0) sheets = line * column;
}

bool GraphicObject::exits_scope(std::string _scope)
{
	bool ret = false;
	for (auto&& scope : scopes) {
		if (scope == _scope) {
			ret = true;
			break;
		}
	}
	return ret;
}

GraphicObject::~GraphicObject()
{
	for (int i = 0; i < sheets; i++) {
		DeleteGraph(*(handle + i));
	}
	delete handle;
}

GraphicResource::GraphicResource()
{
	std::ifstream ifs("img/resource.json");
	if (ifs.fail())
	{
		throw std::runtime_error("resource.json is not found.");	//ファイルが読み込めないと例外を返す
	}
	json11::Json json;
	std::istreambuf_iterator<char> it(ifs);
	std::istreambuf_iterator<char> last;
	std::string json_str(it, last);		//string形式のjson
	std::string err;
	json = json11::Json::parse(json_str,err);	//json11で利用できる形式に変換

	for (auto &item : json["graph"].array_items()) {	//名前登録とfalse初期化
		GraphicObject obj;
		obj.exist = false;
		obj.name = item["name"].string_value();
		obj.path = item["path"].string_value();
		obj.column = item["column"].int_value();
		obj.line = item["line"].int_value();
		obj.width = item["width"].int_value();
		obj.height = item["height"].int_value();
		obj.loop = item["loop"].bool_value();
		obj.speed = item["speed"].int_value();
		obj.sheets = item["sheets"].int_value();
		for (auto &scope : item["scope"].array_items()) {
			obj.scopes.push_back(scope.string_value());
		}
		obj.set_default_to_empty();
		graph.push_back(obj);
	}
}
//デストラクタ
GraphicResource::~GraphicResource()
{
	graph.clear();
}
int GraphicResource::load(std::string _scope)
{
	//scopeの文字列の画像をjsonから検索し、読み込む
	//読み込んだ枚数を返す
	bool ret = 0;
	for (auto itr = graph.begin(); itr != graph.end(); ++itr) {
		if (itr->exist == false) {

		}
	}
	for (auto &item : json["graph"].array_items()) {
		//scopeの配列をitemに格納する
		for(auto &scope : item["scope"].array_items()) {
			//scopeの文字列を順に比較する
			if ( _scope == scope.string_value()) {
				if (exist_name(item["name"].string_value()) == false) {
					//同一の名前のファイルが読み込まれていない場合
					register_graph(item);	//graphにitemを登録する
					ret = true;
					break;
				}
			}
		}
	}
	return ret;
}

GraphicObject GraphicResource::get(std::string name)
{
	int index = get_index(name);
	GraphicObject ret;
	if (index != -1) ret = graph[index];
	return ret;
}

void GraphicResource::register_graph(json11::Json item)
{
	for (auto itr = graph.begin(); itr != graph.end(); ++itr) {
		if(itr->exist == false){
			itr->handle = new int(itr->sheets);	//アニメーション画像のフレーム枚数分のハンドル領域を確保する
			itr->exist = true;
			LoadDivGraph(
				itr->path.c_str(),
				itr->sheets,
				itr->column,
				itr->line,
				itr->width,
				itr->height,
				itr->handle
			);		//JSONに書かれた情報をLoadDivGraphから読み込む
			break;
		}
	}
}


bool GraphicResource::exist_name(std::string name)
{
	//nameが存在しているか調べるメソッド
	bool ret = false;
	for (auto itr = graph.begin(); itr != graph.end(); ++itr) {
		if (itr->name == name) {
			ret = true;
			break;
		}
	}
	return ret;
}
