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
	Point get_point();

protected:
	//���W
	Point point;
	//�ړ���
	float velocityX;
	float velocityY;
};