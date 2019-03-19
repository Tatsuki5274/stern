#pragma once
#include"Point.h"

//----------------------------------
//基本となるクラス
//----------------------------------

class BasicObject {
public:
	//最低限の初期化
	BasicObject() {
		velocityX = 0;
		velocityY = 0;
	}

	//メソッド（関数）
	virtual void update();
	Point get_point();

protected:
	//座標
	Point point;
	//移動量
	float velocityX;
	float velocityY;
};