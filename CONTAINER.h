#pragma once
#include "TITLE.h"
#include "PLAY.h"
#include "RESULT.h"

class CONTAINER
{
	struct DATA{

		TITLE::DATA title;
		PLAY::DATA play;
		RESULT::DATA result;
	};

	DATA Data;

public:

	void load();
	void setData();
	TITLE::DATA& title() { return Data.title; }
	PLAY::DATA& play() { return Data.play; }
	RESULT::DATA& result() { return Data.result; }
};

