#define DEBUG true

#include<list>
#include <string>
#include "DxLib.h"
#include "player.h"
#include "selector.h"
#include "setting.h"

int board[squaresSize][squaresSize] = { };

Players player("player1", "player2");


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

	ChangeWindowMode(TRUE); //�E�B���h�E���[�h�ɐݒ�
	SetOutApplicationLogValidFlag(FALSE);     //log.txt�̔�o��
	SetGraphMode(GameWidth, GameHeight, GameColor);
	SetWindowSize(GameWidth, GameHeight);
	SetMainWindowText(GameTitle);
	SetAlwaysRunFlag(TRUE);

	if (DxLib_Init() == -1) {

		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK); //�_�u���o�b�t�@�����O
	SetBackgroundColor(100, 100, 100);

	
	FrameArray fa;

	int resultArray[2] = { };
	int mouseX, mouseY;
	int previous_mouseX = 0, previous_mouseY = 0;

	KeyInit();
	initBoard();


	while (!isEnd()) {

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


		GetMousePoint(&mouseX, &mouseY);

		fa.DrawFrames(&mouseX, &mouseY, mouseX - previous_mouseX || mouseY - previous_mouseY);

		previous_mouseX = mouseX;
		previous_mouseY = mouseY;

		if (KeyDown(KEY_INPUT_UP)) {

			fa.move2upper();
			WaitTimer(KeyDownSpan);

		}
		if (KeyDown(KEY_INPUT_DOWN)) {

			fa.move2lower();
			WaitTimer(KeyDownSpan);

		}
		if (KeyDown(KEY_INPUT_LEFT)) {

			fa.move2left();
			WaitTimer(KeyDownSpan);
		}
		if (KeyDown(KEY_INPUT_RIGHT)) {

			fa.move2right();
			WaitTimer(KeyDownSpan);

		}
		if (KeyDown(MOUSE_INPUT_LEFT)) {


		}
		if (KeyClick(KEY_INPUT_RETURN)) {

			if (!isPlaceable(fa.getActiveRow(), fa.getActiveLine())) {

				KeyUpdate();
				continue;
			}

			putStone(fa.getActiveRow(), fa.getActiveLine());

			player.changePlayer();
			fa.resetActivation();
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

	//�ԕ�
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

				return false;
			}
		}
	}

	//�v���C���[����サ�Ď��s
	player.changePlayer();
	for (int i = 1; i < squaresSize - 1; i++) {
		for (int j = 1; j < squaresSize - 1; j++) {

			if (isPlaceable(i, j)) {

				//std::cout << "�u����ꏊ���Ȃ����߁A�v���[���[����サ�܂�." << std::endl;
				DrawString(0, 0, "�u����ꏊ���Ȃ����߁A�v���[���[����サ�܂�.", GetColor(0, 0, 0));

				return false;
			}
		}
	}

	return true;
}

void showBoard() {

	DrawBox(VisibleBoardPositionX-10, VisibleBoardPositionY-10, VisibleBoardEndX+10, VisibleBoardEndY+10, GetColor(0, 0, 0), true);     //��g
	DrawBox(VisibleBoardPositionX, VisibleBoardPositionY, VisibleBoardEndX, VisibleBoardEndY, GetColor(110, 224, 86), true);            //�Ζ�

	for (int i = 0; i < squaresSize; i++) {
		for (int j = 0; j < squaresSize; j++) {

			switch (board[i][j]) {

			case Black:
				//std::cout << "�Z";
				DrawCircle(StoneBasePositionX + j * DistanceOfStone, StoneBasePositionY + i * DistanceOfStone, Radius, GetColor(0, 0, 0), true);
				break;

			case White:
				//std::cout << " ��";
				DrawCircle(StoneBasePositionX + j * DistanceOfStone, StoneBasePositionY + i * DistanceOfStone, Radius,GetColor(255, 255, 255), true);
				break;

			case None:
				//std::cout << "�[";
				break;

			default:
				break;
			}
		}
		//std::cout << std::endl;
	}

	return;
}

void printPlayer() {

	switch (player.getCurrentPlayerStone()) {

	case Black:
		//std::cout << player.getCurrentPlayerName() << "(��)�̔�" << std::endl;
		DrawFormatString(0, 0, GetColor(0, 0, 0), "%s(��)�̔�", player.getCurrentPlayerName().c_str());
		break;

	case White:
		//std::cout << player.getCurrentPlayerName() << "(��)�̔�" << std::endl;
		DrawFormatString(0, 0, GetColor(0, 0, 0), "%s(��)�̔�", player.getCurrentPlayerName().c_str());
		break;
	}

	return;
}
bool isPlaceable(int _row, int _line) {

	if (board[_row][_line] == None) {
		//��ł���Ώ���

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
		//�����̐΂܂��͔ԕ��ł���ΏI��

		num++;
	}

	if (board[_row + dir_row * num][_line + dir_line * num] == player.getCurrentPlayerStone()) {
		//�ԕ��łȂ���Ύ����̐΂ł���A���߂�̂ŁA����̐΂̐���Ԃ�

		return num - 1;
	}

	return 0;
}


void putStone(int _row, int _line) {

	//�z�u�ӏ��̐΂̒u������
	board[_row][_line] = player.getCurrentPlayerStone();

	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {

			int numChange = checkDir(_row, _line, i, j);

			for (int k = 1; k < numChange + 1; k++) {
				//���߂�ӏ��̐΂̒u������

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

	//std::cout << "���ʔ��\�I�I\n" << "���(��): " << result[0] << "��\n" << "���(��):" << result[1] << "��\n" << std::endl;
	DrawString(0, 0, "���ʔ��\!!", GetColor(0, 0, 0));
	const char* text;

	if (result[0] < result[1]) {

		//std::cout << "���(��)�̏���" << std::endl;
		text = "���(��)�̏���";
	}
	else if (result[0] > result[1]) {

		//std::cout << "���(��)�̏���" << std::endl;
		text = "���(��)�̏���";
	}
	else {

		//std::cout << "��������" << std::endl;
		text = "��������";
	}

	DrawString(0, 0, text, GetColor(0, 0, 0));

	return;
}