#include "TitleTaskSystem.h"
#include"DxLib.h"
#include"CoreTask.h"

TitleTaskSystem::TitleTaskSystem()
{
	titlestar = std::make_unique<TitleStar>();
	graph = LoadGraph("img/title/title.png");
}

void TitleTaskSystem::update()
{
	//	//�L�[�{�[�h�œ��͂��B���ăX�e�[�W�Z���N�g�ɑJ��
	if (ct->keyboard->key_down(KEY_INPUT_Z)) {
		//WaitTimer(600 * 3);
		ct->scene = Scene::stageselect;
	}
	draw();
	titlestar->update();
	DrawString(50, 0, "���݃^�C�g���^�X�N�ł�", GetColor(255, 0, 0));
}

void TitleTaskSystem::draw()
{
	SetDrawBright(255, 255, 255);
	DrawGraph(0, 0, graph, FALSE);
}

TitleTaskSystem::TitleStar::TitleStar()
{
	switchbright = false;
	x = 100;
	y = 100;
	bright = 195;
	graph = LoadGraph("img/title/star.png");
}

void TitleTaskSystem::TitleStar::draw()
{
	SetDrawBright(bright, bright, bright);
	DrawGraph(0, 0, graph, TRUE);
}

void TitleTaskSystem::TitleStar::update()
{
	bright_switch();
	draw();
}

void TitleTaskSystem::TitleStar::bright_switch()
{
	//����_�ł�����--------------------------------
	if (bright > 255) switchbright = true;
	else if (bright < 195) switchbright = false;
	if (switchbright) bright--;
	else bright++;
	//----------------------------------------------
}
