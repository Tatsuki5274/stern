#include "Switch.h"
void Switch::act()
{
	this->check_contact(point);

	//�X�C�b�`�������ꂽ���
	if (true) {
		shape->set("switch02");
	}
	//�X�C�b�`��������Ă��Ȃ����
	else { shape->set("switch01"); }
	
}
void Switch::update()
{
	this->act();
}
bool Switch::check_contact(Point e_)
{
	//�G�Ƃ̓����蔻��
	if (e_.x < point.x + point.w &&
		e_.x + e_.w > point.x &&
		e_.y < point.y + point.h &&
		e_.y + e_.h > point.y)
	{
		return true;
	}
	else{ return false; }
}