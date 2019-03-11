#include "DxLib.h"
#include"GameTaskSystem.h"
#include"Player.h"

//----------------------------------
//�N���X�쐬�̍ہA�֐��i���\�b�h�j��public
//�ϐ���private�œ���Ă�������(W�ET)
//----------------------------------

GameTaskSystem *gts;

// WinMain�֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// ��ʃ��[�h�̐ݒ�
	SetGraphMode(600, 600, 32);//�E�B���h�E�̃T�C�Y�����߂�
	ChangeWindowMode(TRUE);// �E�B���h�E���[�h�ύX

	// �c�w���C�u��������������
	if (DxLib_Init() == -1) { return -1; };
	gts = new GameTaskSystem;
	//gts = new GameTaskSystem;
	//-------------------------------------------------
	SetDrawScreen(DX_SCREEN_BACK);//����ʐݒ�

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//��ʍX�V�����b�Z�[�W����&��ʎE�Q
		
		gts->update();

	}
	delete gts;
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;					// �\�t�g�̏I��
}
