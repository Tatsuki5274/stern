#include "TitleTaskSystem.h"
#include"DxLib.h"
#include"CoreTask.h"

TitleTaskSystem::TitleTaskSystem()
{
	startbutton = std::make_unique<TitleStartButton>();
	exitbutton = std::make_unique<TitleExitButton>();
	selecter = std::make_unique<TitleSelecter>();
	backgraph = LoadGraph("img/title/title.png");
}

void TitleTaskSystem::update()
{
	if (ct->keyboard->key_down(KEY_INPUT_Z)) {
		switch (selecter->button) {
		case Button::start:
			ct->scene = Scene::stageselect;
			break;
		case Button::exit:
			//exe�����
			break;
		}
	}

	draw();
	startbutton->update();
	exitbutton->update();
	//�J�[�\���̑傫����40�̂��ߗ]�T�������Ă����Ă���
	selecter->update(startbutton->get_lextx() - 50, exitbutton->get_lextx() - 50);
	DrawString(0, 0, "���݃^�C�g���^�X�N�ł�", GetColor(255, 0, 0));
}

void TitleTaskSystem::draw()
{
	DrawGraph(0, 0, backgraph, FALSE);
}
