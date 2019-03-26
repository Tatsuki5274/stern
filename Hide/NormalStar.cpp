#include"NormalStar.h"
#include"DxLib.h"
#include<math.h>
#include"GameTaskSystem.h"

//--------------------------------
//���ʂ̐�
//--------------------------------

NormalStar::NormalStar(Point point_, PhysicState physic_state_, StarState star_state) : Star(point_,physic_state_,star_state)
{

}

void NormalStar::update()
{
	DrawFormatString(300, 0, GetColor(255, 0, 0), "%d", power);
	//���̈ړ�
	point.x += (int)(-sin(angle) * velocityX);
	point.y += (int)(cos(angle) * velocityY);

	draw();
}

void NormalStar::inhale(int, int, float)
{
}

