#include <conio.h>
#include <windows.h>

#include "primerNivel.h"
#include "Cutscene.h"

int main() {
    SetupConsole();

    //sequence_Llave();   system("pause");
	sequence_Intro();   //Cinematica de introduccion
    primerNivel();  //Sin terminar xd
    
    system("pause");
    return 0;

}