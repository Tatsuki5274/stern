#pragma once
#include"Physic.h"

//---------------------------------
//���S��
//---------------------------------

class Star : public Physic {
public:
	Star(int, int, int);
	//Star();//����𔲂���NormalStar�R���X�g���N�^�ŃG���[���N����
	//���\�b�h
	bool attack();
	bool damage(int);

protected:
	//�ϐ�
	int bright;//�P�x
	int radius;//���a(size)�i�~�Ŕ�����s�����߁j
	bool contact;
	int power;
	int life;
};