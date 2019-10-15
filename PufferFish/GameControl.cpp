#include"GameControl.h"

GameControl::GameControl() {
	gameTime = 0;

	pl = new Player();
	for (int i = 0; i < ENEMY_NUM; i++) {
		en[i] = new Enemy();
	}
	bg = new Background();
	for (int i = 0; i < COIN_NUM; i++) {
	    coin[i] = new Coin();
	}
}

GameControl::~GameControl() {
	delete pl;
	for (int i = 0; i < ENEMY_NUM; i++) {
		delete en[i];
	}
	delete bg;
	for (int i = 0; i < COIN_NUM; i++) {
	    delete coin[i];
	}
}

void GameControl::Game() {
	for (int i = 0; i < COIN_NUM; i++) {
		coin[i]->AllSetPosition(gameTime);
	}

	bg->SeaDraw();
	//for (int i = 0; i < ENEMY_NUM; i++) {
	//	en[i]->All();
	//}
	for (int i = 0; i < COIN_NUM; i++) {
	    coin[i]->All();
	}
	pl->All();
	bg->SeaCoverDraw();
	bg->Move(pl->IsDash());

	//当たり判定
	//プレイヤーとエネミー
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (en[i]->GetPosX() > pl->GetPosX() &&
			en[i]->GetPosX() < pl->GetPosX() + pl->GetWidth() &&
			en[i]->GetPosY() > pl->GetPosY() &&
			en[i]->GetPosY() < pl->GetPosY() + pl->GetHeight() &&
			!pl->MutekiNow()) {
			if (pl->Damage()) {
				pl->FlashFlagOn();
				pl->MutekiOn();
			}
		}
		if (en[i]->GetPosX() + en[i]->GetWidth() > pl->GetPosX() &&
			en[i]->GetPosX() + en[i]->GetWidth() < pl->GetPosX() + pl->GetWidth() &&
			en[i]->GetPosY() > pl->GetPosY() &&
			en[i]->GetPosY() < pl->GetPosY() + pl->GetHeight() &&
			!pl->MutekiNow()) {
			if (pl->Damage()) {
				pl->FlashFlagOn();
				pl->MutekiOn();
			}
		}
		if (en[i]->GetPosX() > pl->GetPosX() &&
			en[i]->GetPosX() < pl->GetPosX() + pl->GetWidth() &&
			en[i]->GetPosY() + en[i]->GetHeight() > pl->GetPosY() &&
			en[i]->GetPosY() + en[i]->GetHeight() < pl->GetPosY() + pl->GetHeight() &&
			!pl->MutekiNow()) {
			if (pl->Damage()) {
				pl->FlashFlagOn();
				pl->MutekiOn();
			}
		}
		if (en[i]->GetPosX() + en[i]->GetWidth() > pl->GetPosX() &&
			en[i]->GetPosX() + en[i]->GetWidth() < pl->GetPosX() + pl->GetWidth() &&
			en[i]->GetPosY() + en[i]->GetHeight() > pl->GetPosY() &&
			en[i]->GetPosY() + en[i]->GetHeight() < pl->GetPosY() + pl->GetHeight() &&
			!pl->MutekiNow()) {
			if (pl->Damage()) {
				pl->FlashFlagOn();
     				pl->MutekiOn();
			}
		}
	}

	//プレイヤーとコイン
	for (int i = 0; i < COIN_NUM; i++) {
		if (coin[i]->GetPosX() > pl->GetPosX() &&
			coin[i]->GetPosX() < pl->GetPosX() + pl->GetWidth() &&
			coin[i]->GetPosY() > pl->GetPosY() &&
			coin[i]->GetPosY() < pl->GetPosY() + pl->GetHeight()) {
			coin[i]->Deth();
			break;
		}
		if (coin[i]->GetPosX() + coin[i]->GetWidth() > pl->GetPosX() &&
			coin[i]->GetPosX() + coin[i]->GetWidth() < pl->GetPosX() + pl->GetWidth() &&
			coin[i]->GetPosY() > pl->GetPosY() &&
			coin[i]->GetPosY() < pl->GetPosY() + pl->GetHeight()) {
			coin[i]->Deth();
			break;
		}
		if (coin[i]->GetPosX() > pl->GetPosX() &&
			coin[i]->GetPosX() < pl->GetPosX() + pl->GetWidth() &&
			coin[i]->GetPosY() + coin[i]->GetHeight() > pl->GetPosY() &&
			coin[i]->GetPosY() + coin[i]->GetHeight() < pl->GetPosY() + pl->GetHeight()) {
			coin[i]->Deth();
			break;
		}
		if (coin[i]->GetPosX() + coin[i]->GetWidth() > pl->GetPosX() &&
			coin[i]->GetPosX() + coin[i]->GetWidth() < pl->GetPosX() + pl->GetWidth() &&
			coin[i]->GetPosY() + coin[i]->GetHeight() > pl->GetPosY() &&
			coin[i]->GetPosY() + coin[i]->GetHeight() < pl->GetPosY() + pl->GetHeight()) {
			coin[i]->Deth();
			break;
		}
	}

	gameTime++;
}

void GameControl::All() {
	Game();
}