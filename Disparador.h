#pragma once

#include "Robot.h"
#include "Utils.h"

class Proyectil : public Robot {
private:
	int dY;

public:
	Proyectil(int X, int Y, int dX, int dY) : Robot(X, Y, dX, dY, conSizeX, conSizeY, ConsoleColor::Red) {
		this->dY = dY;
		string tmpspr[1] = { "X        X" };
		setSprite(10, 1, tmpspr, ConsoleColor::Red);
	}
	~Proyectil() {}

	void autoMove() override {
		if (y < conSizeY) {
			y += dY;
		}
	}
};

class Disparador : public Robot {
private:
	Proyectil* bala;
	int tiempoBala;
	int tick;
	bool balaActive;

public:
	Disparador(int X, int Y, int speed, ConsoleColor c) : Robot(X, Y, 0, 0, conSizeX, conSizeY, c) {
		tiempoBala = speed;
		tick = 0;
		visible = true;
		bala = new Proyectil(x, y + sizeY, 0, 1);
	}
	~Disparador() {
		delete bala;
	}

	void updateBalas(int playerX, int playerY) {
		if (bala->YcanMove()) {
			bala->clear();
			bala->autoMove();
			bala->draw();
		}
		else {
			bala->clear();
			balaActive = false;
			bala->setY(y + sizeY);
		}
	}

	void autoUpdate(int playerX, int playerY) {
		draw();

		if (balaActive) {
			updateBalas(playerX, playerY);
		}
		else {
			tick++;
			if (tick >= tiempoBala) {
				balaActive = true;
				tick = 0;
			}
		}
	}

	Drawing::Rectangle collideBala() {
		return bala->getRectagle();
	}
};