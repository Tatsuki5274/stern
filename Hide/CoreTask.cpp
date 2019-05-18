﻿#include "CoreTask.h"
#include "Rendering.h"
//
#include "Audio.h"

GameTaskSystem *gts;

CoreTask::CoreTask()
{
	tts = std::make_shared<TitleTaskSystem>();
	gts = std::make_shared<GameTaskSystem>();
	cts = std::make_shared<ClearTaskSystem>();
	gots = std::make_shared<GameOverTaskSystem>();
	pts = std::make_shared<PauseTask>();
	scene = Scene::title;
}

void CoreTask::update()
{
	Keyboard::update();
	switch (scene) {
	case Scene::title:
		tts->update();
		break;
	case Scene::stageselect:
		ssts->update();
		break;
	case Scene::game:
		//graph->load("player");
		gts->update();
		break;
	case Scene::gameover:
		gots->update();
		break;
	case Scene::clear:
		cts->update();
		break;
	case Scene::pause:
		pts->update();
		break;
	}
}

void CoreTask::init()
{
	//静的メンバの初期化
	GraphicResource::init();
	Keyboard::initialize();
	Audio::init();
	Item::player = mdl::player;
	Enemy::player = mdl::player;
	//メンバ生成
	ssts = std::make_shared<StageSelectTaskSystem>();

	//音
	Audio::load("action");
	Audio::load("system");
	Audio::load("stage");
	//画像
	GraphicResource::load("item");
	GraphicResource::load("goal");
	GraphicResource::load("player");
	GraphicResource::load("enemy");

	//ct->graph->load("star");    //starの画像をロード(現在スコープにplayerがあるためコメントアウト)
	mdl::player->init();	//init_render("player"); を実行。resource.jsonのnameが"player"の画像をセットする
}

void CoreTask::finalize()
{
	Keyboard::finalize();
}