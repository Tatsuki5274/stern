#pragma once
#include<memory>
#include"StageselectChara.h"
#include"StageSelectTaskMass.h"
#include"StageselectTaskTextBox.h"
#include"Point.h"
#include"SpawnEnemy.h"//�G�������X�e�[�W�I�𒼌�ɍs������
#include"SpawnItem.h"

class StageSelectTaskSystem {
protected:
	int stage;//�X�e�[�W���ʔԍ�
	bool state[4];//�N���A�t���O�i�X�e�[�W�����ɂ���ĕς���j
	int backgraph;//�w�i�摜
public:
	StageSelectTaskSystem();
	void update();//Map_Init���X�e�[�W�ԍ��Ɋ�Â����g��ς��ČĂ�
	void draw();
	int get_stage();
	void clear(int);
	
	std::unique_ptr<StageSelectTaskMass> mass;
	std::unique_ptr<StageSelectChara> chara;
	std::unique_ptr<StageSelectTextBox> txtbox;

	std::unique_ptr<SpawnEnemy> spawnenemy;//�G�̐���
	std::unique_ptr<SpawnItem> spawnitem;
};