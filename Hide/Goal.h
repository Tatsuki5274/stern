#pragma once
#include"Rendering.h"

class Goal : public Rendering{
public:
	Goal(Point point_);
	void init();//Init_Render���Ă�
	void update();
	bool hit(Point);
	void to_cleartask();
};