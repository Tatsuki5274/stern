#include "BasicObject.h"

//-----------------------------------
//��{�ƂȂ�N���X
//-----------------------------------

BasicObject::BasicObject() {
	velocityX = 0;
	velocityY = 0;
}

void BasicObject::update()
{
}

Point BasicObject::get_point()
{
	return point;
}
