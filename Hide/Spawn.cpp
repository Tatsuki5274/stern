#include "Spawn.h"


Spawn::Spawn(std::string fpath)
{
	std::ifstream path(fpath);
	if (path.fail()) throw "json file is not found.";//—áŠOˆ—
	std::istreambuf_iterator<char> it(path);
	std::istreambuf_iterator<char> last;
	std::string str_json(it, last);		//stringŒ`®‚Ìjson
	std::string err;
	data = json11::Json::parse(str_json, err);//Json‚Åg‚¦‚é‚æ‚¤‚É‚·‚é
}
