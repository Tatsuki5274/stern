#include"GraphicResource.h" 
#include"DxLib.h" 
#include<fstream> 

//�C���X�g���N�^
GraphicResource::GraphicResource()
{
	*handle = new int[256];
}
//�f�X�g���N�^
GraphicResource::~GraphicResource()
{
	for (int c = 0; c < 256; ++c)
	{
		DeleteGraph(*handle[c]);
	}
}
bool GraphicResource::load(char* FileName, int AllNum, int XNum, int YNum, 
						   int XSize, int YSize, int **G_handle)
{
	//�t�@�C���ǂݍ���
	std::ifstream Graphic_R(FileName);
	//�ǂݍ��ݎ��s������Ԃ�
	if (!Graphic_R) { return false; }
	switch (graphicstate)
	{
	case GraphicState::player_stay_right:
		*handle = *G_handle;
		break;
	case GraphicState::player_stay_left:
		*handle = *G_handle;
		break;
	}
	LoadDivGraph(FileName, AllNum, XNum, YNum, XSize, YSize, *handle);

	//�t�@�C�������
	Graphic_R.close();

	return true;
}

int GraphicResource::get(int kg_)
{
	//�n���h����Ԃ�
	return *handle[kg_];
}