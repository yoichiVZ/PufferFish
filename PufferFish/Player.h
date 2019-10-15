#pragma once

#include"DxLib.h"

class Player {
private:
	enum MoveState {
		IDLE,
		DIVE,
		JUMP,
	};
	MoveState moveState; // 現在の状態
	int posX, posY; // 位置
	float vecY; // 進行方向決定
	float gravity; // 重力
	float buoyancy; // 浮力
	int width, height; // 大きさ
	float diveSpeed; //スピード
	int gh; // グラフィックハンドル格納
	int space; // スペース判定用
	bool landingOnth; //着水判定
	int life; //hp
public:
	Player();
	void Init();
	void Move();
	void Draw();
	void All();
	void PushSpace();
	int GetPosX();
	int GetPosY();
	int GetWidth();
	int GetHeight();
	bool Damage();
};