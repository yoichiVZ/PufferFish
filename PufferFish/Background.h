#pragma once

#include"DxLib.h"

class Background {
private:
	int seaGh, seaCoverGh; //�O���t�B�b�N�n���h���i�[
	int posX, posY; //�C�̈ʒu
	int seaWidth, seaHeight, seaCoverWidth, seaCoverHeight; //�C�̕�
	int scrollSpeed; //�X�N���[���X�s�[�h
public:
	Background();
	void SeaDraw();
	void SeaCoverDraw();
	void Move(bool);
};