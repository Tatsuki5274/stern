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
		x = 0;
		y = 0;
		width;
		height;
	}

	//���\�b�h�i�֐��j
	virtual void update();
	void get_point();

protected:
	int x;
	int y;
	int width;
	int height;
	Point point;
	//�ړ���
	float velocityX;
	float velocityY;
};