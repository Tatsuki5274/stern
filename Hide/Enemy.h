﻿#pragma once
#include"BasicObject.h"
#include"Physic.h"

//----------------------------------
//敵全般
//----------------------------------

//Enemyに共通するためEnemyClassにいれてもいいかもしれない
enum class AngleState {
	left,
	right
};

struct EnemyState {
	int life;
	int damage;
	AngleState anglestate;
};

class Enemy :public BasicObject {
private:
	//プロパティ
	int life;
	int damaged;
	int gravity;


public :
	Enemy(Point point, PhysicState physic_state, EnemyState enemy_state);
	//メソッド
	virtual void update() final;
	virtual bool damage(int) final;

protected:
	//プロパティ
	int hp;//残り体力
	int power;
	int knock_back;
	AngleState anglestate;
	//メソッド
	virtual void move() = 0;	//抽象クラス
	virtual bool attack() final;

};