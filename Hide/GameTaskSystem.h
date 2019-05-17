#pragma once
#include "Player.h"
#include"Map.h"
#include<memory>
#include"NormalStar.h"
#include "Enemy.h"
#include "Item.h"
#include"Goal.h"
#include"Camera.h"
#include"RecoveryItem.h"
#include"GravityStar.h"

class GameTaskSystem
{
private:
	bool deg_flag;
	int feedcnt;

	void attack_star_enemy();
	void attack_player_enemy();
	void attack_player_item();


protected:
public:
	GameTaskSystem();
	~GameTaskSystem();
	void init();
	void update();
	void finalize();
	//~GameTaskSystem();

};

namespace mdl {
	extern std::shared_ptr<Player> player;
	extern std::unique_ptr<Goal> goal;
	//☆
	extern std::vector<NormalStar> normalstar;
	extern std::vector<GravityStar> gravityStar;
	//敵
	extern std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> enemys;
	extern std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> enemy_transaction;
	//アイテム
	extern std::shared_ptr<std::vector<std::shared_ptr<Item>>> item;
}

namespace ctl {
	extern std::unique_ptr<Map> map;
}