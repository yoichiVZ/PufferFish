#pragma once

#include"DxLib.h"

const static int UNTIL_STATRT = 12;

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
	int diveStart; //ダイブをするまでの時間
	bool dash; //ダッシュ用
	int flashCount; //点滅用カウント
	int flashFlag; //点滅用フラグ
	int mutekiCount; //無敵処理用カウント
	bool mutekiFlag; //無敵処理用フラグ
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
	bool IsDash();
	void FlashFlagOn();
	void MutekiOn();
	bool MutekiNow();
};