#pragma once

#include "Utils.h"
#include <string>
#include <vector>

class Entity {
protected:
	int x, y;
	bool visible;
	int sizeX, sizeY;
	string* sprite;
	
public:
	Entity(int X, int Y, int sX, int sY, string sp[], bool v) {	//constructor completo
		x = X; y = Y; sizeX = sX; sizeY = sY;
		visible = v;
		sprite = new string[sY];
		for (int i = 0; i < sY; i++) {
			sprite[i] = sp[i];
		}
	}

	Entity(int X, int Y) {	//constructor para uso de herencia
		x = X; y = Y;
		visible = true;
		sizeX = 0; sizeY = 0;
		sprite = nullptr;
	}

	Entity() {	//constructor vacio
		x = 0; y = 0;
		sizeX = 0; sizeY = 0;
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
	void move(int dX, int dY) { x += dX; y += dY; }

	//getters
	int getX() { return x; }
	int getY() { return y; }
	bool isVisible() { return visible; }
	int getSizeX() { return sizeX; }
	int getSizeY() { return sizeY; }
	
	//Configuracion de objeto (Correr una sola vez)
	void setSprite(int sX, int sY, string sp[]) {	
		if (sprite != nullptr) {
			delete[] sprite;
		}

		sizeX = sX; sizeY = sY;
		sprite = new string[sY];
		for (int i = 0; i < sY; i++) {
			sprite[i] = sp[i];
		}
	}

	//Dibujado
	void draw() {
		for (int i = 0; i < sizeY; i++) {
			Console::SetCursorPosition(x, y + i);
			cout << sprite[i];
		}
	}

	void clear() {
		for (int i = 0; i < sizeY; i++) {
			Console::SetCursorPosition(x, y + i);
			for (int j = 0; j < sizeX; j++) {
				cout << " ";
			}
		}
	}
};