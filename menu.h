#pragma once
#include <iostream>
#include "Entidad.h"
#include <windows.h>
#include <conio.h>
#include "Utils.h"

void TextoChvr(string txt[]) {
	int offset = (conSizeX/2) - txt[0].length()/2;

	for (int i = 0; i < 5; i++) {
		Console::SetCursorPosition(offset, i+1);
		for (char c : txt[i]) {
			if (c == '#') {
				cout << char(219);
			}
			else {
				cout << ' ';
			}
		}
		cout << "\n";
	}
}

void centrado(string txt) {
	int offest((conSizeX / 2) - (txt.length() / 2));
	cout << string(offest, ' ');
	cout << txt;
}

void carga(int durseg = 5) {
	const int ancho = 40;

	cout << "\nCARGANDO.. [";
	cout.flush();

	//int sleepttime = durseg * 1000 / ancho;
	int sleepttime = 20;

	for (int i = 0; i <= ancho; i++) 
	{
		ANSIForeColor(196);
		cout << "#";
		cout.flush();
		Sleep(sleepttime);
	}
	ANSIForeColor(15);
	cout << "] \n\n\nLISTOOOO!" << endl;
}

void CreditosHLN() {

	system("cls");

	cout << endl;
	ANSI_ForeRGB(0, 154, 255);
	string creditos[5] = {
"###### ######  ####### ######  ## ########  ######  ####### ",
"##      ##   ## ##      ##   ## ##    ##    ##    ## ##	 ",
"##      ######  #####   ##   ## ##    ##    ##    ## #######",
"##      ##   ## ##      ##   ## ##    ##    ##    ##      ##",
" ###### ##   ## ####### ######  ##    ##     ######  #######"
	};
	TextoChvr(creditos);
	ANSIReset();
                                                             
	cout << endl;
	centrado("HANS WALTER\n");
	centrado("NOELIA BETETA\n");
	centrado("LUIS CALLE\n");
	cout << endl;
	centrado("PRESIONE UNA TECLA PARA VOLVER AL MENU\n");

	_getch();
}

void Instrucciones() {
	system("cls");

	cout << endl;
	ANSI_ForeRGB(0, 154, 255);
	string instrucciones[5] = {
"## ###    ## ####### ######## ######  ##    ##  ######  ###### ##  ######  ###    ## ####### #######",
"## ####   ## ##         ##    ##   ## ##    ## ##      ##      ## ##    ## ####   ## ##      ##	 ",
"## ## ##  ## #######    ##    ######  ##    ## ##      ##      ## ##    ## ## ##  ## #####   #######",
"## ##  ## ##      ##    ##    ##   ## ##    ## ##      ##      ## ##    ## ##  ## ## ##           ##",
"## ##   #### #######    ##    ##   ##  ######   ######  ###### ##  ######  ##   #### ####### #######"
	};
	TextoChvr(instrucciones);
	ANSIReset();

	cout << endl;
	centrado("USA W/S/A/D para MOVERTE.\n");
	centrado("Espacio para SELECCIONAR.\n");
	centrado("PASA NIVELES..\n");
	centrado("RESPONDE PREGUNTAS..\n");
	cout << endl;
	centrado("PRESIONE UNA TECLA PARA VOLVER AL MENU..\n");

	_getch();

}

void menu() {
	int op = 0;
	do {
		system("cls");
		ANSI_ForeRGB(0, 154, 255);
		cout << endl;
		string AI_Paradox[5] = {
"########### ####     ########   #######  ########   #######  ########   ########  ####   ##",
"####   #### ####     ####   ## ####   ## ####   ## ####   ## ####   ## ####    ##  #### ##	",
"########### ####     ########  ######### #######   ######### ####   ## ####    ##   #####	",
"####   #### ####     ####      ####   ## ####   ## ####   ## ####   ## ####    ##  ## ####	",
"####   #### ####     ####      ####   ## ####   ## ####   ## ########   ########  ##   ####"

		};
		TextoChvr(AI_Paradox);

		ANSIReset();
		cout << endl << endl << endl;
		centrado("                 ........................                 \n");
		centrado("                 |   ELIGE UNA OPCION:  |                 \n");
		centrado(" ----------------|----------------------|---------------- \n");
		centrado("\\................|  1. JUGAR            |.............../ \n");
		centrado("  \\..............|  2. INSTRUCCIONES    |............./   \n");
		centrado("    \\-----------.|  3. CREDITOS         |-----------/     \n");
		centrado("                 |  4. SALIR            |                 \n");
		centrado("                 |                      |                 \n");
		centrado("                 .----------------------.                 \n");
		centrado("                           /\\                            \n");
		centrado("");
		cin >> op;

		switch (op) {
		case 1: system("cls");
			carga(5);
			return;
			break;
		case 2: Instrucciones();
			break;
		case 3: CreditosHLN();
			break;
		case 4: system("cls");
			exit(0);
			break;
		default:
			cout << "INVALIDO. INTENTA DE NUEVO..";
			_getch();
			break;

		}
	} while (1);
}