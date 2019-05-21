﻿#include "StageSelectTaskSystem.h"
#include"Screen_helper.h"
#include"CoreTask.h"
#include"System.h"

//静的定義----------------------------------------------------------------
int StageSelectTaskSystem::stage;//ステージ識別番号
bool StageSelectTaskSystem::state[4];//クリアフラグ（ステージ総数によって変える）

bool StageSelectTaskSystem::deg_flag;
int StageSelectTaskSystem::feedcnt;
int StageSelectTaskSystem::backgraph;//背景画像
std::unique_ptr<StageSelectTaskMass> StageSelectTaskSystem::mass;
std::unique_ptr<StageSelectChara> StageSelectTaskSystem::chara;
std::unique_ptr<StageSelectTextBox> StageSelectTaskSystem::txtbox;

std::unique_ptr<SpawnEnemy> StageSelectTaskSystem::spawnenemy;//敵の生成
std::unique_ptr<SpawnItem> StageSelectTaskSystem::spawnitem;

//------------------------------------------------------------------------

StageSelectTaskSystem::StageSelectTaskSystem()
{
	mass = std::make_unique<StageSelectTaskMass>();
	class Point point = { mass->get_massX(0),200,30,30 };
	chara = std::make_unique<StageSelectChara>(point);
	txtbox = std::make_unique<StageSelectTextBox>();

	spawnenemy = std::make_unique<SpawnEnemy>("img/epath.json", ct->gts->enemys);
	spawnitem = std::make_unique<SpawnItem>("img/item.json", ct->gts->item);

	feedcnt = 0;
	deg_flag = false;
	stage = 1;
	for (int i = 0; i < sizeof(state); ++i) {
		state[i] = false;
	}
	backgraph = LoadGraph("img/stageselect/back.png");
}

void StageSelectTaskSystem::initialize()
{
	class Point point = { mass->get_massX(0),200,30,30 };
	chara->initialize(point);
	feedcnt = 0;
	deg_flag = false;
	//stage = 1;
}

void StageSelectTaskSystem::update()
{
	ScreenFunc::FeedIn(deg_flag, feedcnt);
	if (deg_flag) {
		if (ScreenFunc::FeedOut(deg_flag, feedcnt)) {
			switch (stage)
			{
			case 1:
				ct->gts->map->init((char*)"1");
				ct->gts->player->spawn(600, 30, 30, 30);
				ct->gts->goal->spawn(30, 510, 30, 30);
				spawnenemy->create("1");
				spawnitem->create("1");
				break;
			case 2:
				ct->gts->map->init((char*)"2");
				ct->gts->player->spawn(30, 1826, 30, 30);
				ct->gts->goal->spawn( 4416, 1796, 30, 60);
				spawnenemy->create("2");
				spawnitem->create("2");
				break;
			case 3:
				ct->gts->map->init((char*)"");
				break;
			case 4:
				ct->gts->map->init((char*)"");
				break;
			}
			ct->gts->init();
			ct->cts->init();
			ct->change_scene(Scene::game);
		}
	}
	if (Keyboard::key_down(KEY_INPUT_Z) && chara->get_velocity() == 0 && !deg_flag) {
		deg_flag = true;

	}
	draw();
	
	mass->update();
	chara->update(stage,deg_flag,mass->get_masspos());
	txtbox->update();
}

void StageSelectTaskSystem::draw()
{
	DrawExtendGraph(0, 0, System::width, System::height, backgraph, FALSE);
	//DrawGraph(0, 0, backgraph, FALSE);
}

int StageSelectTaskSystem::get_stage()
{
	return stage;
}

void StageSelectTaskSystem::finalize()
{
	DeleteGraph(backgraph);
}

void StageSelectTaskSystem::clear(int num_)
{
	state[num_] = true;
}