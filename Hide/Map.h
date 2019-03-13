#pragma once
#include"Point.h"

//---------------------------------
//�}�b�v�f�[�^
//---------------------------------

class Map {
public:
	
	Map(char*);
	void draw();
	void update();
	int get_left(Point);
	int get_right(Point);
	int get_top(Point);
	int get_bottom(Point);

private:
	int data[20][20];//���̐��l
	int graph;//�G
	int mapsizex;
	int mapsizey;
	int chipsize;//�`�b�v�̑傫��
};