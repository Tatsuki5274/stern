#pragma once
#include"Rendering.h"

class Effect : public Rendering {
public:
	Effect(Point);
	//�ǉ����\�b�h������΋L�q
	void update();
private:
	double angle;
};