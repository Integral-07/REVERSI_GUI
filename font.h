#pragma once
#include "Dxlib.h"

int Fonts[10];

void SetFonts() {

	Fonts[0] = CreateFontToHandle("���C���I", 70, 5, DX_FONTTYPE_ANTIALIASING_EDGE);
}