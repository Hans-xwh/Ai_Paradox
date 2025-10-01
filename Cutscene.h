#pragma once

#include "ANSI_resources.h"
//No se uso el <locale> por q hace la impresion de secuencias ANSI 10 veces mas lenta

//Funciones para cinematicas
void drawCutscene(string* background) {
	for (int i = 0; i < CutsceneHeight; i++) {
		cout << background[i] << endl;
	}
}

void CharByChar(string text) {	//Usa charTime global
	int t = textTime;

	for (char c : text) {
		if (kbhit()) {
			t = 0;
		}

		cout << c;
		_sleep(t);
	}
}

void CharByChar(string text, int ct) {	//La sobrecarga permite especificar el chjartime
	int t = ct;

	for (char c : text) {
		if (kbhit()) {
			t = 0;
		}

		cout << c;
		_sleep(t);
	}
}

void drawSeparatorBar() {
	cout << string(conSizeX, '-');
}

void EraseDialog() {
	for (int i = 0; i < conSizeY - CutsceneHeight; i++) {
		Console::SetCursorPosition(0, CutsceneHeight + i);
		cout << string(conSizeX, ' ');
	}
	Console::SetCursorPosition(0, CutsceneHeight);
}


//Secuencias ciematicas
void sequence_Intro() {
	system("cls");
	drawCutscene(ctscn_Chatbot);
	drawSeparatorBar();

	CharByChar(" La hitoria de Haluno comienza con una pregunta simple"); CharByChar("...\n\n", 128);
	_sleep(256);
	cout << "\t Haluno: ";  CharByChar("Como es un mundo perfecto..?\n");  _sleep(512);
	cout << "\t Chatbot: ";  CharByChar("Un mundo sin errores, sin bugs.... sin humanos...\n");  _sleep(512);
	cout << "\t Chatbot: "; CharByChar("TE LO MOSTRARE\n\n", 128);
	_sleep(512);
	system("pause");
	
	//Segunda parte
	system("cls");
	drawCutscene(ctscn_Portal); drawSeparatorBar();

	CharByChar("\t El Chatbot abre un portal, y Haluno pasa por el...\n\n");
	cout << "\t Chatbot: "; CharByChar("Bienvenido al mundo perfecto, Haluno.\n\n");
	system("pause");

	//Tercera parte
	system("cls");
	drawCutscene(ctscn_Botcito); drawSeparatorBar();
	CharByChar(" Haluno llega a un mundo lleno de robots controlados por IA, todos perfectos y sin errores...\n");	_sleep(256);
	CharByChar(" Ahi se encuentra con un robot amistoso.\n");															_sleep(256);
	cout << "\t Robot: "; CharByChar("Hola, humano. Ha pasado un tiempo desde que vimos a uno....\n");					_sleep(256);
	cout << "\t Haluno: "; CharByChar("Que es este lugar!? Como puedo volver a mi mundo!?\n");							_sleep(256);
	cout << "\t Robot: "; CharByChar("Si quieres salir de aqui, deberas conocer a la IA suprema. Solo asi podras regresar a tu mundo.\n");	_sleep(256);
	cout << "\t Robot: "; CharByChar("Pero ten cuidado, los otros robots intentaran lastimarte!\n");					_sleep(256);
	system("pause");

	system("cls");	//Las secuencias cinematicas siempre deben limpiar la pantalla al acabar
}

void sequence_Llave() {
	system("cls");
	drawCutscene(ctscn_HumanoKey);
	drawSeparatorBar();

	CharByChar(" Tras superar a los robots, Haluno llega a la puerta que lleva a la IA suprema, donde se encuentra con otro humano...\n"); Sleep(512);
	cout << " \tHaluno: "; CharByChar("Otro humano!?"); Sleep(256); CharByChar(" Quien eres tu?\n"); Sleep(512);
	cout << " \tHumano aliado: "; CharByChar("Yo... no pude vencerla...\n"); Sleep(512);
	cout << " \tHumano aliado: "; CharByChar("Toma esta llave, la necesitaras\n"); Sleep(512);
	cout << " \tHumano aliado: "; CharByChar("*Se muere*\n\n"); Sleep(512);

	system("pause");
}