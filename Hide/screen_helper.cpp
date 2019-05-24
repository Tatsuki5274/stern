#include "screen_helper.h"
#include"screenhelper_config.h"
#include"DxLib.h"
#include"System.h"

int ScreenFunc::brendcnt;

void ScreenFunc::initialize()
{
	//�t�F�[�h�A�E�g�A�C���p�̉摜�����[�h
	ScreenHelperGraph::black_graph = LoadGraph("./img/screen/black_screen.png");
	ScreenHelperGraph::white_graph = LoadGraph("./img/screen/white_screen.png");
	brendcnt = 0;//�����͓����ɂ��Ă���
}

bool ScreenFunc::FeedOut(int screen_graph)
{
	bool check = false;
	//�摜��Z�����Ă����i�^�����A�^�����ɂȂ�j
	if (check_brend_max()) {//���S�ɐ^�����A�^�����ɂȂ�����
		check = true;
	}
	else {//255�����Ȃ�
		brendcnt++;
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, brendcnt);		//�u�����h���[�h�����ɐݒ�
	DrawExtendGraph(0, 0, System::width, System::height, screen_graph, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t

	return check;
}

void ScreenFunc::FeedIn(int screen_graph)
{
	//�摜�𔖂����Ă����i�����ɂȂ�j
	if (!check_brend_min()) {//0���߂Ȃ�
		brendcnt--;
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, brendcnt);		//�u�����h���[�h�����ɐݒ�
	DrawExtendGraph(0, 0, System::width, System::height, screen_graph, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
}

bool ScreenFunc::check_brend_max()
{
	return brendcnt >= 255;//255���傫���Ȃ�true
}

bool ScreenFunc::check_brend_min()
{
	return brendcnt <= 0;//0��菬�����Ȃ�true
}
