#pragma once

#include"DxLib.h"

const static int COIN_NUM = 10;
const static int COIN_ALLNUM = 10;

class Coin {
private:
	int posX, posY; //位置
	int width, height; //幅
	int speed; //速さ
	int gh; //グラフィックハンドル格納用変数
	bool live; //生きているか
	int spawnTiming1[COIN_ALLNUM];
	int spawnTiming2[COIN_ALLNUM];
	int spawnTiming3[COIN_ALLNUM];
	int spawnTiming4[COIN_ALLNUM];
	int spawnTiming5[COIN_ALLNUM];
	int spawnTiming6[COIN_ALLNUM];
	int spawnTiming7[COIN_ALLNUM];
	int spawnTiming8[COIN_ALLNUM];
public:
	Coin();
	void Move();
	void Draw();
	void All();
	int GetPosX();
	int GetPosY();
	int GetWidth();
	int GetHeight();
	void Deth();
	void SetPosition1(int);
	void SetPosition2(int);
	void SetPosition3(int);
	void SetPosition4(int);
	void SetPosition5(int);
	void SetPosition6(int);
	void SetPosition7(int);
	void SetPosition8(int);
	bool GetLive();
	//void AllSetPosition(int);
};