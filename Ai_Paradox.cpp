#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "jugador.h"
#include "Robots.h"
#include <windows.h>

using namespace std;
using namespace System;

void TerminarJuegoTecla() {
    cout << "\nPresiona una tecla para terminar..."; _getch();
}

int main() {
    Console::SetWindowSize(ANCHO1, LARGO1);
    Console::CursorVisible = false;

    Jugador jugador(1, 1, 0, 0);

    Robots robot1(30, 10, 1, 1);
    Robots robot2(40, 10, 2, 2);
    Robots robot3(50, 10, 2, 1);

    ///
    int vidas = 3;
    bool vivo = true;
    char tecla;
    ///

    while (vivo) {

        if (_kbhit()) {
            tecla = _getch();
            tecla = toupper(tecla);

            if (tecla == 'W' || tecla == 'S' || tecla == 'A' || tecla == 'D') {
                jugador.cambiarmovimiento(tecla);
            }
        }

        Sleep(10);
        Console::ForegroundColor = ConsoleColor::Red;
        jugador.borrar(); jugador.mover(); jugador.dibujar();
        Console::ForegroundColor = ConsoleColor::DarkYellow;
        robot1.borrar(); robot1.mover(); robot1.dibujar();
        robot2.borrar(); robot2.mover(); robot2.dibujar();
        robot3.borrar(); robot3.mover(); robot3.dibujar();
        Console::ForegroundColor = ConsoleColor::White;

        jugador.imprimirVidas(vidas);

        bool fuafua = false;

        if (jugador.getX() < robot1.getX() + robot1.getAncho() &&
            jugador.getX() + jugador.getAncho() > robot1.getX() &&
            jugador.getY() < robot1.getY() + robot1.getAlto() &&
            jugador.getY() + jugador.getAlto() > robot1.getY()) {
            fuafua = true;
        }

        else if (jugador.getX() < robot2.getX() + robot2.getAncho() &&
            jugador.getX() + jugador.getAncho() > robot2.getX() &&
            jugador.getY() < robot2.getY() + robot2.getAlto() &&
            jugador.getY() + jugador.getAlto() > robot2.getY()) {
            fuafua = true;
        }

        else if (jugador.getX() < robot3.getX() + robot3.getAncho() &&
            jugador.getX() + jugador.getAncho() > robot3.getX() &&
            jugador.getY() < robot3.getY() + robot3.getAlto() &&
            jugador.getY() + jugador.getAlto() > robot3.getY()) {
            fuafua = true;
        }

        if (fuafua) {
            jugador.explotar(); jugador.borrar(); vidas--; jugador.resetearPosicion(true);
            Sleep(500);
        }
        if (vidas <= 0) {
            vivo = false;
            Console::SetCursorPosition(5, 6);
            cout << "Perdiste!";
            TerminarJuegoTecla();
        }
        Sleep(100);
    }
    return 0;
}