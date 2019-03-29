#pragma once
#include"json11.hpp"
#include"BasicList.h"
#include <iostream>
#include<memory>

class SpawnEnemy {
public:
	SpawnEnemy();
	void create(std::string stg);
	void destroy();
private:
	json11::Json data;

};