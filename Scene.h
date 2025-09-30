#pragma once

#include "Entidad.h"
#include "jugador.h"
#include "Robot.h"

class Scene1 {
	Jugador* jugador;
	Robot** enemigos;
	int cantEnemigos;
	Entity** npcs;
	int cantNpc;
	Entity* TriggerFinal;

};