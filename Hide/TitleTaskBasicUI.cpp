#include "TitleTaskBasicUI.h"
#include"DxLib.h"

TitleTaskBasicUI::TitleTaskBasicUI()
{
	x = 0;
	y = 0;
	strwidth = 0;
}
//�R���X�g���N�^�ŌĂ�----------------------------------------------
void TitleTaskBasicUI::get_width(const char* str)
{
	//��ɕ��������Ƃ�K�v���Ȃ����߃R���X�g���N�^�ŋL�q
	strwidth = (int)(GetDrawStringWidth(str, strlen(str)));
}
//�ȉ�Update�ŌĂ�---------------------------------------------------
void TitleTaskBasicUI::update_txt(const char* str)
{
	draw_txt(str);
}
void TitleTaskBasicUI::draw_txt(const char* str)
{
	//         300�͉�ʃT�C�Y�̔���
	DrawString(300 - strwidth / 2, y, str, GetColor(0, 0, 0));
}
int TitleTaskBasicUI::get_lextx()
{
	//�����̎n�_��Ԃ�
	return 300 - strwidth / 2;
}
int TitleTaskBasicUI::get_y()
{
	return y;
}
//-------------------------------------------------------------------
