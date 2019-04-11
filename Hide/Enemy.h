#pragma once
#include"Physic.h"

//----------------------------------
//�G�S��
//----------------------------------

//Enemy�ɋ��ʂ��邽��EnemyClass�ɂ���Ă�������������Ȃ�
enum class AngleState {
	left,
	right
};

struct EnemyState {
	int life;
	int damage;
	AngleState anglestate;
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
	virtual bool attack();
	virtual void update();
	virtual bool damage(int);

protected:
	//�ϐ�
	int hp;//�c��̗�
	int power;
	int knock_back;
	AngleState anglestate;

};