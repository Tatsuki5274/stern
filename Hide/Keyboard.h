#pragma once
#include"DxLib.h"
#include <memory>
#define KEY_BOARD_BUF_SIZE 256


class Keyboard {
public:
	Keyboard();
	~Keyboard();
	void update();
	bool key_down(int);
	bool key_up(int);
	bool key_press(int);
	//bool Get(KEY_INPUT *key);
private:
	//DX���C�u�����̎d�l��X�}�[�g�|�C���^�ɂł��Ȃ�
	char* current;	//�L�[�{�[�h�Ή�������
	char* previous;	//�P�t���[���O�̔z����L��
	char* work;	//��Ɨ̈�
};