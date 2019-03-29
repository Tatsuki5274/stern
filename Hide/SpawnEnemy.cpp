#include "SpawnEnemy.h"
#include"DxLib.h" 
#include"CoreTask.h"
#include <fstream>
#include <string>
#include <iterator>
#include"CoreTask.h"
#include "json11.hpp"

SpawnEnemy::SpawnEnemy()
{
	std::ifstream epath("data/epath.json");
	if (epath.fail()) throw "resource.json is not found.";//例外処理
	std::istreambuf_iterator<char> it(epath);
	std::istreambuf_iterator<char> last;
	std::string str_json(it, last);		//string形式のjson
	std::string err;
	data = json11::Json::parse(str_json, err);//Jsonで使えるようにする
}

void SpawnEnemy::create(std::string stg)
{
	//enemyコンストラクタにKind,X,Yが必要な可能性
	for (auto &enemy : data[stg].array_items())
	{	//int型にする
		//型変換
		//String型にする、そのあとchar型に変換
		//if(enemy["kind"].string_value().c_str() == "walking") {
			//歩行(コンストラクタ引数にx,y,graph,kindを追加する)
			//---------------------------------------------------------------------------------------------------------
			//(Point point_, PhysicState physic_state_, EnemyState enemy_state_)
			class Point point = { enemy["x"].int_value(),enemy["y"].int_value(), enemy["w"].int_value(), enemy["h"].int_value() };
			struct PhysicState physic_state = { (float)enemy["gravity"].number_value(),(float)enemy["repulsion"].number_value(),enemy["weight"].int_value() };//float gravity, float repulsion, int weight;
			struct EnemyState enemy_state = { enemy["life"].int_value(),enemy["damage"].int_value() };//life,damage
			//---------------------------------------------------------------------------------------------------------
			ct->gts->walking_enemy->lead();//リストを先頭に戻す
			std::shared_ptr<WalkingEnemy> new_instance = std::make_shared<WalkingEnemy>(point,physic_state,enemy_state);
			ct->gts->walking_enemy->create(new_instance);//新規オブジェクトをリスト管理対象とする
		//}	
	}
}

void SpawnEnemy::destroy()
{
	ct->gts->walking_enemy->lead();//<-問題?
	//while (ct->gts->walking_enemy->exist()) {
		ct->gts->walking_enemy->destroy();
	//	ct->gts->walking_enemy->proceed();
	//}
}
