#pragma once

enum class SceneType {
	title,
	stageselect,
	game,
	gameover,
	clear,
	pause
};

class Scene {
	static SceneType scene;
	void set_scene(SceneType type);
	SceneType get_scene();

};