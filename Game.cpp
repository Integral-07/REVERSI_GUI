#include "Game.h"
#include "TITLE.h"
#include "PLAY.h"
#include "RESULT.h"
#include "key.h"
#include "CONTAINER.h"


Game::Game()
{
	Container = new CONTAINER;
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[PLAY_ID] = new PLAY(this);
	Scenes[RESULT_ID] = new RESULT(this);
	CurSceneId = TITLE_ID;
}

Game::~Game()
{
	for (int i = 0; i < NUM_SCENES; i++) {

		delete Scenes[i];
	}
}

void Game::run()
{
	Container->load();
	Scenes[TITLE_ID]->create();

	while (ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		Scenes[CurSceneId]->proc();
		ScreenFlip();

		KeyUpdate();
	}
}

void Game::changeScene(SCENE_ID sceneId)
{
	if (KeyClick(KEY_INPUT_A)) {

		CurSceneId = sceneId;
	}
}
