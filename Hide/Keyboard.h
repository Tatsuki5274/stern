#pragma once
#include"DxLib.h"

class Keyboard {
public:
	Keyboard() {
		
	}
	//���\�b�h
	void update();
	bool key_down(int);
	bool key_up(int);
	bool key_press(int);
	//bool Get(KEY_INPUT *key);
private:
	int current[256];//�L�[�{�[�h�Ή�������
	int previous[256];//�P�t���[���O�̔z����L��
};