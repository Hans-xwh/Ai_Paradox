#pragma once

#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace System;

//// Configuracion del juego ////
const int conSizeX = 120;	//Console size X
const int conSizeY = 49;	//Console size Y


void SetupConsole() {
	Console::SetWindowSize(conSizeX, conSizeY);
	Console::SetBufferSize(conSizeX, conSizeY);
	Console::CursorVisible = false;
	system("cls");	//Enables ANSI output codes
}
