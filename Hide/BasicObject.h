#pragma once

//----------------------------------
//��{�ƂȂ�N���X
//----------------------------------

class BasicObject {
public:
	//�Œ���̏�����
	BasicObject() {
		velocity = 0;
		x = 0;
		y = 0;
		graph = 0;
	}

	//���\�b�h�i�֐��j
	void Draw();
	void Init();
	void Update();
protected:
	//�ϐ�
	float velocity;//�ړ���
	float x, y;//���W(�|�W�V����)
	int graph;//�摜�ւ̃p�X
};