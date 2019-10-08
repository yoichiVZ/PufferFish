#pragma once

#include"DxLib.h"
#include"Player.h"

class GameControl {
public:
	Player* pl;

	GameControl();
	~GameControl();
	void Game();
	void All();
};