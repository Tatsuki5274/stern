#pragma once
#include"Physic.h"

//---------------------------------
//���S��
//---------------------------------

class Star : public Physic {
public:
	Star(int, int, int);
	//���\�b�h
	bool attack();
	bool damage(int);

private:
	//�ϐ�
	int bright;//�P�x
	int radius;//���a(size)�i�~�Ŕ�����s�����߁j
	bool contact;
	int power;
	int life;
};