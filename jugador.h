#pragma once

#include <iostream>
#include <windows.h>
#include "ImagenJugador.h"
#include "Entidad.h"

using namespace std;

class Jugador : public Entity { //Hereda propiedades y metodos de Entidad
private:
    int vidas;
    bool invencible;

public:
    Jugador(int X, int Y) : Entity(X, Y, ConsoleColor::White) { //SEXO
        vidas = 3;
		invencible = true;


        sprite = new string[imgJugador.length];
        sizeY = imgJugador.length; sizeX = 13;

        for (int i = 0; i < sizeY; i++) {
            sprite[i] = imgJugador.image[i];
        }
    }

    Jugador(int X, int Y, string sp[], int sp_lngt) : Entity(X, Y, ConsoleColor::White) {   //No Sexo
        vidas = 3;
        invencible = true;


        sprite = new string[sp_lngt];
        sizeY = sp_lngt;
        sizeX = 4;

        for (int i = 0; i < sizeY; i++) {
            sprite[i] = sp[i];
        }
    }
    ~Jugador() {}

    void setVidas(int v) {
        vidas = v;
    }
    int getVidas() {
        return vidas;
	}
    void setInvencible(bool i) {
        invencible = i;
	}
    bool isInvencible() {
        return invencible;
    }

    void inputMove(char key) {
		invencible = false; //El jugador deja de ser invencible al moverse. Asi tiene tiempo de pensar en vez de perder todas las vidas de golpe.
        key = toupper(key);

        switch (key) {
        case 'W':
            if (y > 0) y--;
            break;
        case 'S':
            if (y + sizeY < conSizeY) y++;
            break;
        case 'A':
			if (x > 1) x -= 2;  //x>1 para evitar que se salga por la izquierda al avanzar 2 espacios
            break;
        case 'D':
            if (x + sizeX < conSizeX) x += 2;
            break;
        }
    }

    void resetPosition() {
        clear();
        x = 0; y = 0;
    }

    void collideEnemy(Drawing::Rectangle collider) {
        if (this->getRectagle().IntersectsWith(collider) && !invencible) {
			invencible = true;
            vidas--;
            resetPosition();
			Sleep(500);
			
		}
    }
};  