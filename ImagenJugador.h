#pragma once

#include <string>
using namespace std;

string MiniPersonaje[4] = {
		" O ",
		"[|]",
		"d|b",
		"L|L",
};

struct ImagenJugador {
    const int length = 8;
    string image[8] = {
"  \x1b[48;2;50;20;9m \x1b[48;2;104;43;24m \x1b[48;2;56;20;8m \x1b[48;2;132;56;42m \x1b[48;2;80;30;19m \x1b[48;2;162;67;39m \x1b[48;2;62;25;16m \x1b[48;2;77;31;18m \x1b[m",
"\x1b[48;2;49;22;13m \x1b[48;2;84;29;9m \x1b[48;2;83;23;13m \x1b[48;2;133;55;33m \x1b[48;2;100;41;23m \x1b[48;2;106;40;18m \x1b[48;2;135;56;26m \x1b[48;2;101;43;23m \x1b[48;2;208;87;56m \x1b[48;2;165;65;39m \x1b[48;2;165;67;44m \x1b[48;2;57;22;18m \x1b[m",
" \x1b[48;2;51;21;10m \x1b[48;2;97;44;28m \x1b[48;2;131;56;33m \x1b[48;2;50;23;12m \x1b[48;2;221;121;95m \x1b[48;2;247;237;235m \x1b[48;2;72;63;56m \x1b[48;2;232;118;81m \x1b[48;2;37;26;24m \x1b[48;2;62;33;25m \x1b[m",
"  \x1b[48;2;34;35;37m \x1b[48;2;120;133;165m \x1b[48;2;147;166;199m \x1b[48;2;64;22;8m \x1b[48;2;232;117;86m \x1b[48;2;235;116;86m \x1b[48;2;242;114;75m \x1b[48;2;44;28;28m \x1b[m",
"  \x1b[48;2;122;137;156m \x1b[48;2;146;167;198m \x1b[48;2;32;34;46m \x1b[48;2;104;97;79m \x1b[48;2;160;152;129m \x1b[48;2;86;82;71m \x1b[48;2;162;151;129m \x1b[48;2;99;95;83m \x1b[48;2;64;22;10m \x1b[m",
"  \x1b[48;2;201;108;91m \x1b[48;2;219;106;76m \x1b[48;2;188;94;68m \x1b[48;2;46;25;20m \x1b[48;2;55;51;42m \x1b[48;2;171;165;139m \x1b[48;2;56;52;41m \x1b[48;2;64;15;10m \x1b[m",
"   \x1b[48;2;52;46;34m \x1b[48;2;115;100;67m \x1b[48;2;228;206;157m \x1b[48;2;51;45;31m \x1b[48;2;226;205;152m \x1b[48;2;45;45;35m \x1b[m",
"   \x1b[48;2;50;46;35m \x1b[48;2;111;99;75m \x1b[48;2;115;97;73m \x1b[48;2;99;71;47m \x1b[48;2;155;102;60m \x1b[48;2;51;45;33m \x1b[48;2;143;106;64m \x1b[m" 
    };
}imgJugador;;

void GanoSegunoNivel() {

	Console::SetCursorPosition(50, 5);
	cout << "HAS GANADO!";
	Console::SetCursorPosition(50, 6);
	cout << "FELICIDADES POR PASAR EL NIVEL 2!";
	ANSIForeColor(220); // COLOR AMARILLO
	int x = 10, y = 11;
	Console::SetCursorPosition(x, y);      cout << " ____     _    _   _    _    ____ _____  _____     _        _";
	Console::SetCursorPosition(x, y + 1);  cout << "/ ___|   / \\  | \\ | |  / \\ / ___ | _  _ | ____|   | |      / \\";
	Console::SetCursorPosition(x, y + 2);  cout << "| |  _  / _ \\ | \\|  | / _ \\ \\___ \\ | |  |  _|     | |     / _ \\";
	Console::SetCursorPosition(x, y + 3);  cout << "| |_| |/ ___ \\| |\\  |/ ___ \\ ___) || |  | |___    | |___ / ___ \\";
	Console::SetCursorPosition(x, y + 4);  cout << "\\____ / _ / \\_\\_| \\_/_ / \\_ \\____/ |_|  |_____|   |_____/_ / \\ _\\";
	Console::SetCursorPosition(x, y + 5);  cout << " ____ ___ ____   ___  _   _    _       ____  _____    _        _";
	Console::SetCursorPosition(x, y + 6);  cout << "/ ___/ _ \\| _ \\ / _ \\| \\ | |  / \\     |  _ \\| ____|  | |      / \\";
	Console::SetCursorPosition(x, y + 7);  cout << "| |  || | ||_) | | | | | | | / _ \\    | | | |  _|    | |     / _ \\";
	Console::SetCursorPosition(x, y + 8);  cout << "| |  || | ||_) | | | | | | | / _ \\    | | | |  _|    | |     / _ \\";
	Console::SetCursorPosition(x, y + 9);  cout << "\\____\\___/|_|\\_\\\\___/|_| \\_/ _ / \\_\\  |____/|_____|  |_____/ _ / \_\\";
	Console::SetCursorPosition(x, y + 10);  cout << " ____   _    ____ ___ ____  _   _ ____ ___     _";
	Console::SetCursorPosition(x, y + 11);  cout << "/ ___| / \\  | __ )_ _|  _ \\| | | |  _ \\|__|   / \\";
	Console::SetCursorPosition(x, y + 12);  cout << "\\___ \\/ _ \\ |  _ \\| || | | | | | | |_) || |  / _ \\";
	Console::SetCursorPosition(x, y + 13);  cout << "___) / ___ \\| |_) | || |_| | |_| |  _ < | | / ___ \\";
	Console::SetCursorPosition(x, y + 14);  cout << "|___/_ / \\ _\\____/___|____/ \\___/|_ |\\_\\___/_ / \ _\\";
	Console::SetCursorPosition(x, y + 15);  cout << "======================================================================:)";

	ANSIForeColor(15); //REGRESAMOS AL BLANCO
	Console::SetCursorPosition(50, 39);
	cout << "PRESIONE UNA TECLA PARA IR AL NIVEL 3";
	char tecla;
	do {
		tecla = _getch();
	} while (tecla != ' ');
}