#pragma once
#include"Physical.h"

//----------------------------------
//�G�S��
//----------------------------------

class Enemy :public Physical {
public :
	Enemy():
		life(0)
	{}
	//���\�b�h
	void Move();
private:
	//�ϐ�
	int life;
};