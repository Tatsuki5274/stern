#include "SpawnItem.h"
#include"DxLib.h" 
#include"CoreTask.h"
#include <fstream>
#include <string>
#include <iterator>
#include"CoreTask.h"

SpawnItem::SpawnItem()
{
	std::ifstream itempath("img/item.json");
	if (itempath.fail()) throw "item.json is not found.";//��O����
	std::istreambuf_iterator<char> it(itempath);
	std::istreambuf_iterator<char> last;
	std::string str_json(it, last);		//string�`����json
	std::string err;
	item_data = json11::Json::parse(str_json, err);//Json�Ŏg����悤�ɂ���
}

void SpawnItem::create(std::string stg)
{
	//enemy�R���X�g���N�^��Kind,X,Y���K�v�ȉ\��
	//enemy�R���X�g���N�^��Kind,X,Y���K�v�ȉ\��
	for (auto &item : item_data[stg].array_items())
	{
		//�����l����---------------------------------------------------------------------------------------------------------
		class Point i_point = { item["x"].int_value(),item["y"].int_value(), item["w"].int_value(), item["h"].int_value() };
		//---------------------------------------------------------------------------------------------------------
		//��
		if (item["kind"].string_value() == "recovery") {
			//�������Č��݂̍Ō���ɓo�^
			ct->gts->recovery.push_back(RecoveryItem{i_point});
		}
	}
}
