#include "RESULT.h"

RESULT::RESULT(class Game* game) :Scene(game)
{
}

RESULT::~RESULT()
{
}

void RESULT::draw()
{
	SetFontSize(200);
	DrawString(0, 0, "Result", GetColor(255, 255, 255));
}

void RESULT::nextScene()
{
	game()->changeScene(Game::TITLE_ID);
}
