#pragma once

class Point {
public:
	//���W�ƕ��ƍ���
	int x;
	int y;
	int w;
	int h;
	bool operator!=(Point& a) {
		return &a != this;
	}
};