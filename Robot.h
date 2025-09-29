#pragma once

#include "Entidad.h"

class Robot : public Entity {  //Hereda propiedades y metodos de Entidad
private:
    int dx, dy;
	int lx, ly; //Limites de movimiento

public:
    Robot() : Entity() {
        dx = 0; dy = 0;
    }
	Robot(int X, int Y, int dX, int dY, int sX, int sY, string sp[], ConsoleColor c, bool v) : Entity(X, Y, sX, sY, sp, c, v) {
        dx = dX; dy = dY;
	}
    Robot(int X, int Y, int dX, int dY, int lX, int lY, ConsoleColor c) : Entity(X, Y, c) {
        dx = dX; dy = dY;
		lx = lX; ly = lY;

        sizeY = 6; sizeX = 10;
		sprite = new string[sizeY];
		sprite[0] = "   ----";
		sprite[1] = "  | D_D|";
		sprite[2] = "[]|----|[]";
		sprite[3] = "  | WW |";
		sprite[4] = "  |____|";
		sprite[5] = "   L L";
	}
    ~Robot() {}

	//movimiento
    void autoMove() {

        if (x + dx > 0 && x + dx + sizeX < lx) {
			x += dx;
        }
        else {
			dx *= -1;
        }
        if (y + dy > 0 && y + dy + sizeY < ly+1) {
			y += dy;
        }
        else {
			dy *= -1;
        }
    }
};


/*#include <iostream>
#include "jugador.h"
using namespace System;
using namespace std;


class Robots {
private:
    int x, y, dx, dy;
    int ancho, alto;
    bool visible;

public:
    Robots(int x, int y, int dx, int dy) {
        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
        this->ancho = 11;
        this->alto = 6;
        this->visible = true;


    }
    ~Robots() {

    }
    void dibujar() {
        Console::SetCursorPosition(x, y);     cout << "   ----";
        Console::SetCursorPosition(x, y + 1); cout << "  | D_D|";
        Console::SetCursorPosition(x, y + 2); cout << "[]|----|[]";
        Console::SetCursorPosition(x, y + 3); cout << "  | WW |";
        Console::SetCursorPosition(x, y + 4); cout << "  |____|";
        Console::SetCursorPosition(x, y + 5); cout << "   L L";
    }
    void borrar() {
        for (int i = 0; i < alto; ++i) {
            Console::SetCursorPosition(x, y + i);
            cout << string(ancho, ' ');
        }
    }
    void mover() {

        if (x + dx < 0 || x + dx + ancho > ANCHO1) {
            dx *= -1;
        }

        if (y + dy < 0 || y + dy + alto > LARGO1) {
            dy *= -1;
        }

        x += dx;
        y += dy;
    }

    void cambiarmovimiento(char tecla) {
        switch (tecla) {
        case 'W': dy = -1; dx = 0; break;
        case 'S': dy = 1; dx = 0; break;
        case 'A': dx = -1; dy = 0; break;
        case 'D': dx = 1; dy = 0; break;
        }
    }
    void limpiar() {
        system("cls");
    }
    int getX() { return x; }
    int getY() { return y; }
    int getAncho() { return ancho; }
    int getAlto() { return alto; }
};*/