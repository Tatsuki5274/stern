#include "StageSelectTaskMass.h"
#include"DxLib.h"
#include"System.h"

StageSelectTaskMass::StageSelectTaskMass()
{
	mass = 4;
	x = System::width / 4;//画像を描画する始点(4マスの中の一番左のマスの左座標)
	y = 100;
	graph = LoadGraph("img/stageselect/mass.png");
	for (int i = mass; i > 0; i--) {
		mass_x[i] = System::width - i * x + mass * 32;
	}
}

void StageSelectTaskMass::update()
{
	draw();
}

void StageSelectTaskMass::draw()
{
	//4マス描画
	for (int i = mass;i > 0;i--) {
		//32は適当な数値
		DrawGraph(System::width - i * x + mass * 32, y, graph, TRUE);
	}
}

int StageSelectTaskMass::get_massX(int mass_num)
{
	return mass_x[mass_num];
}


