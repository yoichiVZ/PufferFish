#pragma once

#include"DxLib.h"

class Player {
private:
	enum MoveState {
		IDLE,
		DIVE,
		JUMP,
	};
	MoveState moveState; // ���݂̏��
	float posX, posY; // �ʒu
	float vecY; // �i�s��������
	float gravity; // �d��
	float buoyancy; // ����
	int width, height; // �傫��
	float diveSpeed; //�X�s�[�h
	int gh; // �O���t�B�b�N�n���h���i�[
	int space; // �X�y�[�X����p
	bool landingOnth; //��������
public:
	Player();
	void Init();
	void Move();
	void Draw();
	void All();
	void PushSpace();
};