﻿#include "StageSelectTaskMass.h"
#include"DxLib.h"

StageSelectTaskMass::StageSelectTaskMass()
{
	//153ずつ 153 -30  123
	// 30   183   336
	x = 30;
	y = 100;
	graph = LoadGraph("img/stageselect/mass.png");
}

void StageSelectTaskMass::update()
{
	draw();
}

void StageSelectTaskMass::draw()
{
	//4マス描画
	for (int i = 0; i < 4; ++i) {
		DrawGraph(153 * i + x , y, graph, TRUE);
	}
}

