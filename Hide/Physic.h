#pragma once
#include"Rendering.h"

//---------------------------------
//�����^��
//---------------------------------

struct PhysicState {
	float gravity;
	float repulsion;
	int weight;
};

class Physic : public Rendering {
public:
	Physic(Point point,PhysicState physic_state);
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
