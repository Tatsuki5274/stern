#include "Physic.h"
#include "CoreTask.h"
//----------------------------------
//�����^��
//----------------------------------


void Physic::exercise()
{
	//�d�͂ɂ�闎��
	velocityY += gravity;  

	if (velocityX <= 0.5f && velocityY <= 0.5f) {
		repulsion = 0.0f;
	}
	if (ct->gts->map->get_bottom(point)==1) {//����1�̕����̓}�b�v�ύX���ɗv�ύX
		rebound_Y();
	}
	if (ct->gts->map->get_left(point)==1 || ct->gts->map->get_right(point)==1) {
		rebound_X();
	}
	point.x += (int)velocityX;
	point.y += (int)velocityY;
}

void Physic::rebound_X()
{
	velocityX *= -repulsion;
}

void Physic::rebound_Y()
{
	velocityY *= -repulsion;
}