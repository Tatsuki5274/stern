#pragma once
#include"Animater.h"

//---------------------------------
//�����^��
//---------------------------------

class Physical : public Animater {
public:
	Physical() {
		gravity = 0;
		repulsion = 0;
		weight = 0;
	}
	//���\�b�h
	//float Gravity(float gra_);
	void exercise(bool judge);//�����^�����s�����̂����������s��
protected:
	//�ϐ�
	float gravity;//�d��
	float repulsion;//�����W��
	int weight;//�d��(����)

};
