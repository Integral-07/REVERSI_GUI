#include "RESULT.h"
#include "CONTAINER.h"

RESULT::RESULT(class GAME* game) :Scene(game)
{
}

RESULT::~RESULT()
{
}

void RESULT::draw()
{
	SetFontSize(Result.fontSize);
	DrawString(Result.pos.x, Result.pos.y, Result.text, Result.textColor);
}

void RESULT::create()
{
	Result = game()->container()->result();
}

void RESULT::nextScene()
{
	game()->changeScene(GAME::TITLE_ID);
}
