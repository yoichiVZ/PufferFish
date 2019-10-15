#pragma once

#include"DxLib.h"
#include"Player.h"
#include"Enemy.h"
#include"Background.h"
#include"Coin.h"

static const int Screen_Width = 1200;
static const int Screen_Height = 800;

class GameControl {
private:
	int gameTime;

	Player* pl;
	Enemy* en[ENEMY_NUM];
	Background* bg;
	Coin* coin[COIN_NUM];
public:
	GameControl();
	~GameControl();
	void Game();
	void All();
};