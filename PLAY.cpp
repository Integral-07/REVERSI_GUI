#include "PLAY.h"

PLAY::PLAY(class Game* game) :Scene(game)
{
}

PLAY::~PLAY()
{
}

void PLAY::draw()
{
	SetFontSize(200);
	DrawString(0, 0, "Play", GetColor(255, 255, 255));
}

void PLAY::nextScene()
{
	game()->changeScene(Game::RESULT_ID);
}