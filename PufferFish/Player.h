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
	MoveState moveState; // ���݂̏��
	int posX, posY; // �ʒu
	float vecY; // �i�s��������
	float gravity; // �d��
	float buoyancy; // ����
	int width, height; // �傫��
	float diveSpeed; //�X�s�[�h
	int gh; // �O���t�B�b�N�n���h���i�[
	int space; // �X�y�[�X����p
	bool landingOnth; //��������
	int life; //hp
	int diveStart; //�_�C�u������܂ł̎���
	bool dash; //�_�b�V���p
	int flashCount; //�_�ŗp�J�E���g
	int flashFlag; //�_�ŗp�t���O
	int mutekiCount; //���G�����p�J�E���g
	bool mutekiFlag; //���G�����p�t���O
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