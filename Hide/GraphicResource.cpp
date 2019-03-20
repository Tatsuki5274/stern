#include"GraphicResource.h" 
#include"DxLib.h" 
#include<fstream> 

//�C���X�g���N�^
GraphicResource::GraphicResource()
{
	handle = 0;
}
GraphicResource::GraphicResource(int** G_hundle)
{
	handle = G_hundle;
}
//�f�X�g���N�^
GraphicResource::~GraphicResource()
{
	DeleteGraph(**handle);
}
bool GraphicResource::load(char* FileName, int XNum, int YNum, int XSize, int YSize)
{
	//�t�@�C���ǂݍ���
	std::ifstream Graphic_R(FileName);
	//�ǂݍ��ݎ��s������Ԃ�
	if (!Graphic_R) { return false; }
	switch (graphicstate)
	{
	case GraphicState::player_stay_right:

		//���������͎����(10�̂Ƃ���) 
		LoadDivGraph(FileName, 10, XNum, YNum, XSize, YSize, *handle);
		break;

	case GraphicState::player_stay_left:
		LoadDivGraph(FileName, 10, XNum, YNum, XSize, YSize, *handle);
		break;
	}
	//
	Graphic_R.close();
	return true;
}

int GraphicResource::get(int kg_)
{
	//�n���h����Ԃ�
	return *handle[kg_];
}