#pragma once
#include"BasicObject.h"

class Rendering : public BasicObject {
public:
	Rendering() {
		
	}
	//�A�j���[�V������؂�ւ���
	bool switch_anime();
	void draw();
protected:
	int cnt;//�����ڂɂ��邩
	bool loop;//���[�v���邩
	int graph;
};