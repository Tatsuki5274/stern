#include "Door.h"


void Door::act()
{
	this->check_contact(point);

	//�h�A���J�������
	if (true) {
		shape->set("door02");
	}
	//�h�A���������
	else{ shape->set("door01"); }

}
void Door::update()
{
	this->act();
}
bool Door::check_contact(Point a_)
{
	//���Ƃ̓����蔻��
	if (a_.x < point.x + point.w &&
		a_.x + a_.w > point.x &&
		a_.y < point.y + point.h &&
		a_.y + a_.h > point.y) {
		return true;
	}
	else { return false; }
}
