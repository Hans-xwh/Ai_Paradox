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
	Console::SetWindowSize(conSizeX, conSizeY);
	Console::SetBufferSize(conSizeX, conSizeY);
	Console::CursorVisible = false;
	system("cls");	//Enables ANSI output codes
}

ConsoleColor getRandomColor() {
	Random random;
	int colorIndex = random.Next(1, 16); // Excluye 0=negro (MODO RACISTA XD)

	return static_cast<ConsoleColor>(colorIndex); //GRACIAS COPILOT POR ESTO XD
}
