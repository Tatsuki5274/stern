#pragma once
#include"BasicObject.h"

enum class Kind {
	recovery,
	powerup
};

class Item : public BasicObject {
protected:
	Kind kind;
	virtual void efficacy() = 0;//���ۂƂȂ�
	bool checkhit(Point);
public:
	void update() final;
	Item(Point);
};