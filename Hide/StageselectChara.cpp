﻿#include"StageselectChara.h"
#include"CoreTask.h"
#include"Dxlib.h"
#include"System.h"
#include "Keyboard.h"

StageSelectChara::StageSelectChara(Point point_)
{
	graph = LoadGraph("img/stageselect/chara.png");
	velocityX = 0;
	point = point_;
}

void StageSelectChara::initialize(Point point_)
{
	velocityX = 0;
	point = point_;
}

void StageSelectChara::update(int& stage_, bool deg, int massline)
{
	select_stage(stage_, deg, massline);
	move();
	draw();
	//DrawFormatString(0, 50, GetColor(255, 0, 0), "x座標 : %d", point.x);
}

void StageSelectChara::draw()
{
	DrawGraph(point.x, point.y, graph, TRUE);
}

void StageSelectChara::select_stage(int& stage_, bool deg, int massline)
{
	if (!deg) {
		if (Keyboard::key_down(KEY_INPUT_RIGHT) && stage_ < 4 && velocityX == 0) {
			velocityX = massline;
			stage_++;
		}
		if (Keyboard::key_down(KEY_INPUT_LEFT) && stage_ > 1 && velocityX == 0) {
			velocityX = -massline;
			stage_--;
		}
		move();//次のマスに移ったら移動を停止したい
	}
}

void StageSelectChara::move()
{
	if (velocityX > 0) {
		point.x += 5;
		velocityX -= 5;
	}
	if (velocityX < 0) {
		point.x -= 5;
		velocityX += 5;
	}
}

int StageSelectChara::get_velocity()
{
	return (int)velocityX;
}
