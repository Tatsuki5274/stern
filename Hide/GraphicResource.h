#pragma once
#include <iostream>
#include <memory>
#include "GraphicState.h"
#include "json11.hpp"

struct GraphicObject {
	//画像の実体を管理する
	GraphicObject();
	bool exist;
	bool loop;	//ループの有無
	std::string name, path;
	int* handle;
	int width, height, line, column, speed, sheets;
	int max;	//最大枚数
	int rate;	//切替速度
	void set_default_to_empty();
};

class GraphicResource
{
public:
	//メソッド
	GraphicResource();
	~GraphicResource();
	bool load(std::string _scope);
	GraphicObject get(std::string name);
private:
	//メソッド
	int get_index(std::string);
	bool exist_name(std::string);
	void register_graph(json11::Json);

	//プロパティ
	json11::Json json;
	//std::unique_ptr<GraphicObject[]> graph;
	std::vector<GraphicObject> graph;
};