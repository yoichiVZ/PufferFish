#include"Coin.h"

Coin::Coin() {
	gh = LoadGraph("Resourse\\Image\\enemy3bulett.png");
	GetGraphSize(gh, &width, &height);
	width *= 2, height *= 2;

	spawnTiming1[0] = 0;
	spawnTiming5[0] = 0;
	spawnTiming8[0] = 0;
	spawnTiming6[0] = 60;
	spawnTiming4[0] = 120;
	spawnTiming4[1] = 180;
	spawnTiming4[2] = 240;

	posX = 0;
	posY = 0;
	speed = 2;
	live = false;
}

void Coin::Move() {
	posX -= speed;
	if (posX < -50)
		live = false;
}

void Coin::Draw() {
	DrawExtendGraph(posX, posY, posX + width, posY + height, gh, TRUE);
}

void Coin::All() {
	if (!live)return;
	Draw();
	Move();
}

int Coin::GetPosX() {
	return posX;
}

int Coin::GetPosY() {
	return posY;
}

int Coin::GetWidth() {
	return width;
}

int Coin::GetHeight() {
	return height;
}

void Coin::Deth() {
	live = false;
}

void Coin::SetPosition1(int gameTime) {
	for (int i = 0; i < COIN_ALLNUM; i++) {
		if (spawnTiming1[i] == gameTime) {
			posX = 1200;
			posY = 80;
			live = true;
		}
	}
}

void Coin::SetPosition2(int gameTime) {
	for (int i = 0; i < COIN_ALLNUM; i++) {
		if (spawnTiming2[i] == gameTime) {
			posX = 1200;
			posY = 160;
			live = true;
		}
	}
}

void Coin::SetPosition3(int gameTime) {
	for (int i = 0; i < COIN_ALLNUM; i++) {
		if (spawnTiming3[i] == gameTime) {
			posX = 1200;
			posY = 240;
			live = true;
		}
	}
}

void Coin::SetPosition4(int gameTime) {
	for (int i = 0; i < COIN_ALLNUM; i++) {
		if (spawnTiming4[i] == gameTime) {
			posX = 1200;
			posY = 320;
			live = true;
		}
	}
}

void Coin::SetPosition5(int gameTime) {
	for (int i = 0; i < COIN_ALLNUM; i++) {
		if (spawnTiming5[i] == gameTime) {
			posX = 1200;
			posY = 400;
			live = true;
		}
	}
}

void Coin::SetPosition6(int gameTime) {
	for (int i = 0; i < COIN_ALLNUM; i++) {
		if (spawnTiming6[i] == gameTime) {
			posX = 1200;
			posY = 480;
			live = true;
		}
	}
}

void Coin::SetPosition7(int gameTime) {
	for (int i = 0; i < COIN_ALLNUM; i++) {
		if (spawnTiming7[i] == gameTime) {
			posX = 1200;
			posY = 560;
			live = true;
		}
	}
}

void Coin::SetPosition8(int gameTime) {
	for (int i = 0; i < COIN_ALLNUM; i++) {
		if (spawnTiming8[i] == gameTime) {
			posX = 1200;
			posY = 640;
			live = true;
		}
	}
}

bool Coin::GetLive() {
	return live;
}

//void Coin::AllSetPosition(int gameTime) {
//	for (int i = 0; i < COIN_NUM; i++) {
//		if (!live) {
//			SetPosition1(gameTime);
//			break;
//		}
//	}
//	for (int i = 0; i < COIN_NUM; i++) {
//		if (!live) {
//			SetPosition2(gameTime);
//			break;
//		}
//	}
//	for (int i = 0; i < COIN_NUM; i++) {
//		if (!live) {
//			SetPosition3(gameTime);
//			break;
//		}
//	}
//	for (int i = 0; i < COIN_NUM; i++) {
//		if (!live) {
//			SetPosition4(gameTime);
//			break;
//		}
//	}
//	for (int i = 0; i < COIN_NUM; i++) {
//		if (!live) {
//			SetPosition5(gameTime);
//			break;
//		}
//	}
//	for (int i = 0; i < COIN_NUM; i++) {
//		if (!live) {
//			SetPosition6(gameTime);
//			break;
//		}
//	}
//	for (int i = 0; i < COIN_NUM; i++) {
//		if (!live) {
//			SetPosition7(gameTime);
//			break;
//		}
//	}
//	for (int i = 0; i < COIN_NUM; i++) {
//		if (!live) {
//			SetPosition8(gameTime);
//			break;
//		}
//	}
//}