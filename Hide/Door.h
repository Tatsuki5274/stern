#pragma once
#include"BasicObject.h"
#include"Player.h"

class Door :public BasicObject {
public:
	void act();
	void update();
protected:
	bool check_contact(Point);//���Ƃ̓����蔻��
private:
	//int id;
	bool status;//���
};