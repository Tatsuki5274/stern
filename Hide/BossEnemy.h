#pragma once
#include"Enemy.h"

//--------------------------------
//�{�X�G
//--------------------------------

class Boss : public Enemy {
public:
	Boss(Point point_, PhysicState physic_state_, EnemyState enemy_state_);
	//���\�b�h
	void move();
	void update();

protected:
private:
};