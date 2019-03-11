#include "GameTaskSystem.h"


GameTaskSystem::GameTaskSystem()
{
	normalstar = std::make_shared<BasicList<NormalStar>>();
	normalstar->lead();//���X�g��擪�ɖ߂�
}

GameTaskSystem::~GameTaskSystem()
{
}

void GameTaskSystem::update()
{
	//�m�[�}���X�^�[
	std::shared_ptr<NormalStar> new_instance = std::make_shared<NormalStar>(0,0,0);
	normalstar->create(new_instance);//�V�K�I�u�W�F�N�g�����X�g�Ǘ��ΏۂƂ���
	
	normalstar->get()->update();

	gts->map->update();
	gts->player->update();
}
