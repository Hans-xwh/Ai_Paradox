#include <conio.h>
#include <windows.h>
#include "primerNivel.h"
#include "SegundoNivel.h"
#include "TercerNivel.h"
#include "Cutscene.h"

int main() {
    SetupConsole();

    minijuegoAutos();
	//sequence_Intro();   //Cinematica de introduccion
    //primerNivel();  
    segundoNivel();     //Sin terminar xd4
    
    
    system("pause");
    return 0;



}