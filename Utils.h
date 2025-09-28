#pragma once

#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace System;

//// Configuracion del juego ////
const int conSizeX = 120;	//Console size X
const int conSizeY = 49;	//Console size Y
const int waitTime = 32;	//Tiempo para esperar despues de dibujar (cambiar despues por algun tipo de deltatime)


//// Funciones utiles ////
void SetupConsole() {
	while (true)
	{
		system("cls");	//Enables ANSI output codes
			
		try {
			Console::SetWindowSize(conSizeX, conSizeY);
			Console::SetBufferSize(conSizeX, conSizeY);
			Console::CursorVisible = false;
			break;
		}
		catch (...) {
			cout << "Tu consola es demasiado grande!" << endl;
			cout << "Usa CTRL + la rueda del mouse para reducirla y vuelvelo a intentar" << endl;
			system("pause");
		}
	}
}

ConsoleColor getRandomColor() {
	Random random;
	int colorIndex = random.Next(1, 16); // Excluye 0=negro (MODO RACISTA XD)

	return static_cast<ConsoleColor>(colorIndex); //GRACIAS COPILOT POR ESTO XD
}
