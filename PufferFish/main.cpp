#include"DxLib.h"
#include"GameControl.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(TRUE);
	SetGraphMode(Screen_Width, Screen_Height, 32);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	GameControl* gc = new GameControl();

	while (ProcessMessage() != -1) {
		int startTime = GetNowCount();
		ScreenFlip();
		ClearDrawScreen();

		gc->All();

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)break;
		int endTime = GetNowCount();
		WaitTimer((1000 / 60) - (endTime - startTime));
	}

	delete gc;

	DxLib_End();
	return 0;
}