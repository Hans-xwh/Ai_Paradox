#include <conio.h>
#include <windows.h>

#include "primerNivel.h"
#include "Cutscene.h"

int main() {
    SetupConsole();

    drawCutscene(ctscn_Chatbot); system("pause"); system("cls");
    drawCutscene(ctscn_Botsito); system("pause"); system("cls");
    drawCutscene(ctscn_Portal); system("pause"); system("cls");
    drawCutscene(ctscn_SahurMalo); system("pause"); system("cls");
	

    primerNivel();
 
    system("pause");
    return 0;

}