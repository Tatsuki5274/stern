#pragma once
#include"Enemy.h"

//---------------------------------
//�G���G(��s)
//---------------------------------

class FlyingEnemy : public Enemy{
public:
	FlyingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_);
	//NormalEnemy* list;//���X�g�\���̂��߈ꉞ�L�q
	//���\�b�h
	void move();
	void update();
protected:

};