#pragma once

#include <vector>
#include <conio.h>
#include "Utils.h"
#include "Robot.h"	//Robot es enemigo, pero ya es muy tarde para cambiarle el nombre xd
#include "jugador.h"
#include "ImagenJugador.h"

void minijuegoAutos();
Robot* dameCarro(int y, int X = 0);

void TercerNivel() {	//Codigo del tercer nivel aqui

}

void minijuegoAutos(){
	char key;
	int lastY = 10;
	Random random;

	vector<Robot*> autos;
	Jugador *jugador = new Jugador(0,0, MiniPersonaje, 4);

	//Crear autos
	for (int i = 0; i < 6; i++) {
		autos.push_back(dameCarro(
			12 + (i * 5),								//Y
			random.Next(10, 100))		//X
		);
		Sleep(10);
	}

	//bucle principal
	while (true) {
		//Movimiento de los autos
		Console::SetCursorPosition(0, 10);  cout << "\x1b[1;39;49m" << string(conSizeX, '-');
		for (int i = 0; i < autos.size(); i++) {
			Console::SetCursorPosition(0, autos[i]->getY()+3);  cout << "\x1b[1;39;49m" << string(conSizeX, '-');
			autos[i]->clear();
			if (autos[i]->XcanMove()) {	//movimiento autorizado
				autos[i]->autoMove();
				autos[i]->draw();
				jugador->collideEnemy(autos[i]->getRectagle());
			}
			else {	//Chocaria con el borde
				lastY = autos[i]->getY();

				delete autos[i];						//Libera la memoria	del objeto
				autos.erase(autos.begin() + i);	//Borra el puntero que esta en el vector
				
				autos.push_back(dameCarro(lastY));
				i--;									//Regresa una unidad el contador
				Sleep(1);					//Para que no llore Random
			}
		}

		if (kbhit()) {		//El jugador debe ser lo ultimo en el orden de dibujado
			key = getch();
			key = toupper(key);
			jugador->clear();
			jugador->inputMove(key);
		}
		jugador->draw();

		Sleep(waitTime);
	}
}

Robot* dameCarro(int Y, int X) {
	string auto1[3] = {
		"",
		".-'--`-._",
		"'-O---O--'"
	};
	string auto2[3] = {
		"__",
		".-'--`-._",
		"'-O---O--'"
	};
	string auto3[3] = {
		" _. - .___\\__",
		"| _      _`-.",
		"'-(_)----(_)--`"
	};

	Random random;
	return new Robot(
		X,		//X
		Y,											//Y
		random.Next(2,5), 0,									//Dx, Dy
		15, 3,									//Sx, sY
		random.Next(1, 3) % 2 == 0 ? auto1 : (random.Next(1, 3) % 2 == 0 ? auto2 : auto3),	//Sorry por quien itente leer esto XD
		getRandomColor(),
		true
	);
}
