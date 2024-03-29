#define DEBUG true

#include <string>
#include "DxLib.h"
#include "player.h"
#include "selector.h"
#include "setting.h"

int board[squaresSize][squaresSize] = { };

Players player("player1", "player2");
Selector slc(VisibleBoardPositionX, VisibleBoardPositionY, GetColor(200, 200, 200));


void initBoard();
bool isEnd();
void showBoard();
void printPlayer();
bool isPlaceable(int, int);
int checkDir(int, int, int, int);
void putStone(int, int);
void totalingStone(int*);
void printResult(int*);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	ChangeWindowMode(TRUE); //ウィンドウモードに設定
	SetOutApplicationLogValidFlag(FALSE);     //log.txtの非出力
	SetGraphMode(GameWidth, GameHeight, GameColor);
	SetWindowSize(GameWidth, GameHeight);
	SetMainWindowText(GameTitle);
	SetAlwaysRunFlag(TRUE);

	if (DxLib_Init() == -1) {

		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK); //ダブルバッファリング
	SetBackgroundColor(100, 100, 100);

	int resultArray[2] = { };
	int mouseX, mouseY;

	KeyInit();
	initBoard();


	while (isEnd()) {

		if (ProcessMessage() != 0) {
			break;
		}
		if (ClearDrawScreen() != 0) {
			break;
		}

		if (KeyDown(KEY_INPUT_ESCAPE)) {

			break;
		}

		printPlayer();
		showBoard();
		slc.DrawFrame();

		if (DEBUG) {

			slc.DebugMonitor();
		}

		GetMousePoint(&mouseX, &mouseY);
		if (VisibleBoardPositionX <= mouseX && mouseX <= VisibleBoardEndX && VisibleBoardPositionY <= mouseY && mouseY <= VisibleBoardEndY) {
			//処理範囲内

			slc.setPosition(mouseX, mouseY);
		}

		if (KeyDown(KEY_INPUT_UP)) {

			slc.move2upper();
			WaitTimer(KeyDownSpan);

		}
		if (KeyDown(KEY_INPUT_DOWN)) {

			slc.move2lower();
			WaitTimer(KeyDownSpan);

		}
		if (KeyDown(KEY_INPUT_LEFT)) {

			slc.move2left();
			WaitTimer(KeyDownSpan);
		}
		if (KeyDown(KEY_INPUT_RIGHT)) {

			slc.move2right();
			WaitTimer(KeyDownSpan);

		}
		if (KeyDown(MOUSE_INPUT_LEFT)) {


		}
		if (KeyDown(KEY_INPUT_RETURN)) {

			if (!isPlaceable(slc.getRow(), slc.getLine())) {

				continue;
			}

			putStone(slc.getRow(), slc.getLine());

			player.changePlayer();
			slc.resetPosition();
		}

		KeyUpdate();

		ScreenFlip();
	}

	showBoard();

	totalingStone(resultArray);
	printResult(resultArray);

	DxLib_End();

	return 0;
}

void initBoard() {

	int initBasePosition = squaresSize / 2;

	board[initBasePosition][initBasePosition] = White;
	board[initBasePosition - 1][initBasePosition - 1] = White;
	board[initBasePosition][initBasePosition - 1] = Black;
	board[initBasePosition - 1][initBasePosition] = Black;

	//番兵
	for (int i = 0; i < squaresSize; i++) {

		board[0][i] = Sentinel;
		board[i][0] = Sentinel;
		board[squaresSize - 1][i] = Sentinel;
		board[i][squaresSize - 1] = Sentinel;
	}

	return;
}


bool isEnd() {

	for (int i = 1; i < squaresSize - 1;i++) {
		for (int j = 1;j < squaresSize - 1;j++) {

			if (isPlaceable(i, j)) {

				return true;
			}
		}
	}

	//プレイヤーを交代して試行
	player.changePlayer();
	for (int i = 1; i < squaresSize - 1; i++) {
		for (int j = 1; j < squaresSize - 1; j++) {

			if (isPlaceable(i, j)) {

				//std::cout << "置ける場所がないため、プレーヤーを交代します." << std::endl;
				DrawString(0, 0, "置ける場所がないため、プレーヤーを交代します.", GetColor(0, 0, 0));

				return true;
			}
		}
	}

	return false;
}

void showBoard() {

	DrawBox(VisibleBoardPositionX, VisibleBoardPositionY, VisibleBoardEndX, VisibleBoardEndY, GetColor(110, 224, 86), true); //緑面
	DrawBox(VisibleBoardPositionX, VisibleBoardPositionY, VisibleBoardEndX, VisibleBoardEndY, GetColor(0, 0, 0), false); //大枠

	for (int i = 0; i < squaresSize; i++) {

		for (int j = 0; j < squaresSize; j++) {


			switch (board[i][j]) {

			case Black:
				//std::cout << "〇";
				DrawBox(BoardBasePositionX + j * DistanceOfStone, BoardBasePositionY + i * DistanceOfStone,
					BoardBasePositionX + j * DistanceOfStone + DistanceOfStone, BoardBasePositionY + i * DistanceOfStone + DistanceOfStone, GetColor(0, 0, 0), false); //黒枠描画
				DrawCircle(StoneBasePositionX + j * DistanceOfStone, StoneBasePositionY + i * DistanceOfStone, GetColor(0, 0, 0), true);
				break;

			case White:
				//std::cout << " ●";
				DrawBox(BoardBasePositionX + j * DistanceOfStone, BoardBasePositionY + i * DistanceOfStone,
					BoardBasePositionX + j * DistanceOfStone + DistanceOfStone, BoardBasePositionY + i * DistanceOfStone + DistanceOfStone, GetColor(0, 0, 0), false); //黒枠描画
				DrawCircle(StoneBasePositionX + j * DistanceOfStone, StoneBasePositionY + i * DistanceOfStone, GetColor(255, 255, 255), true);
				break;

			case None:
				//std::cout << "ー";
				DrawBox(BoardBasePositionX + j * DistanceOfStone, BoardBasePositionY + i * DistanceOfStone,
					BoardBasePositionX + j * DistanceOfStone + DistanceOfStone, BoardBasePositionY + i * DistanceOfStone + DistanceOfStone, GetColor(0, 0, 0), false); //黒枠描画
				break;

			default:
				//std::cout << "ば";
				if (DEBUG) {

					DrawBox(BoardBasePositionX + j * DistanceOfStone, BoardBasePositionY + i * DistanceOfStone,
						BoardBasePositionX + j * DistanceOfStone + DistanceOfStone, BoardBasePositionY + i * DistanceOfStone + DistanceOfStone, GetColor(100, 100, 100), true); //黒枠描画
				}
				break;
			}
		}
		//std::cout << std::endl;
	}

	return;
}

void printPlayer() {

	const char* text;

	switch (player.getCurrentPlayerStone()) {

	case Black:
		//std::cout << player.getCurrentPlayerName() << "(黒)の番" << std::endl;
		text = (player.getCurrentPlayerName() + "(黒)の番").c_str();
		DrawString(0, 0, text, GetColor(0, 0, 0));
		break;

	case White:
		//std::cout << player.getCurrentPlayerName() << "(白)の番" << std::endl;
		text = (player.getCurrentPlayerName() + "(白)の番").c_str();
		DrawString(0, 0, text, GetColor(0, 0, 0));
		break;
	}

	return;
}
bool isPlaceable(int _row, int _line) {

	if (board[_row][_line] == None) {
		//空であれば処理

		for (int dir_row = -1; dir_row < 2; dir_row++) {
			for (int dir_line = -1; dir_line < 2; dir_line++) {

				if (checkDir(_row, _line, dir_row, dir_line)) {

					return true;
				}

			}
		}
	}

	return false;
}

int checkDir(int _row, int _line, int dir_row, int dir_line) {

	int num = 1;
	while (board[_row + dir_row * num][_line + dir_line * num] == player.getConfStn()) {
		//自分の石または番兵であれば終了

		num++;
	}

	if (board[_row + dir_row * num][_line + dir_line * num] == player.getCurrentPlayerStone()) {
		//番兵でなければ自分の石であり、挟めるので、相手の石の数を返す

		return num - 1;
	}

	return 0;
}


void putStone(int _row, int _line) {

	//配置箇所の石の置き換え
	board[_row][_line] = player.getCurrentPlayerStone();

	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {

			int numChange = checkDir(_row, _line, i, j);

			for (int k = 1; k < numChange + 1; k++) {
				//挟める箇所の石の置き換え

				board[_row + i * k][_line + j * k] = player.getCurrentPlayerStone();
			}
		}
	}

	return;
}

void  totalingStone(int* result) {

	int countBlackStone = 0;
	int countWhiteStone = 0;

	for (int i = 1; i < squaresSize - 1; i++) {
		for (int j = 1; j < squaresSize - 1; j++) {

			if (board[i][j] == Black) {

				countBlackStone++;
			}
			else if (board[i][j] == White) {

				countWhiteStone++;
			}
		}
	}

	result[0] = countBlackStone;
	result[1] = countWhiteStone;

	return;
}


void printResult(int* result) {

	/*
	for (int i = 0; i < boardSize; i++) {

		std::cout << "--";
	}
	*/
	//std::cout << std::endl;

	//std::cout << "結果発表！！\n" << "先手(黒): " << result[0] << "枚\n" << "後手(白):" << result[1] << "枚\n" << std::endl;
	DrawString(0, 0, "結果発表!!", GetColor(0, 0, 0));
	const char* text;

	if (result[0] < result[1]) {

		//std::cout << "先手(黒)の勝ち" << std::endl;
		text = "先手(黒)の勝ち";
	}
	else if (result[0] > result[1]) {

		//std::cout << "後手(白)の勝ち" << std::endl;
		text = "後手(白)の勝ち";
	}
	else {

		//std::cout << "引き分け" << std::endl;
		text = "引き分け";
	}

	DrawString(0, 0, text, GetColor(0, 0, 0));

	return;
}