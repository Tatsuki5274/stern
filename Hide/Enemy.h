#pragma once
#include"Physic.h"

//----------------------------------
//�G�S��
//----------------------------------

class Enemy :public Physic {
	//�����o�[�֐�
	int life;
	int damaged;
	int gravity;
public :
	//���\�b�h
	//�R���X�g���N�^
	Enemy();
	Enemy(int E_life, int E_damaged, int E_gravity);
	//���z�֐�
	virtual void move() {

	}
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