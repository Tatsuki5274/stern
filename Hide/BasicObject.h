#pragma once

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
		height = 0;
		width = 0;
	}

	//���\�b�h�i�֐��j
	virtual void update();
	void get_point();

protected:
	//���W
	int x;
	int y;
	//���E����
	int height;
	int width;
	//�ړ���
	float velocityX;
	float velocityY;
};