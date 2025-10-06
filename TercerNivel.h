#pragma once

#include <vector>
#include <conio.h>
#include "Utils.h"
#include "Robot.h"	//Robot es enemigo, pero ya es muy tarde para cambiarle el nombre xd
#include "jugador.h"
#include "Entidad.h"
#include "ImagenJugador.h"
#include "MunoUno.h"

void minijuegoAutos();
Robot* dameCarro(int y, int X = 0);

void TercerNivel() {	//Codigo del tercer nivel aqui
	minijuegoAutos();
}

void minijuegoAutos(){
	system("cls");
	char key;
	int lastY = 10;
	Random random;

	vector<Robot*> autos;
	Jugador *jugador = new Jugador(0,0, MiniPersonaje, 4);

	Robot* robotin = new Robot(120, 2, 0, 0, 0, 0, ConsoleColor::DarkCyan);
	robotin->editSprite("  |d_d |", 1);
	robotin->editSprite("  _| _|", 5);

	Entity* Semaforo1 = new Entity(0, 42);
	Entity* Semaforo2 = new Entity(135, 42);
	Semaforo1->setSprite(4, 5, SemaforoVerde, getRandomColor());
	Semaforo2->setSprite(4, 5, SemaforoVerde, getRandomColor());

	Entity* puerta = new Entity(conSizeX / 2, conSizeY - 7);

	//configuracion puerta
	puerta->setSprite(6, 7, spr_puerta, ConsoleColor::DarkYellow);
	puerta->editSprite("|HOME|", 1);

	//Crear autos
	for (int i = 0; i < 6; i++) {
		autos.push_back(dameCarro(
			12 + (i * 5),								//Y
			random.Next(10, 100))		//X
		);
		Sleep(10);
	}

	//Dibujado inicial
	robotin->draw();
	Semaforo1->draw();
	Semaforo2->draw();
	puerta->draw();

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
			//semaforos
			Semaforo1->draw();
			Semaforo2->draw();
			puerta->draw();


			key = getch();
			key = toupper(key);
			jugador->clear();
			jugador->inputMove(key);

			if (jugador->getX() >= 116 && jugador->getY() <= 10) {
				Console::ForegroundColor = ConsoleColor::DarkCyan;
				Console::SetCursorPosition(110, 1);

				Semaforo1->setSprite(4, 5, SemaforoRojo, getRandomColor());
				Semaforo2->setSprite(4, 5, SemaforoRojo, getRandomColor());
				cout << "Yo te ayudare a cruzar, humano.";
				break;
			}

			if (jugador->getRectagle().IntersectsWith(puerta->getRectagle())) {
				sequence_Finales();
				goto end;
			}

		}
		jugador->draw();

		Sleep(waitTime);
	}

	Semaforo1->draw();
	Semaforo2->draw();
	while (true) {
		//Movimiento de los autos
		Console::SetCursorPosition(0, 10);  cout << "\x1b[1;39;49m" << string(conSizeX, '-');
		for (int i = 0; i < 6; i++) {	//dibujado sin autos
			Console::SetCursorPosition(0, 12 + (i * 5) + 3);  cout << "\x1b[1;39;49m" << string(conSizeX, '-');
		}

		for (int i = 0; i < autos.size(); i++) {
			Console::SetCursorPosition(0, autos[i]->getY() + 3);  cout << "\x1b[1;39;49m" << string(conSizeX, '-');
			if (autos[i]->XcanMove()) {	//movimiento autorizado
				autos[i]->clear();
				autos[i]->autoMove();
				autos[i]->draw();
				jugador->collideEnemy(autos[i]->getRectagle());
			}
			else {	//Chocaria con el borde
				autos[i]->draw();

				delete autos[i];						//Libera la memoria	del objeto
				autos.erase(autos.begin() + i);	//Borra el puntero que esta en el vector

				//autos.push_back(dameCarro(lastY));
				i--;									//Regresa una unidad el contador
				Sleep(1);					//Para que no llore Random
			}
		}

		robotin->draw();

		if (kbhit()) {		//El jugador debe ser lo ultimo en el orden de dibujado
			Semaforo1->draw();
			Semaforo2->draw();

			key = getch();
			key = toupper(key);
			jugador->clear();
			jugador->inputMove(key);

			if (jugador->getRectagle().IntersectsWith(puerta->getRectagle())) {
				sequence_Finales();
				goto end;
			}

		}
		jugador->draw();

		Sleep(waitTime);
	}

	//Libera memoria
	end:
	delete robotin;
	delete jugador;
	delete Semaforo1;
	delete Semaforo2;
	delete puerta;
	return;
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
