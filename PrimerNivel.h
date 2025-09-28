#pragma once

#include "MunoUno.h"
#include "Robot.h"
#include "jugador.h"

void primerNivel() {
	//Creacion de objetos para el primer nivel
	Random random;
	Jugador* jugador = new Jugador(1, 1);

	MundoUno mundo1(0, 26, ConsoleColor::DarkYellow);

	Robot** robots = new Robot * [3];
	for (int i = 0; i < 3; i++) {
		robots[i] = new Robot(
			random.Next(0, conSizeX - 15),
			random.Next(0, conSizeY - 6),
			random.Next(1, 3) % 2 == 0 ? 1 : -1,
			random.Next(1, 3) % 2 == 0 ? 1 : -1,
			getRandomColor());
		Sleep(waitTime / 2);	//necesario, si no random.next no es suficientemente aleatorio
	}

	//Bucle principal del primer nivel
	while (true) {
		//dibujar mundo
		mundo1.draw();

		//movimiento de robots
		for (int i = 0; i < 3; i++) {
			robots[i]->clear();
			robots[i]->autoMove();
			robots[i]->draw();

			//Colisiones
			//jugador->collideEnemy(robots[i]->getRectagle()); //Descomentar para activar colisiones
			if(jugador->getVidas() <= 0) {
				return; //Game over
			}
		}

		//Codigo del jugador aquí
		char tecla = ' ';
		if (_kbhit()) {
			tecla = _getch();
			jugador->clear();
			jugador->inputMove(tecla);
		}
		jugador->draw();

		Sleep(waitTime);
	}
}