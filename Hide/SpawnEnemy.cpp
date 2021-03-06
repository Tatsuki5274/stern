﻿#include "SpawnEnemy.h"
#include"DxLib.h" 
#include"CoreTask.h"
#include <fstream>
#include <string>
#include <iterator>
#include"CoreTask.h"
#include "json11.hpp"

SpawnEnemy::SpawnEnemy(std::string path_, std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> _enemys) : Spawn(path_)
{
	enemys = _enemys;
}

void SpawnEnemy::create(std::string stg)
{
	//enemyコンストラクタにKind,X,Yが必要な可能性
	for (auto &enemy : data[stg].array_items())
	{	
		//初期値制御---------------------------------------------------------------------------------------------------------
			//(Point point_, PhysicState physic_state_, EnemyState enemy_state_)
		class Point point = { enemy["x"].int_value(),enemy["y"].int_value(), enemy["w"].int_value(), enemy["h"].int_value() };
		struct PhysicState physic_state = {1};//float gravity, float repulsion, int weight;//jsonがいじれないので応急処置、ゆるして
		struct EnemyState enemy_state = { enemy["life"].int_value(),enemy["damage"].int_value(),AngleState::left };//life,damage,anglestate
		//---------------------------------------------------------------------------------------------------------
		//歩行
		if(enemy["kind"].string_value() == "walk") {
			//生成して現在の最後尾に登録
			enemys->push_back(std::make_unique<WalkingEnemy>(point, physic_state, enemy_state));
		}	
		//飛行
		if (enemy["kind"].string_value() == "fly") {
			//生成して現在の最後尾に登録
			enemys->push_back(std::make_unique<FlyingEnemy>(point,physic_state,enemy_state ));
		}
		//投げつける奴
		if (enemy["kind"].string_value() == "throw") {
			//生成して現在の最後尾に登録
			enemys->push_back(std::make_unique<ThrowingEnemy>( point,physic_state,enemy_state ));
		}
	}
}
