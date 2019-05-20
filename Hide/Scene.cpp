#include "Scene.h"

void Scene::set_scene(SceneType type)
{
	scene = type;
}

SceneType Scene::get_scene() {
	return scene;
}