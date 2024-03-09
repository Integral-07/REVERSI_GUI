#include "GAME.h"

#define GameWidth 1000
#define GameHeight 1000
#define GameTitle "title"
#define GameColor 32

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	ChangeWindowMode(TRUE);                         //�E�B���h�E���[�h�ɐݒ�
	SetOutApplicationLogValidFlag(FALSE);           //log.txt�̔�o��
	SetGraphMode(GameWidth, GameHeight, GameColor); //�𑜓x
	SetWindowSize(GameWidth, GameHeight);
	SetMainWindowText(GameTitle);
	SetAlwaysRunFlag(TRUE);

	//SetWindowIconID();
	if (DxLib_Init() == -1) {

		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK); //�_�u���o�b�t�@�����O
	SetBackgroundColor(100, 100, 100);

	Game game;
	game.run();

	DxLib_End();
	return 0;
}