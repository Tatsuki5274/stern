#pragma once
#include"Star.h"
#include"DxLib.h"

//--------------------------------
//���ʂ̐�
//--------------------------------

class NormalStar : public Star {
	friend class GravityStar;
public:
	NormalStar(Point point_, PhysicState physic_state_, StarState star_state);
	void update();
	void inhale();

private:

};