#pragma once

//----------------------------------
//��{�ƂȂ�N���X
//----------------------------------

class BasicObject {
public:
	//�Œ���̏�����
	BasicObject() {
		velocity = 0;
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
	float velocity;
};