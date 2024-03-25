#include "PLAY.h"
#include "CONTAINER.h"

PLAY::PLAY(class GAME* game) :Scene(game)
{
}

PLAY::~PLAY()
{
}

void PLAY::draw()
{
	SetFontSize(Play.fontSize);
	DrawString(Play.pos.x, Play.pos.y, Play.text, Play.textColor);
}

void PLAY::create()
{
	Play = game()->container()->play();
}

void PLAY::nextScene()
{
	game()->changeScene(GAME::RESULT_ID);
}