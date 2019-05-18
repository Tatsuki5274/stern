#include "GameOverTaskUI.h"
#include"DxLib.h"

GameOverUI::GameOverUI()
{
	text[0].str = "�R���e�j���[";
	text[1].str = "�X�e�[�W�Z���N�g";
	text[2].str = "�^�C�g��";
	for (int i = 0; i < 3; ++i) {
		text[i].color = GetColor(255, 255,0);
		text[i].text_width = get_width(text[i]);
		text[i].x = 300 - (text[i].text_width / 2);
		text[i].y = 340 + 50 * i;
	}
	select = SelectMode::Continue;
	deg_flag = true;
	ui_brend = 160;
}

void GameOverUI::update()
{
	//�Z���N�^�[��_�ł����邽�߂̏���--------------
	if (deg_flag) {
		ui_brend -= 2;
		if (ui_brend < 0) {
			deg_flag = false;
		}
	}
	else {
		ui_brend += 2;
		if (ui_brend >= 160) {
			deg_flag = true;
		}
	}
	//-------------------------------------------------
	//�e�L�X�g�̕`��
	for (int i = 0; i < 3; ++i) {
		update_txt(text[i]);
	}
	//------------------------------------------------
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, ui_brend);		//�u�����h���[�h����(128/255)�ɐݒ�
	//�Z���N�^�[�̕`��
	draw_selecter();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
}

void GameOverUI::draw_selecter()
{
	switch (select) {
	case SelectMode::Continue:
		// + 16�̓t�H���g�T�C�Y
		DrawBox(text[0].x - 1, text[0].y - 1, text[0].x + text[0].text_width + 1, text[0].y + 16 + 1, GetColor(255, 255, 255), TRUE);
		break;
	case SelectMode::StageSelect:
		DrawBox(text[1].x, text[1].y, text[1].x + text[1].text_width, text[1].y + 16, GetColor(255, 255, 255), TRUE);
		break;
	case SelectMode::Title:
		DrawBox(text[2].x, text[2].y, text[2].x + text[2].text_width, text[2].y + 16, GetColor(255, 255, 255), TRUE);
		break;
	}
}

void GameOverUI::change_Select(SelectMode sm_)
{
	select = sm_;
}

SelectMode GameOverUI::getter()
{
	return select;
}
