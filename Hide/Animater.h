#pragma once
#include"BasicObject.h"

class Animater : public BasicObject {
public:
	Animater() {
		cnt = 0;
		limit = 0;
		//state st;
	}
	//�A�j���[�V������؂�ւ���
	void Switch_anime();
protected:
	int cnt;//���t���[����ɉ摜��؂�ւ��邩
	int limit;//�ő�R�}��

	enum class state{

	};

};