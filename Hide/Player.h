#pragma once
#include"Physical.h"

//---------------------------------
//�v���C���[
//---------------------------------

class Player :public Physical {
public:
	Player():
		life(0)
	{}
	//���\�b�h
	bool Damage(void);//�_���[�W���󂯂鏈��
private:
	//�ϐ�
	int life;//�̗�(HP)
};