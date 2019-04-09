#pragma once
#include"Rendering.h"

enum class Kind {
	recovery,
	powerup
};

class Item : Rendering {
private:
	Kind kind;
	void efficacy(Point, int&,int&);
	bool checkhit(Point);
public:
	Item(Point,Kind);
	void update(Point,int&,int&);
};