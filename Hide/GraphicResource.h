﻿#pragma once
#include <iostream>
#include <memory>
#include "GraphicState.h"
#include "json11.hpp"

struct GraphicObject {
	std::string name;
	int* handle;
	int max;
};

class GraphicResource
{
public:

	GraphicResource();
	~GraphicResource();
	bool load(std::string);
	GraphicObject get(std::string);
private:
	int get_index(std::string);
	json11::Json json;

	int count_of_graph;	//画像枚数
	std::unique_ptr<GraphicObject[]> graph;
};