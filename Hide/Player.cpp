﻿#include "Player.h"
#include"Point.h"
#include"CoreTask.h"
#include"Keyboard.h"

//----------------------------------
//プレイヤー
//----------------------------------

Player::PlayerInterface::PlayerInterface()
{
	hpgraph = LoadGraph("img/hp.png");
	hpfreamgraph = LoadGraph("img/hpfream.png");
	lifegraph = LoadGraph("img/life.png");
}

void Player::PlayerInterface::draw()
{
	//残機
	DrawGraph(500, 0, lifegraph, FALSE);
	DrawFormatString(540, 0, GetColor(255, 255, 255), " × %d",life);
	//HP
	for (int i = 0; i < 3; ++i) {
		DrawGraph(40 * i, 0, hpfreamgraph, FALSE);
		for (int j = 0; j < hp; ++j) {
			DrawGraph(40 * j, 0, hpgraph, TRUE);
		}
	}
}

void Player::PlayerInterface::update(int hp_,int life_)
{
	hp = hp_;
	life = life_;
	draw();
}

Player::StarManager::StarManager()
{
	graph = LoadGraph("img/cursor.png");
}

void Player::StarManager::draw(double st, int x)
{
	DrawRotaGraph2(x, 0, 0, 0, 1, st, graph, FALSE);
}

void Player::StarManager::update(double ang, int x_)
{
	draw(ang, x_);
	if (ct->keyboard->key_down(KEY_INPUT_Z)) {
		ct->gts->normalstar->lead();//リストを先頭に戻す
		//ノーマルスター
		//Point point_, PhysicState physic_state_, StarState star_state
		class Point point = { x_,0,0,0 };
		struct PhysicState physic_state = { 0,0,0 };//	float gravity; float repulsion;int weight;
		struct StarState star_state = { 10,10,10,50,ang };//	int bright, int radius, int power, int life, double angle;
		std::shared_ptr<NormalStar> new_instance = std::make_shared<NormalStar>(point,physic_state,star_state);
		ct->gts->normalstar->create(new_instance);//新規オブジェクトをリスト管理対象とする
	}
}

Player::Player(Point point_, PhysicState physic_state_, PlayerState player_state):Physic(point_,physic_state_)
{
	life = player_state.life;
	hp = player_state.life;
	angle = 0;
	invincible = 0;
	interval = 0;
	//graph = LoadGraph("img/player.png");
	starmanager = std::make_unique<StarManager>();
	playerinterface = std::make_unique<PlayerInterface>();

}

void Player::init()
{
	init_render("player");	//resource.jsonのnameが"player"のものをセットする
}

double Player::get_angle()
{
	return angle;
}

void Player::update()
{
	//仮の移動とカーソル角度調整-------------
	move();
	if (ct->keyboard->key_press(KEY_INPUT_Q)) {
		angle += 0.05;
	}
	if (ct->keyboard->key_press(KEY_INPUT_E)) {
		angle -= 0.05;
	}
	//---------------------------------------
	starmanager->update(angle, point.x);
	playerinterface->update(hp,life);
	draw(true);
	exercise();
	DrawFormatString(0, 0, GetColor(255, 0, 0), "%d", point.x);//L
	DrawFormatString(0, 50, GetColor(255, 0, 0), "%d", point.y);//T
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
	//左右移動
	if (ct->keyboard->key_press(KEY_INPUT_LEFT)) {
		velocityX -= 2;
	}
	if (ct->keyboard->key_press(KEY_INPUT_RIGHT)) {
		velocityX += 2;
	}
	//ジャンプ
	if (ct->keyboard->key_down(KEY_INPUT_X)) {
		velocityY -= 10;
	}
	//ダッシュ
	
	//
	point.x += velocityX;
	point.y += velocityY;
}

bool Player::knockback(int)
{
	return false;
}


