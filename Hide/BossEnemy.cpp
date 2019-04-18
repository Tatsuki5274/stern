#include "BossEnemy.h"
#include "CoreTask.h"
//-----------------------------------
//�{�X�G
//-----------------------------------

Boss::Boss(Point point_, PhysicState physic_state_, EnemyState enemy_state_) : Enemy(point_, physic_state_, enemy_state_)
{
	bossstate = BossState::walk;
	anglestate = AngleState::right;
	movecnt = 0;
	shape->set("boss");
}

void Boss::move()
{
	switch (bossstate)
	{
	case BossState::walk:
		switch (anglestate)
		{
		case AngleState::right:
			velocityX = 1;
			break;
		case AngleState::left:
			velocityX = -1;
			break;
		}
	break;
	case BossState::jump:
		if (velocityY == 0 && velocityY == preY) {
			velocityY -= 18.0f;
			//�W�����v���s�Ȃ�����walk�ɕύX
			bossstate = BossState::walk;
		}
		
	}
	//�O��velocityY��ێ�
	preY = velocityY;
	point.y += (int)velocityY;
	point.x += (int)velocityX;
}

void Boss::change_angle()
{
	//�v���C���[�̍��W���G��菬���������獶�Ɍ���
	if (ct->gts->player->get_point().x < point.x) {
		anglestate = AngleState::right;
		//�E�����A�j���ɕς���
	}
	else {
		anglestate = AngleState::left;
	}
}

void Boss::change_state()
{
	++movecnt;
	if (movecnt >= 300) {
		bossstate = BossState::jump;
		movecnt = 0;
	}
}

AngleState Boss::get_anglestate()
{
	return anglestate;
}
