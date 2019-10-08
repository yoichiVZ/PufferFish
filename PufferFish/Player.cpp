#include"Player.h"

Player::Player() {
	gh = LoadGraph("Resourse\\enemy2.png");
	GetGraphSize(gh, &width, &height);

	posX = 860 / 2;
	posY = 640 / 2;
	gravity = 2;
	buoyancy = 0.5;
	vecY = 1;
}

void Player::Init() {

}

void Player::Move() {
	if (CheckHitKey(KEY_INPUT_SPACE) == 1) {
		posY += vecY;
	}
	else if (posY > 640 / 2) {
		posY -= vecY;
		vecY += buoyancy;
	}
	else if (vecY > 1) {
		posY -= vecY;
		vecY -= gravity;
	}
	
	/*if (posY < 640 / 2) {
		posY += gravity;
	}*/
}

void Player::Draw() {
	DrawExtendGraph(posX, posY, posX + width, posY + height, gh, TRUE);
}

void Player::All() {
	Move();
	Draw();
}