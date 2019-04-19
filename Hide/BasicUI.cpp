#include "BasicUI.h"
#include"DxLib.h"

BasicUI::BasicUI()
{
}
//�R���X�g���N�^�ŌĂ�----------------------------------------------
int BasicUI::get_width(Text _txt)
{
	return (int)(GetDrawStringWidth(_txt.str, strlen(_txt.str)));
}
//�ȉ�Update�ŌĂ�---------------------------------------------------
void BasicUI::update_txt(Text _txt)
{
	draw_txt(_txt);
}
void BasicUI::draw_txt(Text _txt)
{
	//         300�͉�ʃT�C�Y�̔���
	DrawString(_txt.x, _txt.y, _txt.str, GetColor(0, 0, 0));
}
int BasicUI::get_lextx(Text _txt)
{
	//�����̎n�_��Ԃ�(��ʔ������當����̔������������l)
	return 300 - _txt.text_width / 2;
}
int BasicUI::get_y(Text _txt)
{
	return _txt.y;
}
//-------------------------------------------------------------------
