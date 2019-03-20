#include"GraphicResource.h"
#include"DxLib.h"
#include<fstream>

//インストラクタ
GraphicResource::GraphicResource()
{
	handle = 0;
}
GraphicResource::GraphicResource(int** G_hundle)
{
	handle = G_hundle;
}

//デストラクタ
GraphicResource::~GraphicResource()
{

}
bool GraphicResource::load(char* FileName, int XNum, int YNum, int XSize, int YSize)
{
	//ファイル読み込み
	std::ifstream Graphic_R(FileName);
	if (!Graphic_R){return false;}
	switch(graphicstate)
	{
	case GraphicState::player_stay_right:

		//画像の分割総数は手入力？(10のところ)
		LoadDivGraph(FileName, 10, XNum, YNum, XSize, YSize, *handle);
		break;

	case GraphicState::player_stay_left:
		LoadDivGraph(FileName, 10, XNum, YNum, XSize, YSize, *handle);
		break;
	}
	//ファイルを閉じる
	Graphic_R.close();
	return true;
}
int GraphicResource::get(int kg_)
{
	//ハンドルと最大枚数を返す
	return *handle[kg_];
}
