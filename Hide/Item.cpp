#include "Item.h"
#include"CoreTask.h"

Item::Item(Point point_) : Rendering(point_)
{
}

void Item::update()
{
}

void Item::efficacy()
{
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
