#pragma once
#include"Dxlib.h"

extern int board[squaresSize][squaresSize];
extern int bufHandle[16];

enum StoneColor {

	None = 0,
	Black = -1,
	White = 1,
	Sentinel = 2,
};
/*
void initStone() {

	LoadDivGraph("reversi_stone_image.jpeg", 16, 4, 4, 80, 80, bufHandle);
	return;
}
*/

 void DrawStones(int except_row, int except_line) {

	for (int i = 0; i < squaresSize; i++) {
		for (int j = 0; j < squaresSize; j++) {

			if (i == except_row  && j == except_line ) {

				continue;
			}

			switch (board[i][j]) {

			case Black: {
				//DrawExtendGraph(StoneBasePositionX + j * DistanceOfStone, StoneBasePositionY + i * DistanceOfStone, 1000, 1000, bufHandle[6], false);
				//DrawGraph(StoneBasePositionX + j * DistanceOfStone, StoneBasePositionY + i * DistanceOfStone, bufHandle[6], true);
				DrawCircle(StoneBasePositionX + j * DistanceOfStone, StoneBasePositionY + i * DistanceOfStone, Radius, GetColor(0, 0, 0), true);
				break;
			}
			case White: {

				//DrawGraph(StoneBasePositionX + j * DistanceOfStone, StoneBasePositionY + i * DistanceOfStone, bufHandle[0], true);
				DrawCircle(StoneBasePositionX + j * DistanceOfStone, StoneBasePositionY + i * DistanceOfStone, Radius, GetColor(255, 255, 255), true);
				break;
			}
			default: break;

			}
		}
	}
	
	return;
}

void turnOver(int row, int line) {

	/*
	for (int i = 0; i < 13; i++) {

		DrawGraph(500, 500, bufHandle[i], true);
	}
	*/

	if (board[row][line] == White) {

		//Î‚ª•‚Ìê‡
		DrawBox(StoneBasePositionX + line * DistanceOfStone - StoneThick, StoneBasePositionY + row * DistanceOfStone - Radius,
			StoneBasePositionX + line * DistanceOfStone, StoneBasePositionY + row * DistanceOfStone + Radius, GetColor(0, 0, 0), true);
		DrawBox(StoneBasePositionX + line * DistanceOfStone, StoneBasePositionY + row * DistanceOfStone - Radius,
			StoneBasePositionX + line * DistanceOfStone + StoneThick, StoneBasePositionY + row * DistanceOfStone + Radius, GetColor(255, 255, 255), true);
	
	}
	else if (board[row][line] == Black) {

		//Î‚ª”’‚Ìê‡
		DrawBox(StoneBasePositionX + line * DistanceOfStone - StoneThick, StoneBasePositionY + row * DistanceOfStone - Radius,
			StoneBasePositionX + line * DistanceOfStone, StoneBasePositionY + row * DistanceOfStone + Radius, GetColor(255, 255, 255), true);
		DrawBox(StoneBasePositionX + line * DistanceOfStone, StoneBasePositionY + row * DistanceOfStone - Radius,
			StoneBasePositionX + line * DistanceOfStone + StoneThick, StoneBasePositionY + row * DistanceOfStone + Radius, GetColor(0, 0, 0), true);
	}

	ScreenFlip();
	WaitTimer(700);
	return;
}