#pragma once
#include"Rendering.h"

//---------------------------------
//�����^��
//---------------------------------

class Physic : public Rendering {
public:
	Physic() {

		gravity = 0.5f;
		repulsion = 0;
		weight = 0;
	}
	//���\�b�h
	void exercise();//�����^�����s�����̂����������s��
protected:
	//�ϐ�

	float gravity;//�d��
	float repulsion;//�����W��
	int weight;//�d��(����)

	void rebound_X();
	void rebound_Y();
};
