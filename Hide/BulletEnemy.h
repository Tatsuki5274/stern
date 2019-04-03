#pragma once
#include"Enemy.h"

class BulletEnemy : public Enemy {
public:
	BulletEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_);
	void move();
	void update();
private:
	int angle;
protected:
};