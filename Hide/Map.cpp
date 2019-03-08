#include"Map.h"
#include"DxLib.h"
#include<fstream>

//----------------------------------
//�}�b�v�f�[�^
//----------------------------------

Map::Map(char *mapfp)
{
	//1�Ẫ`�b�v�̑傫����30�ƍl����(����)
	mapsizex = 600;
	mapsizey = 600;
	//�g���摜����
	graph = LoadGraph("img/chip.png");
	//�t�@�C���ǂݍ���
	std::ifstream mapdata(mapfp);
	if (!mapdata) { return; }
	for (int y = 0; y < mapsizey / 30; ++y) {
		for (int x = 0; x < mapsizex / 30; ++x) {
			mapdata >> data[y][x];
		}
	}
	//�t�@�C����
	mapdata.close();
}

void Map::draw()
{
	for (int y = 0; y < mapsizey / 20; ++y) {
		for (int x = 0; x < mapsizex / 20; ++x) {
			DrawRectGraph(x * 30, y * 30, data[y][x] * 30, 0, 30, 30, graph, FALSE);
		}
	}
}

void Map::update()
{
	draw();
}

int Map::get_left(Point)
{
	return 0;
}

int Map::get_right(Point)
{
	return 0;
}

int Map::get_top(Point)
{
	return 0;
}

int Map::get_bottom(Point)
{
	return 0;
}
