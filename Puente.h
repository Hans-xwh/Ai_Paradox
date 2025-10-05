#pragma once
#include "Laberinto.h"
#include "Utils.h"
#include "Cutscene.h"

#include <vector>
 
// PUENTE
int PuenteMatriz[35][117] = {

{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,6,6,6,6,6,6,6,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,6,6,6,6,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,6,6,6,6,6,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,6,6,8,6,6,6,6,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,8,6,6,6,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,6,6,6,8,6,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,0,0,13,0,0,0,0,0,0,13,13,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,6,6,6,8,6,6,8,6,6,1,0,0,0,0,0,0,0,0,1,6,6,8,6,6,6,8,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,6,8,6,6,8,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,12,13,0,0,0,13,12,13,0,0,0,13,12,12,13,13,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,6,8,6,6,6,6,8,6,6,1,0,0,0,0,0,0,0,0,1,6,6,8,6,6,6,6,8,6,1,0,0,0,0,0,0,0,0,1,6,6,6,8,6,6,6,8,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,12,12,13,13,13,12,12,13,13,13,13,12,12,12,12,13,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,13,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,13,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,2,2,2,2,2,2,2,2,2,2,2,2,2,12,12,13,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,20,5,5,5,5,5,0,0,0,0,0,0,0,0,5,5,5,5,5,40,5,5,5,5,5,0,0,0,0,0,0,0,0,5,5,5,5,5,6,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,13,7,7,7,7,7,7,7,7,7,7,2,2,12,12,13,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,7,7,0,0,0,0,0,2,2,2,13,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,7,0,7,0,0,0,0,7,0,7,0,2,2,7,13,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,0,11,11,0,0,0,0,0,2,2,13,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,6,6,6,6,8,1,1,1,0,0,0,0,0,0,0,0,1,1,1,8,6,6,6,6,1,1,1,0,0,0,0,0,0,0,0,1,1,1,6,8,6,6,6,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,7,7,7,7,11,11,7,7,7,7,7,7,2,13,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,6,6,6,6,6,6,6,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,6,6,6,6,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,6,6,6,6,6,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,7,7,7,7,7,7,7,7,7,7,7,7,13,0,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,6,6,8,6,6,6,6,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,8,6,6,6,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,6,6,6,8,6,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,7,7,7,11,11,11,11,7,7,7,7,7,13,0,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,6,6,6,8,6,6,8,6,6,1,0,0,0,0,0,0,0,0,1,6,6,8,6,6,6,8,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,6,8,6,6,8,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,13,13,7,7,7,7,7,7,7,13,13,13,0,0,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,6,8,6,6,6,6,8,6,6,1,0,0,0,0,0,0,0,0,1,6,6,8,6,6,6,6,8,6,1,0,0,0,0,0,0,0,0,1,6,6,6,8,6,6,6,8,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,8,8,8,7,7,7,7,7,8,8,13,13,13,0,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,8,8,8,8,8,8,8,8,8,8,8,8,8,13,13,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,20,5,5,5,5,5,0,0,0,0,0,0,0,0,5,5,5,5,5,40,5,5,5,5,5,0,0,0,0,0,0,0,0,5,5,5,5,5,6,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,6,6,6,6,8,1,1,1,0,0,0,0,0,0,0,0,1,1,1,8,6,6,6,6,1,1,1,0,0,0,0,0,0,0,0,1,1,1,6,8,6,6,6,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,6,6,6,6,6,6,8,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,6,6,6,6,8,6,1,0,0,0,0,0,0,0,0,1,6,6,6,8,6,6,6,8,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,6,8,6,6,6,8,6,6,6,1,0,0,0,0,0,0,0,0,1,6,6,8,6,6,6,6,8,6,1,0,0,0,0,0,0,0,0,1,6,6,6,8,6,6,6,8,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,6,8,6,6,6,6,8,6,6,1,0,0,0,0,0,0,0,0,1,6,6,8,6,6,6,8,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,8,6,6,6,8,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,6,6,6,6,6,6,8,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,6,6,6,6,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,8,6,6,6,8,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,6,8,6,6,6,6,8,6,6,1,0,0,0,0,0,0,0,0,1,6,6,8,6,6,6,6,8,6,1,0,0,0,0,0,0,0,0,1,6,6,6,8,6,6,6,8,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,6,6,6,6,6,6,6,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,6,6,6,6,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,6,6,6,6,6,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},

};


// DIBUJAR PUENTE

void drawPuente() {
    Console::SetCursorPosition(0, 0);
    for (int i = 0; i < 35; i++) {

        for (int j = 0; j < 115; j++) {
            ANSIReset();

            switch (PuenteMatriz[i][j]) {
            case 10:             
                cout << char(219);
                break;
            case 0:
                ANSIForeColor(0);
                cout << char(219);
                break;
            case 1:
                cout << char(219);  //BLANCO
                break;
            case 6:
                ANSIForeColor(87);
                cout << char(219);
                break;
            case 2:
                ANSIForeColor(237);
                cout << char(219);
                break;
            case 3:
                ANSIForeColor(5);
                cout << char(219);
                break;
            case 9:
                ANSIForeColor(7);
                cout << char(219);
                break;
            case 4:
                ANSIForeColor(254);
                cout << char(219);
                break;
            case 5:
                ANSIForeColor(130);
                cout << char(219);
                break;
            case 7:
                ANSIForeColor(216);
                cout << char(219);
                break;
            case 8:
                ANSIForeColor(6);
                cout << char(219);
                break;
            case 11:
                ANSIForeColor(209);
                cout << char(219);
                break;
            case 12:
                ANSIForeColor(220);
                cout << char(219);
                break;
            case 13:
                ANSIForeColor(231);
                cout << char(219);
                break;

      
            /*/ 2:
                ANSIForeColor(46);
                cout << "W"; // PREGUNTA FACIL
                break;
            case 4:
                ANSIForeColor(196);
                cout << "X"; // PREGUNTA INTERMEDIA
                break;
            case 6:
               ANSIForeColor(51);
                cout << "O";  // PREGUNTA DIFICIL
                break;*/
            default:
                cout << " ";
                break;
            }
        }
        cout << endl;
    }
    ANSIReset();
}

//////////////
bool facilpregunta1();
bool intermediapregunta1();
bool dificilpregunta1();
/////////////////

void Puente() {
    drawPuente(); //DIBUJAMOS EL PUENTE

    bool jugar = true;
    while (jugar == true) {

        if (_kbhit()) {
            char tecla = toupper(_getch());

            int EQUIS = Personaje.X;
            int EYE = Personaje.Y;

            switch (tecla) {
            case 'W': EYE--;
                break;
            case 'S': EYE++;
                break;
            case 'A': EQUIS--;
                break;
            case 'D': EQUIS++;
                break;
            }

            bool autorizacion = true;
            bool facilpregunta = false;
            bool intermediapregunta = false;
            bool dificilpregunta = false;
            bool ganaste = false;
             for (int x = 0; x < Personaje.ancho; x++) {
                for (int y = 0; y < Personaje.altura; y++) {
                    int punto = PuenteMatriz[EYE + y][EQUIS + x];
                    //autorizacion para que no traspase
                    if (punto == 1) autorizacion = false;
                    else if (punto == 20) facilpregunta = true;
                    else if (punto == 40) intermediapregunta = true;
                    else if (punto == 6) dificilpregunta = true;
                    //
                    else if (punto == 13) ganaste = true;
                 }
            }
            if (autorizacion) {
                borrarPersonaji();
                Personaje.X = EQUIS;
                Personaje.Y = EYE;
            }
            if (facilpregunta) {
                facilpregunta1();
            }
            if (intermediapregunta) {
                dificilpregunta1();
            }
            if (dificilpregunta) {
                dificilpregunta1();
            }
            if (ganaste) {
                system("cls");
                GanoSegunoNivel();
            }
        }

        dibujarPersonaji(); //DIBUJAMOS EL PERSONAJE AL FINAL PARA EVITAR PARPADEO
        contextoSegundoNivel(); //DA CONTEXTO 
        Sleep(waitTime);	//Recomendable usar la variable waitTime de Utils.h en su lugar. -H
    }


}
bool facilpregunta1() {
    vector<string> preguntasfaciles = {
            "Tienes las respuestas frente a ti. Nadie te mira. -Copiar esta bien?"
           ,"Sabes mas que los demas, y empiezas a sentirte superior. -Saber mas, te hace mas?"
           ,"Estas a punto de perder. Una mentira podria darte la victoria. -Mentirias por ganar?"
           ,"Hiciste algo malo, pero crees que fue por una buena causa. -El fin justifica los medios?"
           ,"Una persona que antes te ignoro ahora necesita tu apoyo. -Ayudarias a alguien que no te ayudo?"
    };

    vector<string> respuestasfaciles = {
        "no", "no", "no", "no", "si"
    };

    int aleatorio = rand() % 5; //REOCRRE LAS 5 PREGUNTAS Y ELIGE UNA AL AZAR
    string rpta;

    int Xp = 5, Yp = 34;

    Console::SetCursorPosition(Xp, Yp);
    cout << preguntasfaciles[aleatorio];
    Console::SetCursorPosition(Xp, Yp + 2);
    cout << "RESPUESTA: ";
    cin >> rpta;

    for (char& a : rpta)  a = toupper(a);
    string correcta = respuestasfaciles[aleatorio];
    for (char& a : correcta) a = toupper(a);

    if (rpta == correcta) {
        Console::SetCursorPosition(Xp, Yp + 4);
        cout << "BIEN BRO!:)" << endl;
        Personaje.X += 5; //SE MUEVE 5 A LA DERECHA
        system("pause");

        return true;
    }
    else {
        Console::SetCursorPosition(Xp, Yp + 4);
        cout << "MAL BRO!:(" << endl;
        Personaje.X -= 5; //SE MUVE A LA IZQUIERDA (PORQUE RESPONDIO MAL EL BRO)
        system("pause");
        return false;
    }
    EraseDialog();
}

bool intermediapregunta1() {
    vector<string> preguntasintermedias = {
    "-Cambiarias tus valores por dinero?",
    "-Mentirías para proteger a un amigo?",
    "-El poder corrompe?",
    "-El fin justifica los medios?",
    "-Perdonarias una traicion?"
    };
    vector<string> respuestasintermedias = {
         "no", "no", "si", "no", "si"
    };

    int aleatorio = rand() % 5; //REOCRRE LAS 5 PREGUNTAS Y ELIGE UNA AL AZAR
    string rpta;

    int Xp = 5, Yp = 34;

    Console::SetCursorPosition(Xp, Yp);
    cout << preguntasintermedias[aleatorio];
    Console::SetCursorPosition(Xp, Yp + 2);
    cout << "RESPUESTA: ";
    cin >> rpta;

    for (char& a : rpta)  a = toupper(a);
    string correcta = respuestasintermedias[aleatorio];
    for (char& a : correcta) a = toupper(a);

    if (rpta == correcta) {
        Console::SetCursorPosition(Xp, Yp + 4);
        cout << "EXCELENTE BRO!:)" << endl;
        Personaje.X += 5; //SE MUEVE 5 A LA DERECHA
        system("pause");
        return true;
    }
    else {
        Console::SetCursorPosition(Xp, Yp + 4);
        cout << "MAL BRO, SIGUE REFLEXIONANDO!:(" << endl;
        Personaje.X -= 5; //SE MUVE A LA IZQUIERDA (PORQUE RESPONDIO MAL EL BRO)
        system("pause");
        return false;
    }

    EraseDialog();
}

bool dificilpregunta1() {

    // FALTA CAMBIAR LAS PREGUNTAS A DIFICLES (SON LAS INTERMEDIAS)
    vector<string> preguntasdificiles = {
        "-El perdon libera mas al que lo da que al que lo recibe?",
        "-El conocimiento sin valores puede ser peligroso?",
        "-El miedo puede ser un maestro?",
        "-Cambiar duele, pero es necesario?",
        "-A veces perder es tambien ganar?"
    };
    vector<string> respuestasdificiles = {
        "si", "si", "si", "si", "si"
    };

    int aleatorio = rand() % 5; //RECORRELAS 5 PREGUNTAS Y ELIGE UNA AL AZAR
    string rpta;

    int Xp = 5, Yp = 34;

    Console::SetCursorPosition(Xp, Yp);
    cout << preguntasdificiles[aleatorio];
    Console::SetCursorPosition(Xp, Yp + 2);
    cout << "RESPUESTA: ";
    cin >> rpta;

    for (char& a : rpta)  a = toupper(a);
    string correcta = respuestasdificiles[aleatorio];
    for (char& a : correcta) a = toupper(a);

    if (rpta == correcta) {
        Console::SetCursorPosition(Xp, Yp + 4);
        cout << "BIEN BRO, ERES SINCERO!:)" << endl;
        Personaje.X += 5; //SE MUEVE 5 A LA DERECHA
        system("pause");
        return true;
    }
    else {
        Console::SetCursorPosition(Xp, Yp + 4);
        cout << "MAL BRO!:(" << endl;
        Personaje.X -= 5; //SE MUVE A LA IZQUIERDA (PORQUE RESPONDIO MAL EL BRO)
        system("pause");
        return false;
    }

    EraseDialog();
}

/*void color(int c)
{
    switch (c)
    {
    case 1: Console::ForegroundColor = ConsoleColor::Black; break;
    case 2: Console::ForegroundColor = ConsoleColor::DarkBlue; break;
    case 3: Console::ForegroundColor = ConsoleColor::DarkGreen; break;
    case 4: Console::ForegroundColor = ConsoleColor::DarkRed; break;
    case 5: Console::ForegroundColor = ConsoleColor::DarkMagenta; break;
    case 6: Console::ForegroundColor = ConsoleColor::DarkYellow; break;
    case 7: Console::ForegroundColor = ConsoleColor::Gray; break;
    case 8: Console::ForegroundColor = ConsoleColor::DarkGray; break;
    case 9: Console::ForegroundColor = ConsoleColor::Blue; break;
    case 10: Console::ForegroundColor = ConsoleColor::Green; break;
    case 11: Console::ForegroundColor = ConsoleColor::Cyan; break;
    case 12: Console::ForegroundColor = ConsoleColor::Red; break;
    case 13: Console::ForegroundColor = ConsoleColor::Magenta; break;
    case 14: Console::ForegroundColor = ConsoleColor::Yellow; break;
    case 15: Console::ForegroundColor = ConsoleColor::White; break;
    }
}


void genera_pantallaDerrota(int pantalla[FILAS][COLUMNAS])
{
    for (int f = 0; f < FILAS; f++)
    {
        for (int c = 0; c < COLUMNAS; c++)
        {
            cursor(c, f);
            if (pantalla[f][c] == 0) color(1);    // Negro
            if (pantalla[f][c] == 1) color(2);    // Azul oscuro
            if (pantalla[f][c] == 2) color(3);    // Verde oscuro
            if (pantalla[f][c] == 3) color(12);    // Rojo
            if (pantalla[f][c] == 4) color(15);    // Blanco
            if (pantalla[f][c] == 5) color(6);    // Amarillo oscuro
            if (pantalla[f][c] == 6) color(7);    // Gris
            if (pantalla[f][c] == 7) color(8);    // Gris oscuro
            if (pantalla[f][c] == 8) color(9);    // Azul
            if (pantalla[f][c] == 9) color(10);   // Verde
            if (pantalla[f][c] == 10) color(11);  // Cyan
            if (pantalla[f][c] == 11) color(14);  // Amarelo
            if (pantalla[f][c] == 12) color(13);  // Magenta
            if (pantalla[f][c] == 13) color(4);  // Rojo oscuro
            if (pantalla[f][c] == 14) color(5);  // BMagenta oscuro


            cout << (char)219;
        }
    }
}*/