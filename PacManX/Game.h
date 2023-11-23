#pragma once
#include"Map.h"
#include"player.h"
#include"Ghost.h"
#include"Record.h"
#include<conio.h>

//ÐÅÏ¢UIµÄ³ß´ç
const int INFO_UI_SIZE = 5;
//²à±ßÀ¸
const int SIDE_INFO_UI_SIEZ = 22;

extern const int WINDOWS_SIZE_X;
extern const int WINDOWS_SIZE_Y;

class Game
{
	Pacman pacmanX;
	vector<Ghost> ghosts;
	Map mapX;
	Record record; //still testing

	//speed of the ghost
	int GHOST_SPEED,speed_value;
	//time count
	int time_counter;
	//record the direction of the player or ghosts in a certain period
	vector<int> steps;
	//testtesttesttesttesttesttesttesttesttesttesttesttesttest
	bool play_flag;

public:
	Game();
   //init
	void init();
	//start menu
	int start();
	//game difficulty
	bool settings();
	//test
	int show_record();
	bool loop();
	void play(int x);
	
private:
	//game pause
	void pause();
	bool game_over();
	bool game_win();
	//Score UI
	void infoUI();
	//Instruction UI
	void helpUI();
	//refresh the panel after pause
	void refresh();
};

