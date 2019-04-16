#include "BossEnemy.h"
#include "CoreTask.h"
//-----------------------------------
//ボス敵
//-----------------------------------

Boss::Boss(Point point_, PhysicState physic_state_, EnemyState enemy_state_) : Enemy(point_, physic_state_, enemy_state_)
{
	bossstate = BossState::walk;
	movecnt = 0;
	init_render("boss");
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
			//ジャンプを行なったらwalkに変更
			bossstate = BossState::walk;
		}
		
	}
	//前のvelocityYを保持
	preY = velocityY;
	point.y += (int)velocityY;
	point.x += (int)velocityX;
}

void Boss::change_angle()
{
	//プレイヤーの座標が敵より小さかったら左に向く
	if (ct->gts->player->get_point().x < point.x) {
		anglestate = AngleState::right;
		//右向きアニメに変える
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
