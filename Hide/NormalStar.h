#pragma once
#include"Star.h"

//--------------------------------
//���ʂ̐�
//--------------------------------

class NormalStar : public Star {
public:

	void update();
	void inhale(int,int,float);

private:
	//SmallStar *smallstar;//���X�g�p?
};