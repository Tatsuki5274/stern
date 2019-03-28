#include"Map.h"
#include"DxLib.h"
#include<fstream>
#include<sstream>
//1�Ẫ`�b�v�̑傫����30�ƍl����(����)//�`�b�v�T�C�Y��32���Ó�
#define chipsize 30

//----------------------------------
//�}�b�v�f�[�^
//----------------------------------

Map::Map()
{
	//��
	mapsizex = 600;
	mapsizey = 600;
}

void Map::init(char* mapfp, char* chipfp)
{
	//�g���摜����
	graph = LoadGraph(chipfp);
	//�t�@�C���ǂݍ���
	std::ifstream mapdata(mapfp);
	if (!mapdata) { return; }
	for (int y = 0; y < mapsizey / chipsize; ++y) {
		std::string lineText;
		std::getline(mapdata, lineText);
		std::istringstream  ss_lt(lineText);
		for (int x = 0; x < mapsizex / chipsize; ++x) {
			std::string  tc;
			std::getline(ss_lt, tc, ',');
			std::stringstream ss;
			ss << tc;
			ss >> data[y][x];
			mapdata >> data[y][x];
		}
	}
	//�t�@�C����
	mapdata.close();
}

void Map::draw()
{
	for (int y = 0; y < mapsizey / (mapsizey/chipsize); ++y) {
		for (int x = 0; x < mapsizex / (mapsizex / chipsize); ++x) {
			DrawRectGraph(x * chipsize, y *chipsize, data[y][x] * chipsize, 0, chipsize, chipsize, graph, FALSE);
		}
	}
}

void Map::update()
{
	draw();
}
//-----------------------------------------------------------------------------------------------------------
//���_�@chara����̃}�b�v�`�b�v���܂����ł���Ƃ����i�܂��͏�)�̃`�b�v�̂݃��^�[������A�ق��̃`�b�v�����������
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
	//�}�b�v�^�C���P��30*30�̂���
	int sx = chara_.x / chipsize;
	int sy = (chara_.y + chara_.h) / chipsize;
	int ex = (chara_.x + chara_.w) / chipsize;
	int ey = ((chara_.y + chara_.h)+1) / chipsize;
	//�͈͓��̏�Q����T��
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; sx <= ex; ++x) {
			return data[y][x];
		}
	}
	return 0;
}*/
//-----------------------------------------------------------------------------------------------------------
//�������@�`�b�v�������蔻��������Ă���Ƃ��̂�1��Ԃ��@����_���[�W����2��Ԃ��Ȃǂ̊g�����\
//-----------------------------------------------------------------------------------------------------------
int Map::get_left(Point chara_)
{
	int sx = chara_.x / chipsize;
	int sy = chara_.y / chipsize;
	int ex = chara_.x / chipsize;
	int ey = (chara_.y + chara_.h-1) / chipsize;
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			if (data[y][x] == 1) {//����̏ꍇ�͂P�̃`�b�v�݂̂ɓ����蔻�����������
				return 1;
			}
			
		}
	}
	return 0;
}

int Map::get_right(Point chara_)
{
	int sx = (chara_.x + chara_.w) / chipsize;
	int sy = chara_.y / chipsize;
	int ex = (chara_.x + chara_.w) / chipsize;
	int ey = (chara_.y + chara_.h-1) / chipsize;
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			if (data[y][x] == 1) {//����̏ꍇ�͂P�̃`�b�v�݂̂ɓ����蔻�����������
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
			if (data[y][x] == 1) {//����̏ꍇ�͂P�̃`�b�v�݂̂ɓ����蔻�����������
				return 1;
			}

		}
	}
	return 0;
}

int Map::get_bottom(Point chara_)
{
	int sx = chara_.x / chipsize;
	int sy = (chara_.y + chara_.h) / chipsize;
	int ex = (chara_.x + chara_.w-1) / chipsize;
	int ey = (chara_.y + chara_.h) / chipsize;
	//�͈͓��̏�Q����T��
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			if (data[y][x] == 1) {//����̏ꍇ�͂P�̃`�b�v�݂̂ɓ����蔻�����������
				return 1;
			}

		}
	}
	return 0;
}
