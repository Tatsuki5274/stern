#pragma once
#include<iostream>

class StageSelectTaskSystem {
private:
	int stage;//�X�e�[�W���ʔԍ�
	bool state[4];//�N���A�t���O�i�X�e�[�W�����ɂ���ĕς���j
	int backgraph;//�w�i�摜
public:
	StageSelectTaskSystem();
	void update();//Map_Init���X�e�[�W�ԍ��Ɋ�Â����g��ς��ČĂ�
	void draw();
	int get_stage();
	void clear(int);
};