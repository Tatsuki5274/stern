#pragma once
#include"Physic.h"

//----------------------------------
//�G�S��
//----------------------------------

class Enemy :public Physic {
public :
	//���\�b�h
	Enemy();
	Enemy *Enmyupdate;
	
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