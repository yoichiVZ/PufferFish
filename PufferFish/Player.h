#pragma once

#include"DxLib.h"

class Player {
private:
	enum MoveState {
		Idle,
		Swim,
		Jump,
	};
	MoveState moveState; // ���݂̏��
	float posX, posY; // �ʒu
	float vecY, gravity, buoyancy; // ����
	int width, height; // �傫��
	float speed; //�X�s�[�h
	int gh; // �O���t�B�b�N�n���h���i�[
public:
	Player();
	void Init();
	void Move();
	void Draw();
	void All();
};