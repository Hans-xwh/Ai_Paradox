#pragma once

#include <iostream>
#include <windows.h>
#include "ImagenJugador.h"

#define ANCHO1 100
#define LARGO1 50
#define MAX_BALAS 20
#define BLOQUES 10

using namespace std;

class Jugador { //Sexo
private:
    int x, y, dx, dy;
    int ancho, alto;
    bool visible;
    ImagenJugador sprite;

public:
    Jugador(int x, int y, int dx, int dy) {
        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
        this->ancho = sprite.image[0].length();
        this->alto = sprite.length;
        this->visible = true;
    }

    ~Jugador() {}

    int getX() { return x; }
    int getY() { return y; }
    int getAncho() { return ancho; }
    int getAlto() { return alto; }

    void imprimirVidas(int vidas) {
        COORD curd;
        curd.X = x;
        curd.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curd);
        cout << " VIDAD: " << vidas;
    }

    void resetearPosicion(bool arribaesquina = true) {
        if (arribaesquina) {
            x = 0;
            y = 0;
        }
    }

    void dibujar() {
        if (!visible) return;
        for (int i = 0; i < alto; i++) {
            COORD curd;
            curd.X = x;
            curd.Y = y + i;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curd);
            cout << sprite.image[i];
        }
    }

    void borrar() {
        for (int i = 0; i < alto; ++i) {
            COORD curd;

            curd.X = x;
            curd.Y = y + 1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curd);
            cout << string(ancho, ' ');
        }
    }

    void mover() {
        if (x + dx < 0 || x + dx + ancho > ANCHO1) dx *= -1;
        if (y + dy < 0 || y + dy + alto > LARGO1) dy *= -1;
        x += dx; y += dy;
    }

    void cambiarmovimiento(char tecla) {
        switch (tecla) {
        case 'W': dy = -1; dx = 0; break;
        case 'S': dy = 1; dx = 0; break;
        case 'A': dx = -1; dy = 0; break;
        case 'D': dx = 1; dy = 0; break;
        }
    }

   /* bool explotar() {
        Console::ForegroundColor = ConsoleColor::DarkGreen;

        Console::SetCursorPosition(x, y); cout << " ////////////";
        Console::SetCursorPosition(x, y + 1); cout << " .............";
        Console::SetCursorPosition(x, y + 2); cout << " ////////";
        Sleep(200);
        limpiar();

        Console::SetCursorPosition(x, y); cout << "******";
        Console::SetCursorPosition(x, y + 1); cout << "******";
        Console::SetCursorPosition(x, y + 2); cout << "******";
        Sleep(200);
        limpiar();

        Sleep(500);
        return true;
    }

    void limpiar() {
        
    }*/
};