#pragma once
#include"BasicObject.h"

//----------------------------------
//�X�C�b�`�̃x�[�X
//----------------------------------

class BasicSwitch : public BasicObject {
public:
	BasicSwitch(Point);
	//���\�b�h
	void Switch();
protected:
	//�ϐ�
	bool status;//������Ă��邩�̔���?
};