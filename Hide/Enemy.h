#pragma once
#include"Physic.h"

//----------------------------------
//�G�S��
//----------------------------------

class Enemy :public Physic {
public :
	//���\�b�h
	//�R���X�g���N�^
	Enemy(int life, int damage, int gravity);
	virtual void move();
	bool attack();
	void update();
	bool damage(int);

protected:
	//�ϐ�
	int hp;//�c��̗�
	int power;
	int knock_back;

	enum state {

	};

};