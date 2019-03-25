#pragma once
#include"Physic.h"
#include"CoreTask.h"
//---------------------------------
//星全般
//---------------------------------

class Star : public Physic {
public:
	Star(int, int, int, int, double);
	//Star();//これを抜くとNormalStarコンストラクタでエラーが起こる
	//メソッド
	bool attack();
	bool damage(int);

protected:
	//変数
	double angle;
	int bright;//輝度
	int radius;//半径(size)（円で判定を行うため）
	bool contact;
	int power;
	int life;
	Point Enemy_point;
	struct p {
		int x = 0, y = 0;
	}
	p[4];
};