#pragma once
#include"Enemy.h"

//---------------------------------
//�G���G(��s)
//---------------------------------

class FlyingEnemy : public Enemy{
	enum FlyingState
	{
		fly,
		stay,
	};
public:
	//NormalEnemy* list;//���X�g�\���̂��߈ꉞ�L�q
	//���\�b�h
	void move();
	void update();
protected:

};