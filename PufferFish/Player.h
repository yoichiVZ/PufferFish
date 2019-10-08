#pragma once

#include"DxLib.h"

class Player {
private:
	enum MoveState {
		Idle,
		Swim,
		Jump,
	};
	MoveState moveState; // 現在の状態
	float posX, posY; // 位置
	float vecY, gravity, buoyancy; // 方向
	int width, height; // 大きさ
	float speed; //スピード
	int gh; // グラフィックハンドル格納
public:
	Player();
	void Init();
	void Move();
	void Draw();
	void All();
};