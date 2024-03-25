#include "Scene.h"

Scene::Scene(class GAME* game):GAME_OBJECT(game)
{
}

Scene::~Scene()
{
}

void Scene::create()
{
}

void Scene::init()
{
}

void Scene::proc()
{
	update();
	draw();
	nextScene();
}

void Scene::update()
{
}

void Scene::draw()
{
}

void Scene::nextScene()
{
}
