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
			//���̈З͂��グ��
			break;
		case Kind::recovery:
			//�̗͉�
			break;
		}
	}
}

bool Item::checkhit(Point pl)
{
	bool check = false;
	if(point.x < pl.x + pl.w ||//�A�C�e���̍����v���C���̉E��菬�����Ȃ�
	   point.x + point.w > pl.x ||//�A�C�e���̉E���v���C���̍����傫���Ȃ�
	   point.y < pl.y + pl.h ||
	   point.y + point.h > pl.y){
		check = true;
	}
	return check;
}
