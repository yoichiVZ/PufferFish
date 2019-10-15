#pragma once

#include"DxLib.h"

class Background {
private:
	int seaGh, seaCoverGh; //グラフィックハンドル格納
	int posX, posY; //海の位置
	int seaWidth, seaHeight, seaCoverWidth, seaCoverHeight; //海の幅
	int scrollSpeed; //スクロールスピード
public:
	Background();
	void SeaDraw();
	void SeaCoverDraw();
	void Move(bool);
};