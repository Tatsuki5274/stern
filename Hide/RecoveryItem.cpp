#include "RecoveryItem.h"
#include"CoreTask.h"

RecoveryItem::RecoveryItem(Point point_) : Item(point_)
{
	init_render("recovery");//�摜
}

void RecoveryItem::update()
{
	if (checkhit(ct->gts->player->get_point())) {
		efficacy();
	}
	draw(true);
}

void RecoveryItem::efficacy()
{
	//��
}
