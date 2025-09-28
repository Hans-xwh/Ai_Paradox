#pragma once


#include "Robot.h"
#include "jugador.h"

void primerNivel() {
	//Creacion de objetos para el primer nivel
	Random random;
	Jugador* jugador = new Jugador(1, 1, 0, 0);

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
		//movimiento de robots
		for (int i = 0; i < 3; i++) {
			robots[i]->clear();
			robots[i]->autoMove();
			robots[i]->draw();
		}

		//Codigo del jugador aquí
		char tecla = ' ';
		if (_kbhit()) {
			tecla = _getch();
			tecla = toupper(tecla);
			jugador->cambiarmovimiento(tecla);
		}
		jugador->borrar();
		jugador->mover();
		jugador->dibujar();

		Sleep(waitTime);
	}
}