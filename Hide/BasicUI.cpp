#include "BasicUI.h"
#include"DxLib.h"

BasicUI::BasicUI()
{
	x = 0;
	y = 0;
	strwidth = 0;
}
//コンストラクタで呼ぶ----------------------------------------------
void BasicUI::get_width(const char* str)
{
	strwidth = (int)(GetDrawStringWidth(str, strlen(str)));
}
//以下Updateで呼ぶ---------------------------------------------------
void BasicUI::update_txt(const char* str)
{
	draw_txt(str);
}
void BasicUI::draw_txt(const char* str)
{
	//         300は画面サイズの半分
	DrawString(300 - strwidth / 2, y, str, GetColor(0, 0, 0));
}
int BasicUI::get_lextx()
{
	//文字の始点を返す
	return 300 - strwidth / 2;
}
int BasicUI::get_y()
{
	return y;
}
//-------------------------------------------------------------------
