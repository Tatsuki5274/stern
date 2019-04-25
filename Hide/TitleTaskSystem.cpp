#include "TitleTaskSystem.h"
#include"DxLib.h"
#include"CoreTask.h"

TitleTaskSystem::TitleTaskSystem()
{
	title_ui = std::make_unique<TitleUI>();
	selecter = std::make_unique<TitleSelecter>();
	backgraph = LoadGraph("img/title/title.png");
}

void TitleTaskSystem::update()
{
	if (ct->keyboard->key_down(KEY_INPUT_Z)) {
		ct->audio->play("decision");
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
	title_ui->update();
	//�J�[�\���̑傫����40�̂��ߗ]�T�������Ă����Ă���
	selecter->update(title_ui->get_lextx(title_ui->text[0]) - 50, title_ui->get_lextx(title_ui->text[1]) - 50);
	DrawString(0, 0, "���݃^�C�g���^�X�N�ł�", GetColor(255, 0, 0));
}

void TitleTaskSystem::draw()
{
	DrawGraph(0, 0, backgraph, FALSE);
}
