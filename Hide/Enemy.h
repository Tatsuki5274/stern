#pragma once
#include"Physic.h"

//----------------------------------
//�G�S��
//----------------------------------

class Enemy :public Physic {
public :
	int life;
	int damaged;
	int gravity;
	//���\�b�h
	//�R���X�g���N�^
	Enemy();
<<<<<<< HEAD
	Enemy(int E_life, int E_damaged, int E_gravity);
=======
	Enemy(int E_life, int E_damage, int E_gravity);
>>>>>>> Enemyclass
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