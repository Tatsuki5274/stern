#pragma once
#include"Animater.h"

class Effect : public Animater {
public:
	Effect() {
		angle = 0;
	}
	//�ǉ����\�b�h������΋L�q
private:
	double angle;
};