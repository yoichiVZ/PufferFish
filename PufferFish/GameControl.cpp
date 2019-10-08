#include"GameControl.h"

GameControl::GameControl() {
	pl = new Player();
}

GameControl::~GameControl() {
	delete pl;
}

void GameControl::Game() {
	pl->All();
}

void GameControl::All() {
	Game();
}