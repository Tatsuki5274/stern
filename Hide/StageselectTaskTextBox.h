#pragma once
#include<iostream>

class StageSelectTextBox {
private:
	int boxgraph;//�e�L�X�g�{�b�N�X�̉摜
	//���W�͌Œ�̂��߃v���p�e�B�͕K�v�Ȃ��Ɣ��f
	//�e�L�X�g��String�ɂ��邩DrawString()�ɂ��邩������
public:
	StageSelectTextBox();
	void update(int);
	void draw(int);
};