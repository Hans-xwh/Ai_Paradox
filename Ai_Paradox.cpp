#include <conio.h>
#include <windows.h>

#include "primerNivel.h"

int main() {
    SetupConsole();
    primerNivel();
 
    system("pause");
    return 0;

}


/*int main() {


        bool fuafua = false;

        if (jugador.getX() < robot1.getX() + robot1.getAncho() &&
            jugador.getX() + jugador.getAncho() > robot1.getX() &&
            jugador.getY() < robot1.getY() + robot1.getAlto() &&
            jugador.getY() + jugador.getAlto() > robot1.getY()) {
            fuafua = true;
        }

        else if (jugador.getX() < robot2.getX() + robot2.getAncho() &&
            jugador.getX() + jugador.getAncho() > robot2.getX() &&
            jugador.getY() < robot2.getY() + robot2.getAlto() &&
            jugador.getY() + jugador.getAlto() > robot2.getY()) {
            fuafua = true;
        }

        else if (jugador.getX() < robot3.getX() + robot3.getAncho() &&
            jugador.getX() + jugador.getAncho() > robot3.getX() &&
            jugador.getY() < robot3.getY() + robot3.getAlto() &&
            jugador.getY() + jugador.getAlto() > robot3.getY()) {
            fuafua = true;
        }

        if (fuafua) {
            jugador.explotar(); jugador.borrar(); vidas--; jugador.resetearPosicion(true);
            Sleep(500);
        }

}
*/