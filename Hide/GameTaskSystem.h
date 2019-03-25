#pragma once
#include "Player.h"
#include"Map.h"
#include<memory>
#include"BasicList.h"
#include"NormalStar.h"
#include"Enemy.h"
#include"GravityStar.h"
class GameTaskSystem
{
private:
protected:
public:
	GameTaskSystem();
	~GameTaskSystem();
	void update();
	//~GameTaskSystem();
	std::unique_ptr<Player> player;
	std::unique_ptr<Map> map;
	std::shared_ptr<BasicList<NormalStar>> normalstar;
	std::shared_ptr<BasicList<GravityStar>> gravitystar;
	std::shared_ptr<BasicList<Enemy>> enemy;
};

