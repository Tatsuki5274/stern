#include "Player.h"

//----------------------------------
//�v���C���[
//----------------------------------


void Player::PlayerInterface::Draw(int st)
{
}

Player::StarManager::StarManager()
{
	graph = LoadGraph("img/cursor.png");
}

void Player::StarManager::draw(double st, int x)
{
	DrawRotaGraph2(x, 0, 15, 0, 1.5, st, graph, FALSE);
}

void Player::StarManager::update(double ang, int x_)
{
	draw(ang, x_);
}

Player::Player()
{
	x = 200;
	y = 200;
	life = 0;
	angle = 0;
	invincible = 0;
	hp = 0;
	interval = 0;
	graph = LoadGraph("img/player.png");
}

void Player::update()
{
	//���̈ړ��ƃJ�[�\���p�x����-------------
	move();
	if (CheckHitKey(KEY_INPUT_Q)) {
		angle += 0.05;
	}
	if (CheckHitKey(KEY_INPUT_E)) {
		angle -= 0.05;
	}
	//---------------------------------------
	starmanager->update(angle, x);
	draw();

	DrawFormatString(0, 0, GetColor(255, 0, 0), "%d", x);
	DrawFormatString(0, 50, GetColor(255, 0, 0), "%d", y);
}

bool Player::damage(void)
{
	return false;
}

void Player::draw_interface(int)
{
}

void Player::move()
{
	//�Œ萔�l�ł͂Ȃ�velocity������
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		x += 2;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		x -= 2;
	}
	if (CheckHitKey(KEY_INPUT_UP)) {
		y -= 2;
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		y += 2;
	}
	check_foot();
}

void Player::check_foot()
{
	//���̓����蔻��
	if (y > 540) {
		y = 540;
	}
}

bool Player::knockback(int)
{
	return false;
}


