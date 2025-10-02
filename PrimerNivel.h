#pragma once

#include "MunoUno.h"
#include "Robot.h"
#include "Entidad.h"
#include "jugador.h"
#include "Cutscene.h"



void primerNivel() {
	//Creacion de objetos para el primer nivel
	Random random;
	Jugador* jugador = new Jugador(1, 1);
	Entity* puerta = new Entity(conSizeX - 7, conSizeY / 2 -5, 6, 7, spr_puerta, ConsoleColor::DarkBlue, 1);
	//MundoUno mundo1(0, 26, ConsoleColor::DarkYellow);

	Robot** robots = new Robot * [3];
	for (int i = 0; i < 3; i++) {
		robots[i] = new Robot(
			20 + i*40,		//x
			random.Next(0, conSizeY - 6),		//y
			0,													//dx
			random.Next(1, 3) % 2 == 0 ? 1 : -1,	//dy
			conSizeX - 5,										//lx
			conSizeY,											//ly
			getRandomColor());									//color
		Sleep(waitTime / 2);	//necesario, si no random.next no es suficientemente aleatorio
	}

	
	//Bucle Primera parte del nivel
	system("cls");
	while (true) {
		puerta->draw();

		//movimiento de robots
		for (int i = 0; i < 3; i++) {
			robots[i]->clear();
			robots[i]->autoMove();
			robots[i]->draw();

			//Colisiones
			jugador->collideEnemy(robots[i]->getRectagle()); //Comentar para desactivar colisiones
			if (jugador->getVidas() <= 0) {
				system("cls");
				cout << "GAME OVER" << endl;
				Sleep(1000);
				system("pause");
				primerNivel(); //Reiniciar nivel
				goto end;
			}
		}

		char tecla = ' ';
		if (_kbhit()) {
			tecla = _getch();
			jugador->clear();
			jugador->inputMove(tecla);

			if (jugador->getRectagle().IntersectsWith(puerta->getRectagle())) {
				Sleep(1000);
				break; //terminar bucle y pasar a siguiente fase
			}

			if (tecla == 27) { //ESCAPE
				goto end;
			}
		}
		jugador->draw();

		Sleep(waitTime);

	}

	//Cambios para segunda fase
	for (int i = 0; i < 3; i++) {
		delete robots[i];
		robots[i] = new Robot(
			random.Next(0, conSizeX - 15),		//x
			random.Next(0, conSizeY - 6),		//y
			random.Next(1, 3) % 2 == 0 ? 1 : -1,	//dx
			random.Next(1, 3) % 2 == 0 ? 1 : -1,	//dy
			conSizeX - 7,										//lx
			conSizeY,											//ly
			getRandomColor());									//color
		Sleep(waitTime / 2);	//necesario, si no random.next no es suficientemente aleatorio
	}
	puerta->editSprite("|EXIT|", 1);
	puerta->setColor(ConsoleColor::Green);
	jugador->resetPosition();
	jugador->setInvencible(true);


	//Bucle Segunda parte del nivel
	system("cls");
	while (true) {
		puerta->draw();

		//movimiento de robots
		for (int i = 0; i < 3; i++) {
			robots[i]->clear();
			robots[i]->autoMove();
			robots[i]->draw();

			//Colisiones
			jugador->collideEnemy(robots[i]->getRectagle()); //Comentar para desactivar colisiones
			if(jugador->getVidas() <= 0) {
				system("cls");
				cout << "GAME OVER" << endl;
				Sleep(1000);
				system("pause");
				primerNivel(); //Reiniciar nivel
				goto end;
			}
		}

		//Codigo del jugador aquí
		char tecla = ' ';
		if (_kbhit()) {
			tecla = _getch();
			jugador->clear();
			jugador->inputMove(tecla);

			if(jugador->getRectagle().IntersectsWith(puerta->getRectagle())) {
				Sleep(1000);
				break; //terminar bucle y pasar a siguiente fase
			}

			if(tecla == 27) { //ESCAPE
				goto end;
			}
		}
		jugador->draw();

		Sleep(waitTime);
	}

	//Cinematica entrega de llave
	sequence_Llave();
	sequence_SahurMalo();

	//Liberacion de memoria al finalizar el nivel
	end:
	delete jugador;
	delete puerta;
	for (int i = 0; i < 3; i++) {
		delete robots[i];
	}
	delete[] robots;
	cout << "Nivel completado, memoria liberada!" << endl;
	return;
}