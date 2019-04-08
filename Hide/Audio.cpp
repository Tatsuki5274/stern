#include "Audio.h"
#include<fstream>
#include<memory>
#include"DxLib.h"

Audio::Audio()
{
	std::ifstream audiopath("img/audiosource.json");
	if (audiopath.fail()) throw "resource.json is not found.";//��O����
	std::istreambuf_iterator<char> it(audiopath);
	std::istreambuf_iterator<char> last;
	std::string str_json(it, last);	//string�`����json
	std::string err;
	json = json11::Json::parse(str_json, err);//Json�Ŏg����悤�ɂ���
	for (auto &item : json["audio"].array_items()) {
		count_size++;//�ő吔�𐔂���
	}
	audio = std::make_unique<AudioObject[]>(count_size);//�������m��
}

Audio::~Audio()
{
	for (int i = 0; i < count_size; ++i) {
		DeleteSoundMem(audio[i].handle);
	}
}

void Audio::play(std::string name)
{
	for (int i = 0; i < count_size; ++i) {
		if (audio[i].name == name) {
			int playtype;
			if (audio[i].loop) playtype = DX_PLAYTYPE_LOOP;
			else playtype = DX_PLAYTYPE_BACK;
			PlaySoundMem(audio[i].handle, playtype);
		}
	}
}

void Audio::load()
{
	for (int i = 0; i < count_size; ++i) {
		for (auto &audiosource : json["audio"].array_items())
		{
			audio[i].name = audiosource["name"].string_value();//���O
			audio[i].loop = audiosource["loop"].bool_value();//���[�v�Đ����s����
			audio[i].path = audiosource["path"].string_value();

			audio[i].handle = LoadSoundMem(audio[i].path.c_str());
			break;
		}
	}
}
