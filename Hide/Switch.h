#pragma once
#include"BasicObject.h"
#include"Player.h"

class Switch :public BasicObject {
public:
	void act();
	void update();
protected:
	bool check_contact(Point);//�G�Ƃ̓����蔻��
private:
	//int id;
};

