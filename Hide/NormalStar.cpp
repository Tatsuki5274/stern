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
	x += (int)(-sin(angle) * velocityX);
	y += (int)(cos(angle) * velocityY);

	draw();
}

void NormalStar::inhale(int, int, float)
{
}

