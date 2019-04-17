#pragma once
#include <iostream>
#include <memory>
#include "GraphicState.h"
#include "json11.hpp"

class GraphicObject {
private:
	friend class GraphicResource;
	bool exist;
	std::string path;	//ファイルパス
	std::vector<std::string> scopes;
	void set_default_to_empty();	//オブジェクトにデフォルト値を設定する
	bool exits_scope(std::string);	//スコープが存在しているか調べる
public:
	~GraphicObject();
	bool loop;	//ループの有無
	std::string name;
	int *handle;
	int width, height, line, column, speed, sheets;
	int max;	//最大枚数
};

class GraphicResource
{
public:
	//メソッド
	GraphicResource();
	~GraphicResource();
	int load(std::string _scope);
	GraphicObject get(std::string name);
private:
	//メソッド
	bool exist_name(std::string);
	void register_graph(json11::Json);

	//プロパティ
	std::vector<GraphicObject> graph;
};