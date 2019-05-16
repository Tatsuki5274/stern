﻿#include"NormalStar.h"
#include"DxLib.h"
#include"CoreTask.h"

//--------------------------------
//
//--------------------------------

NormalStar::NormalStar(Point point_, PhysicState physic_state_, StarState star_state) : Star(point_, physic_state_, star_state)
{
	point = point_;
	shape->set("star");
}

void NormalStar::update()
{
	Point sizeup{ point.x - 1,point.y - 1,point.w + 2,point.h + 2 };
	DrawFormatString(300, 0, GetColor(255, 0, 0), "%d", point);
	if (!contact) {
		point.x += physicshape->Movement_X(point, (int)(-sin(angle) * 20));
		point.y += physicshape->Movement_Y(point, (int)(cos(angle) * 20));
		if (ct->gts->map->get_bottom(sizeup) ||
			ct->gts->map->get_left(sizeup) ||
			ct->gts->map->get_right(sizeup) ||
			ct->gts->map->get_top(sizeup)) {
			contact = true;
		}
	}
	else {
		if (gravitypoint != Point{ NULL,NULL,NULL,NULL }) {
			inhale();
		}
	}
	attack();
	shape->draw(point);
}

void NormalStar::inhale()
{
	Point gravitypoint = {0,0,0,0};
	for (auto itr = ct->gts->gravityStar.begin(); itr != ct->gts->gravityStar.end(); ++itr) {
		gravitypoint = itr->gravitypoint;
	}
	//問題の地点　pointに赤線がひかれる
	point.x += physicshape->Movement_X(point,(gravitypoint.x - point.x) / 10);///100は近づかせるのを減衰させるため
	point.y += physicshape->Movement_Y(point,(gravitypoint.y - point.y)/10);
}
