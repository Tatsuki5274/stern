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
	Point enemy_point;
	struct p {
		int x = 0, y = 0;
	}
	p[4];
	bool check_hit(Point);
};