#pragma once

#include"DxLib.h"
#include"Player.h"
#include"Background.h"

static const int Screen_Width = 1200;
static const int Screen_Height = 800;

class GameControl {
public:
	Player* pl;
	Background* bg;

	GameControl();
	~GameControl();
	void Game();
	void All();
};