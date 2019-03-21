#pragma once
#include"TitleStartButton.h"
#include"TitleSelecter.h"
#include"TitleExitButton.h"
#include<memory>

class TitleTaskSystem {
private:
	int backgraph;
public:
	TitleTaskSystem();
	void update();
	void draw();
	std::unique_ptr<TitleSelecter> selecter;
	std::unique_ptr<TitleStartButton> startbutton;
	std::unique_ptr<TitleExitButton> exitbutton;
};