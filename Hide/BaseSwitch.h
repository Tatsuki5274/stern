#pragma once
#include"BasicObject.h"

//----------------------------------
//�X�C�b�`�̃x�[�X
//----------------------------------

class BasicSwitch : public BasicObject {
public:
	BasicSwitch() :
		status(false)
	{}
	//���\�b�h
	void Switch();
protected:
	//�ϐ�
	bool status;//������Ă��邩�̔���?
};