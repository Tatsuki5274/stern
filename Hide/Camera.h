#pragma once
#include"DxLib.h"
#include"Point.h"

class Camera {
public:
	//Camera();
	void update();
	void move(int, int);
	//void change();
	bool get();
private:
	Point range;
	bool mode;//enum�ŗp�ӂ���\������
	int preX;//�ړ��O�̍��W
	int preY;
};