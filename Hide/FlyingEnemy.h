#pragma once
#include"Enemy.h"

//---------------------------------
//�G���G(��s)
//---------------------------------

class FlyingEnemy : public Enemy{
	
	
	//NormalEnemy* list;//���X�g�\���̂��߈ꉞ�L�q
	//���\�b�h
	enum class FlyingState
	{
		fly,
		stay,
	};
	FlyingState flyingstate;
	void move();
	void update();
private:
protected:
};