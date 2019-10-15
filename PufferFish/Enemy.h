#pragma once

#include"DxLib.h"

const static int ENEMY_NUM = 20;

class Enemy {
private:
	int posX, posY; // 位置
	float gravity; // 重力
	float buoyancy; // 浮力
	int width, height; // 大きさ
	float speed; //スピード
	int gh; // グラフィックハンドル格納
public:
	Enemy();
	void Init();
	void Move();
	void Draw();
	void All();
	int GetPosX();
	int GetPosY();
	int GetWidth();
	int GetHeight();
};