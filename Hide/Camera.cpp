#include "Camera.h"
#include "CoreTask.h"


void Camera::update()
{
	//�v���C�����S�Ƃ���X,Y���W����葱����
	range.x = ct->gts->player->get_point().x;
	range.y = ct->gts->player->get_point().y;
	
}

void Camera::move(int, int)
{
}

bool Camera::get()
{
	return false;
}
