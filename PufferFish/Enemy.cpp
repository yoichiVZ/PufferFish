#include"Enemy.h"

Enemy::Enemy() {
	gh = LoadGraph("Resourse\\Image\\enemy2.png");
	GetGraphSize(gh, &width, &height);
	width *= 2, height *= 2;

	posX = 1200;
	posY = 700;
	speed = 2;
}

void Enemy::Init() {

}

void Enemy::Move() {
	posX -= speed;
	if (posX <= -70)
		posX = 1200;
}

void Enemy::Draw() {
	DrawExtendGraph(posX, posY, posX + width, posY + height, gh, TRUE);
}

void Enemy::All() {
	Draw();
	Move();
}

int Enemy::GetPosX() {
	return posX;
}

int Enemy::GetPosY() {
	return posY;
}

int Enemy::GetWidth() {
	return width;
}

int Enemy::GetHeight() {
	return height;
}