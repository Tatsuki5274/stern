#pragma once
#include"Physical.h"

//---------------------------------
//���S��
//---------------------------------

class Star : public Physical {
public:
	Star():
		bright(0),
		radius(0)
	{}
	//���\�b�h
private:
	//�ϐ�
	int bright;//�P�x
	float radius;//���a�i�~�Ŕ�����s�����߁j
};