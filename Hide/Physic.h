#pragma once
#include"Rendering.h"
#include "Point.h"

//---------------------------------
//�����^��
//---------------------------------

class Physic : public Rendering {
public:
	Physic() {
		gravity = 9.8f;	//���̐��l
		repulsion = 0;
		weight = 0;
	}
	//���\�b�h
	//float Gravity(float gra_);
	void exercise(Point Chara);//�����^�����s�����̂����������s��
	void rebound_X();	//X�ɑ΂��锽���W��
	void rebound_Y();	//Y�ɑ΂��锽���W��
protected:
	//�ϐ�
	float gravity;//�d��
	float repulsion;//�����W��
	int weight;//�d��(����)

};
