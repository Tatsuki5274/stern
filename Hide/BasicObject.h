#pragma once
#include"Point.h"
//----------------------------------
//��{�ƂȂ�N���X
//----------------------------------

class BasicObject {
public:
	//�Œ���̏�����
	BasicObject() {
		velocityX = 0;
		velocityY = 0;
	}

	//���\�b�h�i�֐��j
	virtual void update();
	void get_point();

protected:
	Point point;
	//�ړ���
	float velocityX;
	float velocityY;
};