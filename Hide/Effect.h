#pragma once
#include"BasicObject.h"

class Effect : public BasicObject {
public:
	Effect(Point);
	//�ǉ����\�b�h������΋L�q
	void update();
private:
	double angle;
};