#include "Item.h"

Item::Item(Point point_,Kind kind_):Rendering(point_)
{
	kind = kind_;
	switch (kind_) {
	case Kind::powerup:
		init_render("item_powerup");
		break;
	case Kind::recovery:
		init_render("item_recovery");
		break;
	}
}

void Item::update(Point pl_,int& starpower,int& plhp)
{
	efficacy(pl_, starpower, plhp);
	draw(true);
}

void Item::efficacy(Point pl_,int& starpower,int& plhp)
{
	if (checkhit(pl_)) {
		switch (kind) {
		case Kind::powerup:
			//星の威力を上げる
			break;
		case Kind::recovery:
			//体力回復
			break;
		}
	}
}

bool Item::checkhit(Point pl)
{
	bool check = false;
	if(point.x < pl.x + pl.w ||//アイテムの左がプレイ屋の右より小さいなら
	   point.x + point.w > pl.x ||//アイテムの右がプレイ屋の左寄り大きいなら
	   point.y < pl.y + pl.h ||
	   point.y + point.h > pl.y){
		check = true;
	}
	return check;
}
