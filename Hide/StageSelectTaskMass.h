﻿#pragma once

class StageSelectTaskMass {
private:
	int x;
	int y;//表示する高さ
	int mass;
	int mass_x[4];
	//画像
	int graph;
public:
	StageSelectTaskMass();
	void update();
	void draw();
	int* get_masspos();
	int get_massX(int);
	int get_massY();
	int get_massline();
};