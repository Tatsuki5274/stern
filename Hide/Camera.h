#pragma once
#include"DxLib.h"

class Camera {
public:
	//Camera();
	void update();
	void move(int, int);
	void change();
	bool get();
private:
	RECT range;
	bool mode;//enum�ŗp�ӂ���\������
	int prex;//�ړ��O�̍��W
	int prey;
};