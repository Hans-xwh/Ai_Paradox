#pragma once

#include <iostream>

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
        this->ancho = 7;
        this->alto = 8;
        this->visible = true;
    }

    ~Jugador() {}

    int getX() { return x; }
    int getY() { return y; }
    int getAncho() { return ancho; }
    int getAlto() { return alto; }

    void vidas(bool explotar = true) {
        int vidas = 3;
        Console::SetCursorPosition(5, 5);
        cout << "Vidas: " << vidas << "   ";
        if (explotar) {
            vidas--;
        }
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
        Console::SetCursorPosition(x, y);     cout << "       ";
        Console::SetCursorPosition(x, y + 1); cout << "       ";
        Console::SetCursorPosition(x, y + 2); cout << "       ";
        Console::SetCursorPosition(x, y + 3); cout << "        ";
        Console::SetCursorPosition(x, y + 4); cout << "            ";
        Console::SetCursorPosition(x, y + 5); cout << "          ";
        Console::SetCursorPosition(x, y + 6); cout << "          ";
        Console::SetCursorPosition(x, y + 7); cout << "      ";
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

        Sleep(1000);
        return true;
    }

    void limpiar() {
        system("cls");
    }
};