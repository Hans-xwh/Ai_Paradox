#pragma once
#include "Entidad.h"

using namespace std;
 


class MundoUno : public Entity {
private: 
    bool visible;
public:
    MundoUno(int X, int Y, ConsoleColor c) : Entity(X, Y, c) {
        sizeY = 16;
        sizeX = 80;
        visible = true;

        sprite = new string[sizeY];
        sprite[0] = "           ||||||||||||||||||||||  MUNDO IA ||||||||||||||||||||||";
        sprite[1] = "                                                                          ";
        sprite[2] = "              |||||||||      []        /\\      WWW       |||||||||        ";
        sprite[3] = "          ╔════════════════╗ [][]|  ╔════════╗    |   ╔═════════════════╗       [][]      ";
        sprite[4] = "          LOOOOOOOOOOOOOOOOL  []   OOOOOOOOOOOO   |   OOOOOOOOOOOOOOOOOOO     [][][][][][][][]";
        sprite[5] = "          L  []   []   []  L        L  [][]  L    |   L []   []    []   L  [][][][]   [][][][][][]";
        sprite[6] = "          LOOOOOOOOOOOOOOOOL  I|IIIOOOOOOOOOOOOIII|  IOOOOOOOOOOOOOOOOOOO       [][][][][]";
        sprite[7] = "     WWW   <<<<<<<>>>>>>>II   II|III<<<<<<<>>>>>>>I  I|IIIIII<<<<<<<>>>>>>>     W  W";
        sprite[8] = "      T    []L| |||| |L[]II   I|  ILLL| || |LLL  I|  II|LLL|||||||||LLLL|L";
        sprite[9] = "      |[]  []L| |[]| |L[]II   I|  ILLL| [] |LLL  I|  II|LLL||[][]|||LLL |L";
        sprite[10] = "      |[]  []L| |[]| |L[]II   I|  ILLL| [] |LLL  I|  II|LLL||[][]|||LLLL------ ";
        sprite[11] = "      |[]  []L| |[]| |L[]______|___LLL| [] |LLL___|____|LLL||[][]|||LLL |L[]L|";
        sprite[12] = "      ||[] []L| |[]| |L[][][][][][]LLL| [] |LLL---------LLL||[][]|||LLL |L[]L|";
        sprite[13] = "|      |[] [][][][][][][][][][]|   [][][][][][][][][][][][][][][][][][] |L[]L|   |";
        sprite[14] = "||     |[]   [][][][][][]           [][]  []  [][]           [][][][][] |____|  ||";
        sprite[15] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
     }
    ~MundoUno() { }

    void setVisible(bool v) {
        visible = v;
    }
    bool isVisible() {
        return visible;
    }
    void draw() override {
        if (!visible) return;
        Entity::draw();
    }
    void clear() override {

    }


};

string spr_puerta[7] = {
    " ____ ",
    "|EXIT|",
    "|    |",
	"|<O  |",
	"|    |",
	"| ## |",
	"|____|"
};