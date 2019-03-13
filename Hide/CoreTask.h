#pragma once
#include<memory>
#include"GameTaskSystem.h"
#include"TitleTaskSystem.h"
#include"Keyboard.h"

class CoreTask {
private:
public:
	enum Scene {
		title,
		stageselect,
		game,
		gameover,
		clear
	};
	Scene scene;//どのシーンからでも変えられるように

	CoreTask();
	void update();
	std::unique_ptr<GameTaskSystem> gts;
	std::unique_ptr<TitleTaskSystem> tts;
	std::unique_ptr<Keyboard> keyboard;
};

extern CoreTask *ct;