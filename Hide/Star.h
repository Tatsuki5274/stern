#pragma once
#include"Physic.h"
#include"CoreTask.h"
//---------------------------------
//���S��
//---------------------------------

class Star : public Physic {
public:
	Star(int, int, int, int, double);
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
	Point Enemy_point;
	struct p {
		int x = 0, y = 0;
	}
	p[4];
};