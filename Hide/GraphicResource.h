#pragma once
class GraphicResource
{
	//�n���h�� 
	int** handle;
	//���
	enum class GraphicState {
		player_stay_right, player_stay_left,
	};
	GraphicState graphicstate;
public:
	//�C���X�g���N�^
	GraphicResource();
	GraphicResource(int** G_handle);
	//�f�X�g���N�^
	~GraphicResource();
	bool load(char* FileName, int XNum, int YNum, int XSize, int YSize);
	int get(int);
protected:
};