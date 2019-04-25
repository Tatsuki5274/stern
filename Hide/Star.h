#pragma once
#include"Physic.h"

//---------------------------------
//���S��
//---------------------------------

struct StarState {
	int bright;
	int radius;
	int power;
	int life;
	double angle;
};

class Star : public Physic {
public:
	Star(Point point_, PhysicState physic_state_, StarState star_state);
	//Star();//����𔲂���NormalStar�R���X�g���N�^�ŃG���[���N����
	//���\�b�h
	bool attack();
	bool damage(int);


protected:
	//�ϐ�
	double angle;
	int bright;//�P�x
	int radius;//���a(size)�i�~�Ŕ�����s�����߁j
	bool contact;
	int power;
	int life;

	//void exercise();
	bool check_hit(Point);
private:
	/*void rebound_X();
	void rebound_Y();*/
};