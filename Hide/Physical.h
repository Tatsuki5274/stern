#pragma once
#include"BasicObject.h"

//---------------------------------
//�����^��
//---------------------------------

class Physical : public BasicObject {
public:
	Physical() :
		gravity(0),
		repulsion(0),
		weight(0)
	{}
	//���\�b�h
	//float Gravity(float gra_);
private:
	//�ϐ�
	float gravity;//�d��
	float repulsion;//�����W��
	int weight;//�d��(����)

};
