#pragma once
#include"Enemy.h"

//---------------------------------
//�G���G(��s)
//---------------------------------

class FlyingEnemy : public Enemy{
	enum class FlyingState
	{
		fly,
		stay,
	};
	FlyingState flyingstate;
public:
	//NormalEnemy* list;//���X�g�\���̂��߈ꉞ�L�q
	//���\�b�h
	void move();
	void update();
protected:

};