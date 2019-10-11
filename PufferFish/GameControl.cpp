#include"GameControl.h"

GameControl::GameControl() {
	pl = new Player();
	bg = new Background();
}

GameControl::~GameControl() {
	delete pl;
	delete bg;
}

void GameControl::Game() {
	bg->SeaDraw();
	pl->All();
	bg->SeaCoverDraw();
	bg->Move();
}

void GameControl::All() {
	Game();
}