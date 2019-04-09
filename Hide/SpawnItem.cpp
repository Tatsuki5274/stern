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
	if (itempath.fail()) throw "itempath.json is not found.";//—áŠOˆ—
	std::istreambuf_iterator<char> it(itempath);
	std::istreambuf_iterator<char> last;
	std::string str_json(it, last);		//stringŒ`®‚Ìjson
	std::string err;
	data = json11::Json::parse(str_json, err);//Json‚Åg‚¦‚é‚æ‚¤‚É‚·‚é
}

void SpawnItem::create(std::string)
{
}
