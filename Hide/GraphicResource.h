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
	int line, column;
	void set_default_to_empty();	//オブジェクトにデフォルト値を設定する
	bool exits_scope(std::string);	//スコープが存在しているか調べる
public:
	bool loop;	//ループの有無
	std::string name;
	int *handle;
	int width, height,  speed, sheets;
	//int max;	//最大枚数
};

class GraphicResource
{
public:
	static int load(std::string _scope);
	static void init();
	static std::shared_ptr<GraphicObject> get(std::string name);	//nameを持つオブジェクトポインタを返す
private:
	GraphicResource();
	static bool exist_name(std::string);		//名前が存在しているか調べる
	static bool register_graph(std::vector<std::shared_ptr<GraphicObject>>::iterator);	//画像を登録する

	static std::vector<std::shared_ptr<GraphicObject>> graph;	//画像データなどを保持するオブジェクト
};