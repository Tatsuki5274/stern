#pragma once
#include"Physic.h"

//----------------------------------
//�G�S��
//----------------------------------

struct EnemyState {
	int life;
	int damage;
};

class Enemy :public Physic {
	//�����o�[�֐�
	int life;
	int damaged;
	int gravity;
public :
	//���\�b�h
	//�R���X�g���N�^
	Enemy(Point point, PhysicState physic_state,EnemyState enemy_state);
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