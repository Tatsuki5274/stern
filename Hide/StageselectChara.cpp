#include"StageselectChara.h"
#include"CoreTask.h"
#include"Dxlib.h"
#include"System.h"

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

void StageSelectChara::update(int& stage_, bool deg,int* massX)
{
	select_stage(stage_, deg,massX);
	move();
	draw();
	//DrawFormatString(0, 50, GetColor(255, 0, 0), "x座標 : %d", point.x);
}

void StageSelectChara::draw()
{
	DrawGraph(point.x, point.y, graph, TRUE);
}

void StageSelectChara::select_stage(int& stage_, bool deg,int* massX)
{
	if (!deg) {
		if (Keyboard::key_down(KEY_INPUT_RIGHT) && stage_ < 4 && velocityX == 0) {
			velocityX = 1;
			stage_++;
		}
		if (Keyboard::key_down(KEY_INPUT_LEFT) && stage_ > 1 && velocityX == 0) {
			velocityX = -1;
			stage_--;
		}
		if (massX[stage_ - 1] > point.x) {//次のマスと１つ前のマス
			move();//次のマスに移ったら移動を停止したい
		}
		else {
			velocityX = 0;
		}
	}
}

void StageSelectChara::move()
{
	point.x += (int)velocityX;
}

int StageSelectChara::get_velocity()
{
	return (int)velocityX;
}
