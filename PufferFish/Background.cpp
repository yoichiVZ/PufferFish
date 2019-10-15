#include"Background.h"

Background::Background() {
	seaGh = LoadGraph("Resourse\\Image\\Haikei.png");
	GetGraphSize(seaGh, &seaWidth, &seaHeight);
	seaWidth *= 2, seaHeight *= 2;
	seaCoverGh = LoadGraph("Resourse\\Image\\haikei2.png");
	GetGraphSize(seaCoverGh, &seaCoverWidth, &seaCoverHeight);
	seaCoverWidth *= 2, seaCoverHeight *= 2;

	posX = 0;
	posY = 0;
	scrollSpeed = 2;
}

void Background::SeaDraw() {
	DrawExtendGraph(posX, posY, posX + seaWidth, posY + seaHeight, seaGh, false);

	DrawExtendGraph(posX + seaWidth, posY, posX + seaWidth + seaWidth, posY + seaHeight, seaGh, false);
}

void Background::SeaCoverDraw() {
	DrawExtendGraph(posX, posY, posX + seaCoverWidth, posY + seaCoverHeight, seaCoverGh, true);

	DrawExtendGraph(posX + seaCoverWidth, posY, posX + seaCoverWidth + seaCoverWidth, posY + seaCoverHeight, seaCoverGh, true);
}

void Background::Move(bool dash) {
	if (!dash)
		posX -= scrollSpeed;
	if (dash)
		posX -= (scrollSpeed * 3);
	if (posX <= -seaWidth) {
		posX = 0;
	}
}
