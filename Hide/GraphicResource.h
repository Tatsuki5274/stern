#pragma once
class GraphicResource
{

public:
	//���
	enum class GraphicState {
		player_stay_right, player_stay_left,
	};
	//�C���X�g���N�^
	GraphicResource();
	//�f�X�g���N�^
	~GraphicResource();
	bool load(char* FileName, int AllNum,int XNum, int YNum,
		      int XSize, int YSize, int** G_handl);
	int get(int);
private:
	GraphicState graphicstate;
	//�n���h�� 
	int** handle;
protected:
};