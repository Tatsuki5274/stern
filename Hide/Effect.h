#pragma once
#include"Rendering.h"

class Effect : public Rendering {
public:
	Effect() {
		angle = 0;
	}
	//�ǉ����\�b�h������΋L�q
	void update();
private:
	double angle;
};