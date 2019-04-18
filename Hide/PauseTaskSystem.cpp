#include "PauseTaskSystem.h"
#include"DxLib.h"
#include"CoreTask.h"

PauseTask::PauseTask()
{
	p_selecter = std::make_unique<PauseSelecter>();
	p_ui = std::make_unique<PauseUI>();
	feedcnt = 255;
	backgraph = LoadGraph("img/pause.png");
}

void PauseTask::update()
{
	p_selecter->update(1,1,1);
	p_ui->update();
	if (ct->keyboard->key_down(KEY_INPUT_X)) {
		//audio->play("決定");
		while(feedcnt>0){
			feedcnt--;
			SetDrawBright(feedcnt,feedcnt,feedcnt);
			if (feedcnt < 0) {
				feedcnt = 255;
				SetDrawBright(feedcnt, feedcnt, feedcnt);
				change_scene();
				break;
			}
		}
	}

	change_scene();
	draw();
}

void PauseTask::draw()
{
	DrawGraph(0, 0, backgraph, FALSE);//背景
}

void PauseTask::change_scene()
{
		//ゲームに戻る
		switch (p_selecter->button) {
		case PauseButton::returngame:
			ct->scene = Scene::game;
			break;
		case PauseButton::exit:
			//アプリケーション終了
			break;
		case PauseButton::backssts:
			ct->scene = Scene::stageselect;
			break;
		}
}
