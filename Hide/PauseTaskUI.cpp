#include "PauseTaskUI.h"
#include"DxLib.h"

PauseUI::PauseUI()
{
	text[0].str = "�Q�[���ɖ߂�";
	text[1].str = "�X�e�[�W�Z���N�g�ɖ߂�";
	text[2].str = "�Q�[���I��";
	for (int i = 0; i < 3; ++i) {
		text[i].text_width = get_width(text[i]);
		text[i].x = 300 - (text[i].text_width / 2);
		text[i].y =  340 + 50 * i;
	}
}

void PauseUI::update()
{
	for (int i = 0; i < 3; ++i) {
		update_txt(text[i]);
	}
}
