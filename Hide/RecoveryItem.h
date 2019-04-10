#pragma once
#include"Item.h"

class RecoveryItem : public Item {
public:
	RecoveryItem(Point);
	void update();
private:
	void efficacy();
};