#include "Physic.h"
#include "CoreTask.h"
//----------------------------------
//�����^��
//----------------------------------


void Physic::exercise(Point Chara)
{
	//�d�͂ɂ�闎��
	velocityY += ((gravity / 60) / 60) * 32;  //32�̂Ƃ���͂P���[�g����32�s�N�Z��

	if (velocityX <= 0.5f && velocityY <= 0.5f) {
		repulsion = 0.0f;
	}
	if (ct->gts->map->get_bottom(Chara)) {
		rebound_Y();
	}
	if (ct->gts->map->get_left(Chara) || ct->gts->map->get_right(Chara)) {
		rebound_X();
	}
}

void Physic::rebound_X()
{
	velocityX *= -repulsion;
}

void Physic::rebound_Y()
{
	velocityY *= -repulsion;
}