#pragma once
#include<iostream>
#include"PauseTaskUI.h"
#include"PauseTaskSelecter.h"
#include<memory>

class PauseTask{
private:
	//�Z���N�^�[�N���X
	std::unique_ptr<PauseSelecter> p_selecter;
	//UI�N���X
	std::unique_ptr<PauseUI> p_ui;

	int backgraph;//�w�i
	int feedcnt;//�t�F�[�h�A�E�g�̃J�E���g
	void draw();//�w�i�AUI�̕`��
	void change_scene();//�V�[����؂�ւ��郁�\�b�h
	bool deg_flag;
public:
	PauseTask();
	void update();
};