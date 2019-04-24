﻿#pragma once
#include"Point.h"
#include "json11.hpp"

//---------------------------------
//マップデータ
//---------------------------------

class Map {
public:
	Map();
	void init(char*, char*);
	void draw();
	void update();
	int get_left(Point);
	int get_right(Point);
	int get_top(Point);
	int get_bottom(Point);
	int get_circle(Point, int);
private:
	std::string chipmap;
	int data[20][20];//仮の数値
	int graph;//絵
	int mapsizex;
	int mapsizey;
	json11::Json mapdata;
	json11::Json map;
	json11::Json chipdata;
};