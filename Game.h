#pragma once
#include "Dxlib.h"
#include "VECTOR2.h"

class Game {

//container
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }

public:
	enum SCENE_ID{

		TITLE_ID,
		PLAY_ID,
		RESULT_ID,
		NUM_SCENES
	};
private:
	class Scene* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;

public:
	Game();
	~Game();

	void run();

	void changeScene(SCENE_ID sceneId);
};