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
	bool exist_name(std::string);		//名前が存在しているか調べる
	bool register_graph(std::vector<GraphicObject>::iterator);	//画像を登録する

	std::vector<GraphicObject> graph;	//画像データなどを保持するオブジェクト
};