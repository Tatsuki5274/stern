#pragma once
#include"Star.h"

//---------------------------------
//��R�̐��i���͂̂��鐯�j
//---------------------------------

class GravityStar :public Star {
public:
	GravityStar(Point point_, PhysicState physic_state_, StarState star_state);
	void update();
	void setposition(Point);
private:


protected:
};