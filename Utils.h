#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
using namespace System;

//// Configuracion del juego ////
const int conSizeX = 144;	//Console size X
const int conSizeY = 49;	//Console size Y
const int waitTime = 32;	//Tiempo para esperar despues de dibujar (cambiar despues por algun tipo de deltatime)
const int textTime = 32;	//Tiempo entre salidas de caracteres para el texto lento en dialogos.
const int CutsceneHeight = conSizeY - 9; //Altura del fondo de las cinematicas (deja espacio para el texto)


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

void ANSIForeColor(int n) {	//Cambia el color del texto al color ansi indicado (0-255)
	string ansi = "\x1b[38;5;";
	ansi += to_string(n) +'m';
	cout << ansi;
}

void ANSIBackColor(int n) {	//Cambia el color del fondo al color ansi indicado (0-255)
	string ansi = "\x1b[48;5;";
	ansi += to_string(n) +'m';
	cout << ansi;
}
