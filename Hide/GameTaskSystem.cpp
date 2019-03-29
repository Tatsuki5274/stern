#include "GameTaskSystem.h"
#include"CoreTask.h"

GameTaskSystem::GameTaskSystem()
{
	//Point point_, PhysicState physic_state_, PlayerState player_state
	class Point p_point = {100,300,30,30};
	struct PhysicState p_physic_state = { 1,0,0 };//gra,rep,wei
	struct PlayerState player_state = { 3,2 };//life,hp

	class Point g_point = { 0,510,30,60 };

	map = std::make_unique<Map>();
	goal = std::make_unique<Goal>(g_point);
	player = std::make_unique<Player>(p_point,p_physic_state,player_state);

	normalstar = std::make_shared<BasicList<NormalStar>>();
	walking_enemy = std::make_shared<BasicList<WalkingEnemy>>();
	boss = std::make_shared<BasicList<Boss>>();
	flying_enemy = std::make_shared<BasicList<FlyingEnemy>>();
	throwing_enemy = std::make_shared<BasicList<ThrowingEnemy>>();
}

GameTaskSystem::~GameTaskSystem()
{
}

void GameTaskSystem::init()
{
	class Point p_point = { 100,300,30,30 };
	player->initialize(p_point);
}

void GameTaskSystem::update()
{
	//リストを先頭に戻す
	normalstar->lead();
	walking_enemy->lead();

	map->update();
	//☆------------------------------
	while (normalstar->exist()) {
		normalstar->get()->update();
		normalstar->proceed();
	}
	//--------------------------------
	//敵------------------------------
	while (walking_enemy->exist()) {
		walking_enemy->get()->update();
		walking_enemy->proceed();
	}
	//--------------------------------

	goal->update();
	player->update();

}
