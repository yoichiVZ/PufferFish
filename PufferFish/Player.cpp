#include"Player.h"

Player::Player() {
	gh = LoadGraph("Resourse\\Image\\Player.png");
	GetGraphSize(gh, &width, &height);
	width *= 2, height *= 2;

	moveState = IDLE;
	space = 0;
	posX = 400 - (width / 2);
	posY = 400 - (height / 2);
	gravity = 1;
	buoyancy = 1;
	vecY = 0;
	diveSpeed = 4;
	landingOnth = false;
	life = 3;
	diveStart = 0;
	dash = false;

	flashCount = 0;
	flashFlag = false;
	mutekiCount = 0;
	mutekiFlag = false;
}

void Player::Init() {
	posY = 0;
}

void Player::Move() {
	if (space > 0 && diveStart > UNTIL_STATRT) {
		posY += diveSpeed;
		moveState = DIVE;
	}
	if (space < 0 && diveStart > UNTIL_STATRT) {
		moveState = JUMP;
	}
	if (posY > 800 / 2) {
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
	if (posY < 800 / 2) {
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
	posY += vecY;
}

void Player::Draw() {
	if (flashFlag) {
		if (flashCount % 10 == 0 || flashCount % 10 == 5)
			return;
	}
	DrawExtendGraph(posX, posY, posX + width, posY + height, gh, TRUE);
}

void Player::All() {
	PushSpace();
	Move();
	Draw();

	if (flashCount < 60) {
		flashCount++;
	}
	else {
		flashFlag = false;
	}
	if (mutekiFlag) {
  		if (mutekiCount > 60) {
			mutekiFlag = false;
			mutekiCount = 0;
		}
		mutekiCount++;
	}
}

void Player::PushSpace() {
	if (CheckHitKey(KEY_INPUT_SPACE) == 0) {
		// âüÇ≥ÇÍÇƒÇ¢Ç»Ç¢
		if (space > 0) {
			space = -1; // ó£ÇµÇΩèuä‘
			if (diveStart <= UNTIL_STATRT)
				dash = true;
		}
		else {
			space = 0; // ó£ÇÍÇƒÇ¢ÇÈ
			diveStart = 0;
			dash = false;
		}
	}
	else {
		space++; //âüÇ≥ÇÍÇƒÇ¢ÇÈ
		diveStart++;
	}
}

int Player::GetPosX() {
	return posX;
}

int Player::GetPosY() {
	return posY;
}

int Player::GetWidth() {
	return width;
}

int Player::GetHeight() {
	return height;
}

bool Player::Damage() {
	if (life > 0)
		life -= 1;
	if (life <= 0)
		return true;
	return false;
}

bool Player::IsDash() {
	return dash;
}

void Player::FlashFlagOn() {
	flashFlag = true;
	flashCount = 0;
}

void Player::MutekiOn() {
	mutekiFlag = true;
}

bool Player::MutekiNow() {
	return mutekiFlag;
}