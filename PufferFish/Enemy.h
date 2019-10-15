#pragma once

#include"DxLib.h"

const static int ENEMY_NUM = 20;

class Enemy {
private:
	int posX, posY; // �ʒu
	float gravity; // �d��
	float buoyancy; // ����
	int width, height; // �傫��
	float speed; //�X�s�[�h
	int gh; // �O���t�B�b�N�n���h���i�[
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