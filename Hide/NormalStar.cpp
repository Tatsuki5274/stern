#include"NormalStar.h"
#include"DxLib.h"

//--------------------------------
//���ʂ̐�
//--------------------------------

void NormalStar::update()
{
	DrawFormatString(300, 0, GetColor(255, 0, 0), "%d", power);
	//���̈ړ�
	y += (int)velocity;
	x += (int)velocity;

	draw();
}

void NormalStar::inhale(int, int, float)
{
}

