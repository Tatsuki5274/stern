#pragma once
#include"Physic.h"

//----------------------------------
//�G�S��
//----------------------------------

class Enemy :public Physic {
public :
	//���\�b�h
	Enemy(int, int, int) {

	}
	virtual void move();
	bool attack();
	void update();
	void damage(int);
protected:
	//�ϐ�
	int hp;//�c��̗�
	int power;
	int knock_back;

	enum state {

	};

};