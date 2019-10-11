#include"Player.h"

Player::Player() {
	gh = LoadGraph("Resourse\\Image\\Player.png");
	GetGraphSize(gh, &width, &height);
	width *= 2, height *= 2;

	moveState = IDLE;
	space = 0;
	posX = 1200 / 2;
	posY = 800 / 2;
	gravity = 1;
	buoyancy = 1;
	vecY = 0;
	diveSpeed = 4;
	landingOnth = false;
}

void Player::Init() {

}

void Player::Move() {
	if (space > 0) {
		posY += diveSpeed;
		moveState = DIVE;
	}
	if (space < 0) {
		moveState = JUMP;
	}
	if (posY > 640 / 2) {
		if (moveState == JUMP) {
			if (landingOnth) {
				moveState = IDLE;
			}
			else {
				vecY -= buoyancy;
			}
		}
		if (moveState == IDLE) {
			if (landingOnth) {
				vecY -= diveSpeed / 2;
			}
		}
	}
	if (posY < 640 / 2) {
		if (moveState == JUMP) {
			vecY += gravity;
			landingOnth = true;
		}
		if (moveState == IDLE) {
			if (landingOnth) {
				landingOnth = false;
				vecY = 0;
			}
		}
	}
	//if (vecY > 1) {
	//	posY -= vecY;
	//	vecY -= gravity;
	//}
	
	/*if (posY < 640 / 2) {
		posY += gravity;
	}*/
	posY += vecY;
}

void Player::Draw() {
	DrawExtendGraph(posX, posY, posX + width, posY + height, gh, TRUE);
}

void Player::All() {
	PushSpace();
	Move();
	Draw();
}

void Player::PushSpace() {
	if (CheckHitKey(KEY_INPUT_SPACE) == 0) {
		// ������Ă��Ȃ�
		if (space > 0)
			space = -1; // �������u��
		else
			space = 0; // ����Ă���
	}
	else {
		space++; //������Ă���
	}
}