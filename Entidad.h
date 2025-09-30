#pragma once

#include "Utils.h"
#include <string>
#include <vector>
#using <System.Drawing.dll>

using namespace System::Drawing;

class Entity {//Noelia noob nivel ingles c1M+
protected:
	int x, y;
	bool visible;
	int sizeX, sizeY;
	string* sprite;		//sprite puede ser ASCII o ANSI
	ConsoleColor color;
	
public:
	Entity(int X, int Y, int sX, int sY, string sp[], ConsoleColor c, bool v) {	//constructor completo
		x = X; y = Y; sizeX = sX; sizeY = sY;
		visible = v;
		color = c;

		sprite = new string[sY];
		for (int i = 0; i < sY; i++) {
			sprite[i] = sp[i];
		}
	}

	Entity(int X, int Y) {	//constructor para uso de herencia
		x = X; y = Y;
		visible = true;
		sizeX = 0; sizeY = 0;
		color = ConsoleColor::White;
		sprite = nullptr;
	}

	Entity(int X, int Y, ConsoleColor c) {	//constructor para uso de herencia
		x = X; y = Y;
		visible = true;
		sizeX = 0; sizeY = 0;
		color = c;
		sprite = nullptr;
	}

	Entity() {	//constructor vacio
		x = 0; y = 0;
		sizeX = 0; sizeY = 0;
		color = ConsoleColor::White;
		visible = true;
		sprite = nullptr;
	}

	~Entity() {
		if (sprite != nullptr) {
			delete[] sprite;
		}
	}

	//Setters
	void setX(int X) { x = X; }
	void setY(int Y) { y = Y; }
	void setVisible(bool v) { visible = v; }
	void setPos(int X, int Y) { x = X; y = Y; }
	void setColor(ConsoleColor c) { color = c; }

	//getters
	int getX() { return x; }
	int getY() { return y; }
	bool isVisible() { return visible; }
	int getSizeX() { return sizeX; }
	int getSizeY() { return sizeY; }
	
	//Configuracion de objeto
	void setSprite(int sX, int sY, string sp[], ConsoleColor c) {
		color = c;

		if (sprite != nullptr) {
			delete[] sprite;
		}

		sizeX = sX; sizeY = sY;
		sprite = new string[sY];
		for (int i = 0; i < sY; i++) {
			sprite[i] = sp[i];
		}
	}

	void editSprite(string l, int line) {
		if (line <= sizeY) {
			sprite[line] = l;
		}
	}

	//Polimorfismo habilitaado
	//Dibujado
	virtual void draw() {
		Console::ForegroundColor = color;
		for (int i = 0; i < sizeY; i++) {
			Console::SetCursorPosition(x, y + i);
			cout << sprite[i];
		}
	}

	virtual void clear() {
		for (int i = 0; i < sizeY; i++) {
			Console::SetCursorPosition(x, y + i);
			cout << string (sizeX, ' ');
		}
	}
	
	virtual void move(int Dx, int Dy) {
		x += Dx;
		y += Dy;
	}

	//Colisiones
	Drawing::Rectangle getRectagle() {
		return Drawing::Rectangle(x, y, sizeX, sizeY);
	}
};