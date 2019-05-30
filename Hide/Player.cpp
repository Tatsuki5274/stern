﻿#include "Player.h"
#include"Point.h"
#include"CoreTask.h"
#include"Keyboard.h"
#include "PlayerConfig.h"
#include"System.h"
#include"environments.h"

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
	DrawGraph(System::width-100, 0, lifegraph, FALSE);
	DrawFormatString(System::width - 60, 0, GetColor(255, 255, 255), " × %d",life);
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
	DrawRotaGraph2(x - Map::get_camera().x+ ct->gts->player->get_point().w / 2, 0, 15, 0, 1, st, graph, FALSE);//Xにプレーヤー.wの半分だけついか
}

void Player::StarManager::update(double ang, int x_)
{
	draw(ang, x_);

	if (starmanagercoolCnt <= 0) {
		if (Keyboard::key_down(KEY_INPUT_Z)) {
			starmanagercoolCnt = STAR_COOLTIME;   //クールタイム60フレーム
			Point prestarpoint{ x_, Map::get_camera().y, 32, 32 };
			if (!(ct->gts->map->get_bottom(prestarpoint) ||
				ct->gts->map->get_left(prestarpoint) ||
				ct->gts->map->get_right(prestarpoint) ||
				ct->gts->map->get_top(prestarpoint))) {
				if (starmanagercoolCnt <= 0) {
					starmanagercoolCnt = 180;   //クールタイム180フレーム
					class Point point = { x_,Map::get_camera().y,32,32 };
					struct PhysicState physic_state = { 1 };//	float gravity;
					struct StarState star_state = { 10,10,10,50,ang };//	int bright, int radius, int power, int life, double angle;

					ct->gts->normalstar.push_back(NormalStar{ point,physic_state,star_state });	//新規インスタンスを生成して最後尾へ登録する
					//ノーマルスター
					//Point point_, PhysicState physic_state_, StarState star_state
				}
			}
		}
		else {
			//キャンセル音をだす　
		}

		if (starmanagercoolCnt <= 0) {
			if (Keyboard::key_down(KEY_INPUT_V)) {
				starmanagercoolCnt = STAR_COOLTIME;   //クールタイム60フレーム
				Point prestarpoint{ x_, Map::get_camera().y, 32, 32 };
				if (!(ct->gts->map->get_bottom(prestarpoint) ||
					ct->gts->map->get_left(prestarpoint) ||
					ct->gts->map->get_right(prestarpoint) ||
					ct->gts->map->get_top(prestarpoint))) {

					ct->gts->gravityStar.clear();
					class Point point = { x_ ,Map::get_camera().y,32,32 };
					struct PhysicState physic_state = { 1 };//	float gravity;
					struct StarState star_state = { 10,10,10,50,ang };//	int bright, int radius, int power, int life, double angle;

					ct->gts->gravityStar.push_back(GravityStar{ point,physic_state,star_state });	//新規インスタンスを生成して最後尾へ登録する


				}
			}
			if (starmanagercoolCnt > 0) {
				starmanagercoolCnt--;

			}

		}
	}
}

Player::Player(Point point_, PhysicState physic_state_):BasicObject(point)
{
	life = PLAYER_MAX_LIFE;
	hp = PLAYER_MAX_HP;
	angle = 0;
	invincible = 0;
	jumpCnt = 0;
	interval = 0;
	//graph = LoadGraph("img/player.png");
	starmanager = std::make_unique<StarManager>();
	playerinterface = std::make_unique<PlayerInterface>();

}
void Player::spawn(int x_, int y_, int w_, int h_)
{
	p_point = { x_,y_,w_,h_ };
}
void Player::init()
{
	point = p_point;
	shape->set("player");//resource.jsonのnameが"player"のものをセットする
}

bool Player::recover()
{
	bool ret = false;
	if (hp < PLAYER_MAX_LIFE) {
		hp++;
		ret = true;
	}
	return ret;
}



void Player::update()
{
	//仮の移動とカーソル角度調整-------------
	move();
	if (Keyboard::key_press(KEY_INPUT_Q)) {
		angle += CURSOL_TURN_SPEED;
	}
	if (Keyboard::key_press(KEY_INPUT_E)) {
		angle -= CURSOL_TURN_SPEED;
	}
	//---------------------------------------
	starmanager->update(angle, point.x);
	playerinterface->update(hp,life);
	if (invincible % 4 <= 2) {
		shape->draw(point);
	}
	if (jumpCnt <= 0) {
		point.y += physicshape->fall(point);
	}
	if (invincible > 0) {
		invincible--;
	}
}

bool Player::damage()
{
	if (invincible <= 0) {
		invincible = PLAYER_INVINCIBLE;
		hp -= 1;
		if (hp <= 0) {
			return true;
		}
	}
	return false;
}

void Player::draw_interface(int)
{
}

void Player::move()
{
	//左右移動
	if (Keyboard::key_press(KEY_INPUT_LEFT)) {
		if (Keyboard::key_press(KEY_INPUT_C)/* && velocityX <= -6*/) { //仮のダッシュ処理
			/*velocityX--;*/
			point.x+= physicshape->Movement_X(point, -PLAYER_MAX_SPEED);
		}
		else {
			point.x += physicshape->Movement_X(point, -PLAYER_SPEED);
		}
	}
	if (Keyboard::key_press(KEY_INPUT_RIGHT)) {
		if (Keyboard::key_press(KEY_INPUT_C)) {  //仮のダッシュの処理
			/*if (velocityX <= +6) {
				velocityX++;
			}*/
			point.x += physicshape->Movement_X(point, PLAYER_MAX_SPEED);
		}
		else {
			point.x += physicshape->Movement_X(point, PLAYER_SPEED);
		}
	}
	//ジャンプ
	if (point.y==preY) {
		if (Keyboard::key_press(KEY_INPUT_X)) {


			if (Keyboard::key_down(KEY_INPUT_X)) {
				jumpCnt = PLAYER_MAX_JUMP;
			}
			if (jumpCnt > 0) {
				
				point.y += physicshape->Movement_Y(point, -jumpCnt - 8);//jumpCntを設けないと空中浮遊する
				Point extendpoint = point;
				extendpoint.y--;
				if (ct->gts->map->get_top(extendpoint)) {
					jumpCnt = 0;
				}

			}
		}
	}
	if (Keyboard::key_up(KEY_INPUT_X)) {
		jumpCnt = 0;
	}
	jumpCnt--;
	preY = point.y;
}

bool Player::knockback(int)
{
	return false;
}

void Player::jump(int pow) {
	while (pow > 0) {
		point.y += physicshape->Movement_Y(point, -pow);
		pow--;
	}
}


//アクセサメソッド

void Player::set_hp(int hp) {
	if (hp < 0) hp = 0;
	this->hp = hp;
}
int Player::get_hp() {
	return this->hp;
}
void Player::set_angle(double angle) {
	this->angle = angle;
}
double Player::get_angle()
{
	return this->angle;
}
void Player::set_invincible(int invincible) {
	this->invincible = invincible;
}
int Player::get_invincible() {
	return this->invincible;
}
void Player::set_life(int life) {
	this->life = life;
}
int Player::get_life() {
	return this->life;
}