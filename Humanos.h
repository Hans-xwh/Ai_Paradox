#pragma once

#include "Entidad.h"

//Para implementarlo en el nivel 3

class Humanos : public Entity {

private:
	int dx, dy;
	int lx, ly;

public:

	Humanos() : Entity() {
		dx = 0; dy = 0;
	}
	Humanos(int X, int Y, int dX, int dY, int lX, int lY, ConsoleColor c) : Entity(X, Y, c) {

		dx = dX;
		dy = dY;
		lx = lX;
		ly = lY;
		sizeY = 7; sizeX = 8;

		sprite = new string[sizeY];
		sprite[0] = "T----T";
		sprite[1] = "|o, o|";
		sprite[2] = "-----";
		sprite[3] = "[| o |]";
		sprite[4] = "[| o |]";
		sprite[5] = " -----";
		sprite[6] = " L L";
	}

	~Humanos() { }
	
	void autoMove() {
		if (x + dx > 0 && x + dx + sizeX < lx) {
			x += dx;
		}
		else { dx *= -1; }
		if (y + dy > 0 && y + dy + sizeY < ly + 1) {
			y += dy;
		}
		else { dy *= -1; }

	}


};