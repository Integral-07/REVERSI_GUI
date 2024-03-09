#include "TITLE.h"
#include "CONTAINER.h"

TITLE::TITLE(class Game* game):Scene(game)
{
}

TITLE::~TITLE()
{
}

void TITLE::create()
{
	Title = game()->container()->title();
}

void TITLE::draw()
{
	SetFontSize(Title.fontSize);
	DrawString(Title.pos.x, Title.pos.y, Title.text, Title.textColor);
}

void TITLE::nextScene()
{
	game()->changeScene(Game::PLAY_ID);
}
