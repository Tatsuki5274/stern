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
	int data[1][1];//���̐��l
	int graph;//�G
	int mapsizex;
	int mapsizey;
};