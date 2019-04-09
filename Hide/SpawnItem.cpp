#include "SpawnItem.h"
#include"DxLib.h" 
#include"CoreTask.h"
#include <fstream>
#include <string>
#include <iterator>
#include"CoreTask.h"

SpawnItem::SpawnItem()
{
	std::ifstream itempath("img/itempath.json");
	if (itempath.fail()) throw "itempath.json is not found.";//例外処理
	std::istreambuf_iterator<char> it(itempath);
	std::istreambuf_iterator<char> last;
	std::string str_json(it, last);		//string形式のjson
	std::string err;
	data = json11::Json::parse(str_json, err);//Jsonで使えるようにする
}

void SpawnItem::create(std::string)
{
}
