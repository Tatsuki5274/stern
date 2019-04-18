#pragma once
#include"BasicObject.h"

//---------------------------------
//物理運動
//---------------------------------

struct PhysicState {
	float gravity;

};

class Physic : public BasicObject {
public:
	Physic(Point point,PhysicState physic_state);
	//メソッド
	int fall(Point);//物理運動を行うものだけ処理を行う
	int Check_X(Point, int);
	int Check_Y(Point, int);
protected:
	//変数
	float gravity;//重力
private:
	int velocity;


};
