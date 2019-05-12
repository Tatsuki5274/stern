#pragma once
#include"Star.h"
#include"DxLib.h"

//--------------------------------
//���ʂ̐�
//--------------------------------

class NormalStar : public Star {
public:
	NormalStar(Point point_, PhysicState physic_state_, StarState star_state);
	void update();
	void inhale();

private:
	Point gravity_point;
};