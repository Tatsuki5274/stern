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
	virtual void exercise();//�����^�����s�����̂����������s��
	/*virtual void rebound_X();
	virtual void rebound_Y();*/
protected:
	//�ϐ�
	float gravity;//�d��
	float repulsion;//�����W��
	int weight;//�d��(����)


};
