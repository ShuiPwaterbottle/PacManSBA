#pragma once
#include"Map.h"

class Pacman:public Position
{
	DIRECTION go;
public:
	friend class Game;
	Pacman() {};
	//initialize player's position
	void init(int x, int y);
	//move and check for suitable movements
	void move(int dir, Map &map);
	//return the coordinate of the player
	void getXY(int &a, int &b);
};

