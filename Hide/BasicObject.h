#pragma once

//----------------------------------
//��{�ƂȂ�N���X
//----------------------------------

class BasicObject {
public:
	//�Œ���̏�����
	BasicObject():
		x(0),
		y(0),
		graph(0)
	{}
	//���\�b�h�i�֐��j
	void Draw();
	void Init();
private:
	//�ϐ�
	float x, y;//���W(�|�W�V����)
	int graph;//�摜�ւ̃p�X
};