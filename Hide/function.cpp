﻿#include"Function.h"
bool Function::CheckHit(Point attack_, Point defense_) {
	if (attack_.x <= defense_.x + defense_.w
		&&defense_.x <= attack_.x + attack_.w
		&&attack_.y <= defense_.y + defense_.h
		&&defense_.y <= attack_.y + attack_.h){
		return true;
	}
	else {
		return false;
	}
}

int Function::Attack(int damege) {
	return 0;//未実装
}

