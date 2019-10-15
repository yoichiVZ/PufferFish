#include"GameControl.h"

GameControl::GameControl() {
	pl = new Player();
	en = new Enemy();
	bg = new Background();
}

GameControl::~GameControl() {
	delete pl;
	delete en;
	delete bg;
}

void GameControl::Game() {
	bg->SeaDraw();
	en->All();
	pl->All();
	bg->SeaCoverDraw();
	bg->Move();

	//当たり判定
	//プレイヤーとエネミー
	if (pl->GetPosX() > en->GetPosX() &&
		pl->GetPosX() < en->GetPosX() + en->GetWidth() &&
		pl->GetPosY() > en->GetPosY() &&
		pl->GetPosY() < en->GetPosY() + en->GetHeight()) {
		if (pl->Damage())
			pl->Init();
	}
	if (pl->GetPosX() + pl->GetWidth() > en->GetPosX() &&
		pl->GetPosX() + pl->GetWidth() < en->GetPosX() + en->GetWidth() &&
		pl->GetPosY() > en->GetPosY() &&
		pl->GetPosY() < en->GetPosY() + en->GetHeight()) {
		if (pl->Damage())
			pl->Init();
	}
	if (pl->GetPosX() > en->GetPosX() &&
		pl->GetPosX() < en->GetPosX() + en->GetWidth() &&
		pl->GetPosY() + pl->GetHeight() > en->GetPosY() &&
		pl->GetPosY() + pl->GetHeight() < en->GetPosY() + en->GetHeight()) {
		if (pl->Damage())
			pl->Init();
	}
	if (pl->GetPosX() + pl->GetWidth() > en->GetPosX() &&
		pl->GetPosX() + pl->GetWidth() < en->GetPosX() + en->GetWidth() &&
		pl->GetPosY() + pl->GetHeight() > en->GetPosY() &&
		pl->GetPosY() + pl->GetHeight() < en->GetPosY() + en->GetHeight()) {
		if (pl->Damage())
			pl->Init();
	}
}

void GameControl::All() {
	Game();
}