﻿#include"StageselectChara.h"
#include"CoreTask.h"
#include"Dxlib.h"
//
#include "Keyboard.h"

StageSelectChara::StageSelectChara(Point point_)
{
	graph = LoadGraph("img/stageselect/chara.png");
	velocityX = 0;
	point = point_;
}

void StageSelectChara::update(int& stage_,bool deg)
{
	select_stage(stage_,deg);
	move();
	draw();
	DrawFormatString(0, 50, GetColor(255, 0, 0), "x座標 : %d", point.x);
}

void StageSelectChara::draw()
{
	DrawGraph(point.x, point.y, graph, TRUE);
}

void StageSelectChara::select_stage(int& stage_,bool deg)
{
	if (!deg) {
		if (Keyboard::key_down(KEY_INPUT_RIGHT) && stage_ < 4 && velocityX == 0) {
			velocityX = 18;
			stage_++;//ステージセレクトタスクの方のステージ番号は加算されていない
		}
		if (Keyboard::key_down(KEY_INPUT_LEFT) && stage_ > 1 && velocityX == 0) {
			velocityX = -18;
			stage_--;
		}
	}
	if(velocityX > 0) velocityX--;
	if(velocityX < 0) velocityX++;
}

void StageSelectChara::move()
{
	point.x += (int)velocityX;
}

int StageSelectChara::get_velocity()
{
	return (int)velocityX;
}
