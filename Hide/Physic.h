#pragma once
#include"Rendering.h"

//---------------------------------
//�����^��
//---------------------------------

class Physic : public Rendering {
public:
	Physic() {
		gravity = 0;
		repulsion = 0;
		weight = 0;
	}
	//���\�b�h
	//float Gravity(float gra_);
	void exercise();//�����^�����s�����̂����������s��
protected:
	//�ϐ�
	float gravity;//�d��
	float repulsion;//�����W��
	int weight;//�d��(����)

};
