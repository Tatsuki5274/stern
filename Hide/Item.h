#pragma once
#include"Rendering.h"

enum class Kind {
	recovery,
	powerup
};

class Item : public Rendering {
protected:
	Kind kind;
	virtual void efficacy();
	bool checkhit(Point);
public:
	void update();
	Item(Point);
};