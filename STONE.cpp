#include "STONE.h"

STONE::STONE(GAME* game)
	:ACTOR(game)
{
}

void STONE::draw()
{
	//�`�揈��

	DrawCircle(0,0,2,GetColor(0,0,0));
}

void STONE::proc()
{
	//update����
}
