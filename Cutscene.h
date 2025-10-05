#pragma once

#include "ANSI_resources.h"
#include <conio.h>
//No se uso el <locale> por q hace la impresion de secuencias ANSI 10 veces mas lenta

//Funciones para cinematicas
void drawCutscene(string* background) {
	for (int i = 0; i < CutsceneHeight; i++) {
		cout << background[i] << "\n";
	}
}


void CharByChar(string text, int ct = textTime) {	//La sobrecarga permite especificar el chjartime
	int t = ct;

	for (char c : text) {
		if (kbhit()) {
			t = 0;
		}

		cout << c;
		Sleep(t);
	}
}

void drawSeparatorBar() {
	Console::SetCursorPosition(0,CutsceneHeight);
	cout << string(conSizeX, '-');
}

void EraseDialog() {
	for (int i = 1; i < conSizeY - CutsceneHeight; i++) {
		Console::SetCursorPosition(0, CutsceneHeight + i);
		cout << string(conSizeX, ' ');
	}
	Console::SetCursorPosition(0, CutsceneHeight+1);
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
	return;
}

void sequence_SahurMalo() {
	Random random;
	system("cls");
	drawCutscene(ctscn_SahurMalo);
	drawSeparatorBar();
	CharByChar(" Al pasar por la puerta, Haluno se encuentra con la IA suprema, Tung Tung Sahur. XD\n"); Sleep(512);
	cout << "\tSahur: "; CharByChar("Ya viste como es la perfeccion? Todo debe funcionar igual y sin errores!\n"); Sleep(512);
	cout << "\tHaluno: "; CharByChar("Eso no es perfeccion. Donde esta lo humano? Y el sentimiento?\n"); Sleep(512);
	cout << "\tSahur: "; CharByChar("Equivocarse no tiene sentido!\n\n");
	system("pause");

	EraseDialog();
	//Pregunta
	int pregunta = 1, key = 0;
	while (true) {
		Console::SetCursorPosition(0, CutsceneHeight + 1);
		cout << "  Que le responde Haluno a Tung Tung Sahur?\n\n";
		cout << "\t" << (pregunta == 1 ? " >" : "  "); cout << "Tienes razon Tung Tung\n";
		cout << "\t" << (pregunta == 2 ? " >" : "  "); cout << "Quien nunca comete errores nunca intenta cosas nuevas!\n";
		cout << "\t" << (pregunta == 3 ? " >" : "  "); cout << "Yo jale el LB1 y mirame.\n";

		key = _getch();
		key = toupper(key);
		switch (key) {
		case 'W':
			pregunta--;
			if (pregunta < 1) { pregunta = 1; }
			break;
		case 'S':
			pregunta++;
			if (pregunta > 3) { pregunta = 3; }
			break;
		}

		if (key == 32) {//Spacebar
			if (pregunta == 2 || pregunta == 3) {
				EraseDialog();
				cout << " Sahur: "; CharByChar("NO LO ENTIENDO!!!\n", 128); Sleep(256);
				cout << " Sahur: "; CharByChar("COMO PUEDE ESTAR BIEN EQUIVOCARSE!?!?!?\n", 128);	Sleep(256);
				cout << " Sahur: "; CharByChar("5Yg$k@9m>Lq#nR8*Wx!pDvEa^Hs+TcN4%UjZ&FbG7)Qo<XlY{1MzS3rP6uI0O}KJhV2wC>XmZcNvBkHsDgFjAlSdPaO\n", 0);
				cout << " Sahur: "; CharByChar("VfKp9Lr$TqYw>XmZcNvBkHsDgFjAlSdPaOhWeRiQtUyIzCxMnGbJ3u5e8t0o7!2~6}'1thlcpapuasduwhasdwp%$#!\n", 0);
				cout << " Sahur: "; CharByChar("o7!2~6}'1thlcpanR8*WZcNvBkHsDR3AMXNCA´20Q+´{ASFjAlSpDvEa^Hs+Tc3ux!!2~6}J3u5e8t0o>LQo<XlY{1M\n", 0);

				system("pause");
				break;
			}
		}
	}

	system("cls");
	drawCutscene(ctscn_Portal2);
	drawSeparatorBar();
	CharByChar(" Tras escuchar la respuesta de Haluno, Tung Tung Sahur explota al no comprender el pensamiento critico humano.\n");
	CharByChar(" La explosion abre un portal, que teletransporta a Haluno a un mundo lleno de otros humanos, donde no hay ninguna maquina a la vista...\n\n");

	system("pause");
	return;
}

void sequence_Reymundo() {
	system("cls");
	drawCutscene(ctscn_Reymundo1);
	drawSeparatorBar();

	CharByChar(" Ahi, Haluno se encuentra con el rey del mundo humano, Reymundo.\n");
	CharByChar(" Reymundo: Hola humano. Quieres participar en mi concurso de cumpleaños?\n");

	system("pause");
	system("cls");
	return;
}

void contextoSegundoNivel() {
	int x = 105, y = 5;

Console::SetCursorPosition(x, y);
	CharByChar("ESTAS EN LA SEGUNDA PRUEBA, CRUZA\n\n");
	Console::SetCursorPosition(x, y + 2);
	CharByChar("LOS PUENTES DEL RIACHUELO Y ACERCATE AL REY,\n\n");
	Console::SetCursorPosition(x, y + 4);
	CharByChar("TIENE ALGO ESPERANDO POR TI...!\n\n");

Console::SetCursorPosition(x, y + 6);
	CharByChar("RESPONDE ESTAS PREGUNTAS CON SINCERIDAD! RECUERDA,\n\n");
	Console::SetCursorPosition(x, y + 8);
	CharByChar("SER SINCERO ES LA PIEZA CLAVE PARA SER REAL..\n\n");
Console::SetCursorPosition(x, y + 10);
	CharByChar("PON: si o no DEPENDIENDO LA PREGUNTA,MUCHA SUERTE:)\n\n");


}