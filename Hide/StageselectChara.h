#pragma once
#include"BasicObject.h"

//�L�����N�^�[
class StageSelectChara : public BasicObject {
private:
	int graph;
public:
	StageSelectChara();
	void update(int&);
	void draw();
	void select_stage(int&);
	void move();
	int get_velocity();
};