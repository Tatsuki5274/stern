﻿#include "CoreTask.h" //更新により削除予定
//
#include "Keyboard.h"
#include "StageSelectTaskSystem.h"
#include "model.h"
#include "Controller.h"

StageSelectTaskSystem::StageSelectTaskSystem()
{
	mass = std::make_unique<StageSelectTaskMass>();
	class Point point = { 30,100,30,30 };
	chara = std::make_unique<StageSelectChara>(point);
	txtbox = std::make_unique<StageSelectTextBox>();

	spawnenemy = std::make_unique<SpawnEnemy>("img/epath.json", mdl::enemys);
	spawnitem = std::make_unique<SpawnItem>("img/item.json", mdl::item);

	feedcnt = 0;
	deg_flag = false;
	stage = 1;
	for (int i = 0; i < sizeof(state); ++i) {
		state[i] = false;
	}
	backgraph = LoadGraph("img/stageselect/back.png");
}

void StageSelectTaskSystem::update()
{
	ScreenFunc::FeedIn(deg_flag, feedcnt);
	if (deg_flag) {
		if (ScreenFunc::FeedOut(deg_flag, feedcnt)) {
			switch (stage)
			{
			case 1:
				ctl::map->init((char*)"1");
				mdl::player->spawn(600, 30, 30, 30);
				mdl::goal->spawn(30, 510, 30, 30);
				spawnenemy->create("1");
				spawnitem->create("1");
				break;
			case 2:
				ctl::map->init((char*)"2");
				mdl::player->spawn(30, 1826, 30, 30);
				mdl::goal->spawn( 4416, 1796, 30, 60);
				spawnenemy->create("2");
				spawnitem->create("1");
				break;
			case 3:
				ctl::map->init((char*)"");
				break;
			case 4:
				ctl::map->init((char*)"");
				break;
			}
			ct->gts->init();
			ct->cts->init();
			ct->scene = Scene::game;//ゲームシーンに遷移
		}
	}
	if (Keyboard::key_down(KEY_INPUT_Z) && chara->get_velocity() == 0 && !deg_flag) {
		deg_flag = true;

	}
	draw();
	for (int i = 0; i < sizeof(mass); ++i) {
		mass->update();
	}
	chara->update(stage,deg_flag);
	txtbox->update(stage);
}

void StageSelectTaskSystem::draw()
{
	DrawGraph(0, 0, backgraph, FALSE);
}

int StageSelectTaskSystem::get_stage()
{
	return stage;
}

void StageSelectTaskSystem::clear(int num_)
{
	state[num_] = true;
}