#pragma once
#include"DxLib.h"

class ScreenFunc {
private:
	//�t�B�[���h
	static int brendcnt;//�摜�̓����x������
	//�u�����h�J�E���g�̃`�F�b�N���\�b�h
	static bool check_brend_max();//255�ɂȂ�����true��Ԃ�
	static bool check_brend_min();//0�ɂȂ�����true��Ԃ�
public:
	static void initialize();//�摜�̃��[�h�Ȃ�

	//�ǂ������Ƃ��ɌĂԂ��Ȃǂ̓V�[�������߂�
	static bool FeedOut(int screen_graph);//�Â����鏈��(true : �V�[���؂�ւ����s��, false : ���s�Ȃ�)
	static void FeedIn(int screen_graph);//���邭���鏈��

};