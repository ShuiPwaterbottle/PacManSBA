#pragma once
#include"Position.h"
#include"Map.h"
#include"player.h"

class Ghost:public Position
{
	//表示移动方向
	DIRECTION go;
	//初始位置坐标
	int init_x, init_y;
public:
	Ghost() {};
	
	Ghost(int x, int y); //initalise
	int move(Map &map,Pacman &pacman); //move and check for suitable movement
	int move(int dir,Map &map, Pacman &pacman);//same
	//check for the ghosts has crushed into player or not. If player get super pean, ghosts will back to home.
	bool hit(Pacman &pacman, Map &map);
	void getXY(int& a, int& b);
};

