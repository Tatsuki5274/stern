#include"NormalStar.h"
#include"DxLib.h"
#include<math.h>
#include"GameTaskSystem.h"

//--------------------------------
//���ʂ̐�
//--------------------------------

void NormalStar::update()
{
	DrawFormatString(300, 0, GetColor(255, 0, 0), "%d", power);
	//���̈ړ�
	y += (int)(sin(gts->player->get_angle()) * velocityY);
	x += (int)(cos(gts->player->get_angle()) * velocityX);

	draw();
}

void NormalStar::inhale(int, int, float)
{
}

