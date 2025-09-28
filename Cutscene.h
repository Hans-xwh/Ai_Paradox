#pragma once

#include "ANSI_resources.h"

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

void EraseCutscene() {
	system("cls");
}