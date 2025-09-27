#pragma once

#include <iostream>
#include <windows.h>

#define ANCHO1 100
#define LARGO1 50
#define MAX_BALAS 20
#define BLOQUES 10

using namespace System;
using namespace std;

class Jugador { //Sexo
private:
    int x, y, dx, dy;
    int ancho, alto;
    bool visible;

public:
    Jugador(int x, int y, int dx, int dy) {
        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
        this->ancho = 12;
        this->alto = 8;
        this->visible = true;
    }

    ~Jugador() {}

    int getX() { return x; }
    int getY() { return y; }
    int getAncho() { return ancho; }
    int getAlto() { return alto; }

    void imprimirVidas(int vidas) {
        Console::SetCursorPosition(5, 5);
        Console::WriteLine("Vidas: " + vidas);
    }

    void resetearPosicion(bool arribaesquina = true) {
        if (arribaesquina) {
            x = 0;
            y = 0;
        }
    }

    void dibujar() {
        Console::SetCursorPosition(x, y);     cout << " u----u";
        Console::SetCursorPosition(x, y + 1); cout << "| 0v0|";
        Console::SetCursorPosition(x, y + 2); cout << " ----";
        Console::SetCursorPosition(x, y + 3); cout << "[]|o|[]";
        Console::SetCursorPosition(x, y + 4); cout << "[]|o|[]";
        Console::SetCursorPosition(x, y + 5); cout << "E ---E";
        Console::SetCursorPosition(x, y + 6); cout << " || ||";
        Console::SetCursorPosition(x, y + 7); cout << " |L |L";
    }

    void borrar() {
        for (int i = 0; i < alto; ++i) {
            Console::SetCursorPosition(x, y + i);
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

    bool explotar() {
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
        system("cls");
    }
};