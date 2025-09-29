#include <conio.h>
#include <windows.h>

#include "primerNivel.h"
#include "Cutscene.h"

int main() {
    SetupConsole();

    sequence_Intro();
    primerNivel();  //Sin terminar xd
    
    system("pause");
    return 0;

}