#include"Star.h"

//---------------------------------
//���S��
//---------------------------------

Star::Star(int power_, int life_, int weight_,int x_,double angle_)
{
	x = x_;
	angle = angle_;
	power = power_;
	weight = weight_;
	life = life_;
	contact = false;
	bright = 0;//���̂Ƃ���
}

bool Star::attack()
{
	//�~�Ƌ�`�̓����蔻��
	return false;
}

bool Star::damage(int damage_)
{
	life -= damage_;
	if (life <= 0) {
		return true;
	}
	return false;
}


