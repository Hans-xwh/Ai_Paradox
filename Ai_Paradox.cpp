#include <conio.h>
#include <windows.h>
#include "primerNivel.h"
#include "SegundoNivel.h"
#include "TercerNivel.h"
#include "Cutscene.h"
#include "ImagenJugador.h"
#include "menu.h"

int main() {

    SetupConsole();
    menu();
    sequence_Intro();
    primerNivel();
    segundoNivel();
    //GanoPrimerNivel();
    //GanoSegunoNivel();
    minijuegoAutos();
    
    
    system("pause");
    return 0;



}