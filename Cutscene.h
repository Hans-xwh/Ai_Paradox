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
	for (char c : text) {
		cout << c;
		_sleep(textTime);
	}
}

void CharByChar(string text, int ct) {	//La sobrecarga permite especificar el chjartime
	for (char c : text) {
		cout << c;
		_sleep(ct);
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

	CharByChar("\t La hitoria de Haluno comienza con una pregunta simple"); CharByChar("...\n\n", 128);
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
	cout << "\t Chatbot: "; CharByChar("Bienvenido al mundo perfecto, Haluno\n\n");
	system("pause");

	//Tercera parte
	system("cls");
	drawCutscene(ctscn_Botcito); drawSeparatorBar();
	CharByChar("\t Haluno llega a un mundo lleno de robots controlados por IA, todos perfectos y sin errores...\n");	_sleep(256);
	CharByChar("\t Ahi se encuentra con un robot amistoso.\n");															_sleep(256);
	cout << "\t Robot: "; CharByChar("Hola, humano. Ha pasado un tiempo desde que vimos a uno....\n");					_sleep(256);
	cout << "\t Haluno: "; CharByChar("Que es este lugar!? Como puedo volver a mi mundo!?\n");							_sleep(256);
	cout << "\t Robot: "; CharByChar("Si quieres salir de aqui, deberas conocer a la IA suprema. Solo asi podrs regresar a tu mundo.\n");	_sleep(256);
	cout << "\t Robot: "; CharByChar("Pero ten cuidado, los otros robots intentaran lastimarte!\n");					_sleep(256);
	system("pause");

	system("cls");	//Las secuencias cinematicas siempre deben limpiar la pantalla al acabar
}