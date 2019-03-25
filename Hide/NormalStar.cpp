#include"NormalStar.h"
#include"DxLib.h"
#include<math.h>
#include"GameTaskSystem.h"

//--------------------------------
//普通の星
//--------------------------------

void NormalStar::update()
{
	DrawFormatString(300, 0, GetColor(255, 0, 0), "%d", power);
	//仮の移動
	point.x += (int)(-sin(angle) * velocityX);
	point.y += (int)(cos(angle) * velocityY);
	inhale();
	if (contact) {
		exercise();
	}
	draw();
}

void NormalStar::inhale()
{
	gravity_point=ct->gts->gravitystar->get()->point;
	velocityX += (gravity_point.x - point.x) * 5;//5はデバックしながら変えていく感じで
	velocityY += (gravity_point.x - point.x) * 5;
}

