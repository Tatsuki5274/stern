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
	std::ifstream epath("img/epath.json");
	if (epath.fail()) throw "resource.json is not found.";//��O����
	std::istreambuf_iterator<char> it(epath);
	std::istreambuf_iterator<char> last;
	std::string str_json(it, last);		//string�`����json
	std::string err;
	data = json11::Json::parse(str_json, err);//Json�Ŏg����悤�ɂ���
}

void SpawnEnemy::create(std::string stg)
{
	//enemy�R���X�g���N�^��Kind,X,Y���K�v�ȉ\��
	for (auto &enemy : data[stg].array_items())
	{	//int�^�ɂ���
		//�^�ϊ�
		//String�^�ɂ���A���̂���char�^�ɕϊ�
		//graph = item["graph"].string_value().c_str();    //"img/f.png";
		if(enemy["kind"].string_value().c_str() == "walking") {
			//���s(�R���X�g���N�^������x,y,graph,kind��ǉ�����)
		    ct->gts->walking_enemy->lead();//���X�g��擪�ɖ߂�
			//---------------------------------------------------------------------------------------------------------
			//(Point point_, PhysicState physic_state_, EnemyState enemy_state_)
			class Point point = { enemy["x"].int_value(),enemy["y"].int_value(), enemy["w"].int_value(), enemy["h"].int_value() };
			struct PhysicState physic_state = { (float)enemy["garavity"].number_value(),(float)enemy["replusion"].number_value(),enemy["weight"].int_value() };//float gravity, float repulsion, int weight;
			struct EnemyState enemy_state = { enemy["life"].int_value(),enemy["damage"].int_value() };//life,damage
			//---------------------------------------------------------------------------------------------------------

			std::shared_ptr<WalkingEnemy> new_instance = std::make_shared<WalkingEnemy>(point,physic_state,enemy_state);
			ct->gts->walking_enemy->create(new_instance);//�V�K�I�u�W�F�N�g�����X�g�Ǘ��ΏۂƂ���
			break;
		}	

		//switch���œG�̎�ނ����ʂ��A���X�g���\�z����
		//Create();//�G�̃��X�g
	}
}
