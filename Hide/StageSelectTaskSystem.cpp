#include "StageSelectTaskSystem.h"
#include"CoreTask.h"

StageSelectTaskSystem::StageSelectTaskSystem()
{
	mass = std::make_unique<StageSelectTaskMass>();
	class Point point = { 30,100,30,30 };
	chara = std::make_unique<StageSelectChara>(point);
	txtbox = std::make_unique<StageSelectTextBox>();

	spawnenemy = std::make_unique<SpawnEnemy>("img/epath.json", ct->gts->enemys);
	spawnitem = std::make_unique<SpawnItem>("img/item.json",ct->gts->item);

	stage = 1;
	for (int i = 0; i < sizeof(state); ++i) {
		state[i] = false;
	}
	backgraph = LoadGraph("img/stageselect/back.png");
}

void StageSelectTaskSystem::update()
{
	if (Keyboard::key_down(KEY_INPUT_Z)&& chara->get_velocity() == 0) {
		switch (stage)
		{
		case 1:
			ct->gts->map->init((char*)"1", (char*)"chip1");
			spawnenemy->create("1");
			spawnitem->create("1");
			break;
		case 2:
			ct->gts->map->init((char*)"", (char*)"");
			break;
		case 3:
			ct->gts->map->init((char*)"", (char*)"");
			break;
		case 4:
			ct->gts->map->init((char*)"", (char*)"");
			break;
		}
		ct->gts->init();
		ct->cts->init();
		ct->gts->goal->init();
		ct->scene = Scene::game;//�Q�[���V�[���ɑJ��
	}
	draw();
	for (int i = 0; i < sizeof(mass); ++i) {
		mass->update();
	}
	chara->update(stage);
	txtbox->update(stage);
	DrawFormatString(0, 0, GetColor(0, 255, 0), "���݃X�e�[�W %d ��I��", stage);
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