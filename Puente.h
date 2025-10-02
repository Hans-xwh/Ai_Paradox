#pragma once
#include "Laberinto.h"
#include "Utils.h"

#include <vector>

// PUENTE
int PuenteMatriz[35][115] = {

{ 9,9,9,9,9,9,9,9,9,9,9,9,9,7,1,1,1,1,1,1,1,1,1,7,9,9,9,9,9,9,9,9,7,1,1,1,1,1,1,1,1,1,7,9,9,9,9,9,9,9,9,7,1,1,1,1,1,1,1,1,1,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,7,1,1,8,1,1,1,1,1,1,7,9,9,9,9,9,9,9,9,7,1,1,1,8,1,1,1,1,1,7,9,9,9,9,9,9,9,9,7,1,1,1,1,1,1,8,1,1,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,7,1,1,1,8,1,1,8,1,1,7,9,9,9,9,9,9,9,9,7,1,1,8,1,1,1,8,1,1,7,9,9,9,9,9,9,9,9,7,1,1,1,1,8,1,1,8,1,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,7,1,8,1,1,1,1,8,1,1,7,9,9,9,9,9,9,9,9,7,1,1,8,1,1,1,1,8,1,7,9,9,9,9,9,9,9,9,7,1,1,1,8,1,1,1,8,1,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,7,1,1,1,1,1,1,1,1,1,7,9,9,9,9,9,9,9,9,7,1,1,1,1,1,1,1,1,1,7,9,9,9,9,9,9,9,9,7,1,1,1,1,1,1,1,1,1,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,7,0,0,0,0,0,0,0,0,0,7,9,9,9,9,9,9,9,9,7,0,0,0,0,0,0,0,0,0,7,9,9,9,9,9,9,9,9,7,0,0,0,0,0,0,0,0,0,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,9,0,9,9,9,9,9,9,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,0,5,5,5,5,5,5,5,5,5,0,9,9,9,9,9,9,9,9,0,5,5,5,5,5,5,5,5,5,0,9,9,9,9,9,9,9,9,0,5,5,5,5,5,5,5,5,5,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,4,0,4,0,9,9,9,9,9,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,5,5,5,5,5,2,5,5,5,5,5,9,9,9,9,9,9,9,9,5,5,5,5,5,6,5,5,5,5,5,9,9,9,9,9,9,9,9,5,5,5,5,5,4,5,5,5,5,5,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,3,0,3,0,9,9,9,9,9,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,5,5,5,5,5,5,5,5,5,5,5,9,9,9,9,9,9,9,9,5,5,5,5,5,5,5,5,5,5,5,9,9,9,9,9,9,9,9,5,5,5,5,5,5,5,5,5,5,5,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,3,0,3,0,9,9,9,9,9,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,5,5,0,0,0,0,0,0,0,5,5,9,9,9,9,9,9,9,9,5,5,0,0,0,0,0,0,0,5,5,9,9,9,9,9,9,9,9,5,5,0,0,0,0,0,0,0,5,5,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,4,4,4,4,0,9,9,9,9,9,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,0,0,1,1,8,1,1,8,1,0,0,9,9,9,9,9,9,9,9,0,0,1,8,1,1,1,8,1,0,0,9,9,9,9,9,9,9,9,0,0,1,1,1,8,1,1,8,0,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,4,4,0,4,4,4,0,0,0,9,0,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,7,1,8,1,1,1,1,8,1,1,7,9,9,9,9,9,9,9,9,7,1,1,8,1,1,1,1,8,1,7,9,9,9,9,9,9,9,9,7,1,1,1,8,1,1,1,8,1,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,4,4,0,4,4,4,4,4,4,0,4,0,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,7,1,1,1,1,1,1,1,1,1,7,9,9,9,9,9,9,9,9,7,1,1,1,1,1,1,1,1,1,7,9,9,9,9,9,9,9,9,7,1,1,1,1,1,1,1,1,1,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,3,4,4,4,4,4,4,4,4,4,0,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,7,1,1,8,1,1,1,1,1,1,7,9,9,9,9,9,9,9,9,7,1,1,1,8,1,1,1,1,1,7,9,9,9,9,9,9,9,9,7,1,1,1,1,1,1,8,1,1,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,4,4,4,4,0,4,4,4,4,4,0,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,7,1,1,1,8,1,1,8,1,1,7,9,9,9,9,9,9,9,9,7,1,1,8,1,1,1,8,1,1,7,9,9,9,9,9,9,9,9,7,1,1,1,1,8,1,1,8,1,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,0,0,0,4,4,4,4,4,4,0,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,7,1,8,1,1,1,1,8,1,1,7,9,9,9,9,9,9,9,9,7,1,1,8,1,1,1,1,8,1,7,9,9,9,9,9,9,9,9,7,1,1,1,8,1,1,1,8,1,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,4,4,4,4,0,4,4,4,0,2,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,7,1,1,1,1,1,1,1,1,1,7,9,9,9,9,9,9,9,9,7,1,1,1,1,1,1,1,1,1,7,9,9,9,9,9,9,9,9,7,1,1,1,1,1,1,1,1,1,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,4,4,0,0,4,4,4,0,2,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,7,0,0,0,0,0,0,0,0,0,7,9,9,9,9,9,9,9,9,7,0,0,0,0,0,0,0,0,0,7,9,9,9,9,9,9,9,9,7,0,0,0,0,0,0,0,0,0,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,0,0,2,0,0,0,0,2,9,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,0,5,5,5,5,5,5,5,5,5,0,9,9,9,9,9,9,9,9,0,5,5,5,5,5,5,5,5,5,0,9,9,9,9,9,9,9,9,0,5,5,5,5,5,5,5,5,5,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,5,5,5,5,5,4,5,5,5,5,5,9,9,9,9,9,9,9,9,5,5,5,5,5,2,5,5,5,5,5,9,9,9,9,9,9,9,9,5,5,5,5,5,4,5,5,5,5,5,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,5,5,5,5,5,5,5,5,5,5,5,9,9,9,9,9,9,9,9,5,5,5,5,5,5,5,5,5,5,5,9,9,9,9,9,9,9,9,5,5,5,5,5,5,5,5,5,5,5,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,5,5,0,0,0,0,0,0,0,5,5,9,9,9,9,9,9,9,9,5,5,0,0,0,0,0,0,0,5,5,9,9,9,9,9,9,9,9,5,5,0,0,0,0,0,0,0,5,5,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,0,0,1,1,8,1,1,8,1,0,0,9,9,9,9,9,9,9,9,0,0,1,8,1,1,1,8,1,0,0,9,9,9,9,9,9,9,9,0,0,1,1,1,8,1,1,8,0,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
{ 9,9,9,9,9,9,9,9,9,9,9,9,9,7,1,8,1,1,1,1,8,1,1,7,9,9,9,9,9,9,9,9,7,1,1,8,1,1,1,1,8,1,7,9,9,9,9,9,9,9,9,7,1,1,1,8,1,1,1,8,1,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
 };

// DIBUJAR PUENTE

void drawPuente() {
    Console::SetCursorPosition(0, 0);
    for (int i = 0; i < 35; i++) {

        for (int j = 0; j < 115; j++) {
            ANSIReset();

            switch (PuenteMatriz[i][j]) {
            case 1:
                cout << char(219);
                break;
            case 0:
                cout << " ";
                break;
            case 2:
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
                break;
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

            for (int x = 0; x < Personaje.ancho; x++) {
                for (int y = 0; y < Personaje.altura; y++) {
                    int punto = PuenteMatriz[EYE + y][EQUIS + x];

                    if (punto == 1) autorizacion = false;
                    if (punto == 2) facilpregunta = true;
                    if (punto == 4) intermediapregunta = true;
                    if (punto == 6) dificilpregunta = true;
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
        }

        dibujarPersonaji(); //DIBUJAMOS EL PERSONAJE AL FINAL PARA EVITAR PARPADEO
        Sleep(waitTime);	//Recomendable usar la variable waitTime de Utils.h en su lugar. -H
    }


}


bool facilpregunta1() {
    vector<string> preguntasfaciles = {
        "CUANTO ES 3 + 2?", "CUANTO ES 5 + 1?", "CUANTO ES 1 +2?", "CUANTO ES 8 + 0?", "CUANTO ES 4 + 1"
    };
    vector<string> respuestasfaciles = {
        "5", "6", "3", "8", "5"
    };

    int aleatorio = rand() % 5; //REOCRRE LAS 5 PREGUNTAS Y ELIGE UNA AL AZAR
    string rpta;

    int Xp = 50, Yp = 36;

    Console::SetCursorPosition(Xp, Yp);
    cout << preguntasfaciles[aleatorio];
    Console::SetCursorPosition(Xp, Yp + 1);
    cout << "RESPUESTA: ";
    cin >> rpta;

    for (char& a : rpta)  a = toupper(a);
    string correcta = respuestasfaciles[aleatorio];
    for (char& a : correcta) a = toupper(a);

    if (rpta == correcta) {
        Console::SetCursorPosition(Xp, Yp + 2);
        cout << "BIEN BRO!:)" << endl;
        Personaje.X += 5; //SE MUEVE 5 A LA DERECHA
        system("pause");
        return true;
    }
    else {
        Console::SetCursorPosition(Xp, Yp + 2);
        cout << "MAL BRO!:(" << endl;
        Personaje.X -= 5; //SE MUVE A LA IZQUIERDA (PORQUE RESPONDIO MAL EL BRO)
        system("pause");
        return false;
    }

}

bool intermediapregunta1() {
    vector<string> preguntasintermedias = {
    "CUANTO ES 5 x 7?", "CUANTO ES 7 x 7?", "CUANTO ES 9 x 10?", "CUANTO ES 198 x 0", "CUANTO ES 6 x 9?"
    };
    vector<string> respuestasintermedias = {
        "35", "49", "90", "0", "54"
    };

    int aleatorio = rand() % 5; //REOCRRE LAS 5 PREGUNTAS Y ELIGE UNA AL AZAR
    string rpta;

    int Xp = 50, Yp = 36;

    Console::SetCursorPosition(Xp, Yp);
    cout << preguntasintermedias[aleatorio];
    Console::SetCursorPosition(Xp, Yp + 1);
    cout << "RESPUESTA: ";
    cin >> rpta;

    for (char& a : rpta)  a = toupper(a);
    string correcta = respuestasintermedias[aleatorio];
    for (char& a : correcta) a = toupper(a);

    if (rpta == correcta) {
        Console::SetCursorPosition(Xp, Yp + 2);
        cout << "BIEN BRO!:)" << endl;
        Personaje.X += 5; //SE MUEVE 5 A LA DERECHA
        system("pause");
        return true;
    }
    else {
        Console::SetCursorPosition(Xp, Yp + 2);
        cout << "MAL BRO!:(" << endl;
        Personaje.X -= 5; //SE MUVE A LA IZQUIERDA (PORQUE RESPONDIO MAL EL BRO)
        system("pause");
        return false;
    }


}

bool dificilpregunta1() {

    // FALTA CAMBIAR LAS PREGUNTAS A DIFICLES (SON LAS INTERMEDIAS)
    vector<string> preguntasdificiles = {
"CUANTO ES 5 x 7?", "CUANTO ES 7 x 7?", "CUANTO ES 9 x 10?", "CUANTO ES 198 x 0", "CUANTO ES 6 x 9?"
    };
    vector<string> respuestasdificiles = {
        "35", "49", "90", "0", "54"
    };

    int aleatorio = rand() % 5; //REOCRRE LAS 5 PREGUNTAS Y ELIGE UNA AL AZAR
    string rpta;

    int Xp = 50, Yp = 36;

    Console::SetCursorPosition(Xp, Yp);
    cout << preguntasdificiles[aleatorio];
    Console::SetCursorPosition(Xp, Yp + 1);
    cout << "RESPUESTA: ";
    cin >> rpta;

    for (char& a : rpta)  a = toupper(a);
    string correcta = respuestasdificiles[aleatorio];
    for (char& a : correcta) a = toupper(a);

    if (rpta == correcta) {
        Console::SetCursorPosition(Xp, Yp + 2);
        cout << "BIEN BRO!:)" << endl;
        Personaje.X += 5; //SE MUEVE 5 A LA DERECHA
        system("pause");
        return true;
    }
    else {
        Console::SetCursorPosition(Xp, Yp + 2);
        cout << "MAL BRO!:(" << endl;
        Personaje.X -= 5; //SE MUVE A LA IZQUIERDA (PORQUE RESPONDIO MAL EL BRO)
        system("pause");
        return false;
    }


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