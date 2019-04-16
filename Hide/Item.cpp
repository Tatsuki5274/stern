#include "Item.h"
#include"CoreTask.h"

std::shared_ptr<Player> player;

Item::Item(Point point_) : BasicObject(point_)
{
}

void Item::update()
{
	if (checkhit(ct->gts->player->get_point())) {
		work();
	}
	shape->draw(point);
}

bool Item::checkhit(Point pl)
{
	bool check = false;
	if (point.x < pl.x + pl.w ||
		point.x + point.w > pl.x ||
		point.y < pl.y + pl.h ||
		point.y + point.h > pl.y) {
		check = true;
	}
	return check;
}
