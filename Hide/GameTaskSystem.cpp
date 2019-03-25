﻿#include "GameTaskSystem.h"


GameTaskSystem::GameTaskSystem()
{
	normalstar = std::make_shared<BasicList<NormalStar>>();
	gravitystar = std::make_shared<BasicList<GravityStar>>();
	map = std::make_unique<Map>();
	enemy = std::make_shared<Enemy>();
	player = std::make_unique<Player>();

}

GameTaskSystem::~GameTaskSystem()
{
}

void GameTaskSystem::update()
{
	//リストを先頭に戻す
	normalstar->lead();

	map->update();
	while (normalstar->exist()) {
		normalstar->get()->update();
		normalstar->proceed();
	}
	player->update();
}
