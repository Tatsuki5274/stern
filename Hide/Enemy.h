#pragma once
#include"Physical.h"

//----------------------------------
//�G�S��
//----------------------------------

class Enemy :public Physical {
public :
	Enemy() {
		hp = 0;
		damage = 0;
	}
	//���\�b�h
	virtual void Move();
	bool Attack();
protected:
	//�ϐ�
	int hp;//�c��̗�
	int damage;
};