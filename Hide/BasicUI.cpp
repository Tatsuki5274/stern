#include "BasicUI.h"
#include"DxLib.h"

BasicUI::BasicUI()
{
	x = 0;
	y = 0;
	strwidth = 0;
}
//�R���X�g���N�^�ŌĂ�----------------------------------------------
void BasicUI::get_width(const char* str)
{
	strwidth = (int)(GetDrawStringWidth(str, strlen(str)));
}
//�ȉ�Update�ŌĂ�---------------------------------------------------
void BasicUI::update_txt(const char* str)
{
	draw_txt(str);
}
void BasicUI::draw_txt(const char* str)
{
	//         300�͉�ʃT�C�Y�̔���
	DrawString(300 - strwidth / 2, y, str, GetColor(0, 0, 0));
}
int BasicUI::get_lextx()
{
	//�����̎n�_��Ԃ�
	return 300 - strwidth / 2;
}
int BasicUI::get_y()
{
	return y;
}
//-------------------------------------------------------------------
