#include "Game.h"
const int TIME_SPEED = 50;
const int INFO_MARGIN_LEFT = 8;
const int INFO_MARGIN_UP = 6;

Game::Game()
{
	SetWindowSize(WINDOWS_SIZE_X, WINDOWS_SIZE_Y);
	srand((unsigned int)(time(NULL)));
	HideCursor();
}
void Game::init()
{
	map.init("map.txt", pac_man, ghosts);
	time_counter = 0;
	steps.clear();
	play_flag = false;
}

char GameName[] = { "\
                                                                                                     \n\
     111111111                                                                                       \n\
     11      11                                                                                      \n\
     11       11                                                                                     \n\
     11      11                                                                                      \n\
     111111111       11111          111111        111      111         11111         11  11111       \n\
     11            11     11      11      11     11  11   11 11      11     11     11 11      11     \n\
     11           11       11    11              1   11  11   11    11       11      11        11    \n\
     11          111       11    11             11    11 1    11   111       11      11        11    \n\
     11           11      111     11      11    1     1111     11   11      111      11        11    \n\
     11             11111   111     111111     11      11       1     11111   111    11        11    \n\
                                                                                                     \n\
                                                                                                     \n\
"
};



int Game::start()
{
	SetColor(WHITE_COLOR);
	system("cls");
	Goto_XY(0, 2);
	SetColor(GAMENAME_COLOR);
	cout << GameName;

	int left_margin = (MAP_SIZE + SIDE_INFO_UI_SIEZ)-7;
	int vertical_margin = (MAP_SIZE + INFO_UI_SIZE)/2+5;
	SetColor(WHITE_COLOR);
	Goto_XY(left_margin, vertical_margin - 1);
	cout << "¡ú"; SetColor(WHITE_COLOR); cout << "Game Start!"; SetColor(WHITE_COLOR);

	int selected = 0;
	int MAX_IDX = 1;

	while (true) {
		char ch;
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case -32:
				ch = _getch();
				switch (ch)
				{
				case 72:					
					if (selected != 0){
						selected = 0;
						Goto_XY(left_margin, vertical_margin - 1);
						cout << "¡ú"; SetColor(WHITE_COLOR); cout << "Game Start!"; SetColor(WHITE_COLOR);
					}
					break;
				
				default:
					break;
				}
				break;
			case '\r':
				system("cls");
				return selected;
			case 27://Esc
				system("cls");
				exit(0);
			default:;
			}
		}
		Sleep(10);
	}
	system("cls");
	return selected;
}

int speed_min = 1;
int speed_max = 5;
int right_way_rate = 1;
void showSettings(int selected, int &speed) {
	int left_margin = (MAP_SIZE + SIDE_INFO_UI_SIEZ) - 7;
	int vertical_margin = (MAP_SIZE + INFO_UI_SIZE) / 2;
	SetColor(WHITE_COLOR);
	switch (selected)
	{
	case 0:
		speed = speed_min;
		Goto_XY(left_margin, vertical_margin);
		cout << "¡ú"; SetColor(WHITE_COLOR); cout << "Easy  "; SetColor(WHITE_COLOR);
		Goto_XY(left_margin, vertical_margin + 2);
		cout << "  Normal    ";
		Goto_XY(left_margin, vertical_margin + 4);
		cout << "  Hard      ";
		Goto_XY(left_margin, vertical_margin + 6);
		cout << "  Custom";
		break;
	case 1:
		speed = (speed_min + speed_max) / 2;
		Goto_XY(left_margin, vertical_margin);
		cout << "  Easy    ";
		Goto_XY(left_margin, vertical_margin + 2);
		cout << "¡ú"; SetColor(WHITE_COLOR); cout << "Normal  "; SetColor(WHITE_COLOR);
		Goto_XY(left_margin, vertical_margin + 4);
		cout << "  Hard    ";
		Goto_XY(left_margin, vertical_margin + 6);
		cout << "  Custom";
		break;
	case 2:
		speed = speed_max;
		Goto_XY(left_margin, vertical_margin);
		cout << "  Easy      ";
		Goto_XY(left_margin, vertical_margin + 2);
		cout << "  Normal    ";
		Goto_XY(left_margin, vertical_margin + 4);
		cout << "¡ú"; SetColor(WHITE_COLOR); cout << "Hard    "; SetColor(WHITE_COLOR);
		Goto_XY(left_margin, vertical_margin + 6);
		cout << "  Custom";
		break;
	case 3:
		Goto_XY(left_margin, vertical_margin);
		cout << "  Easy      ";
		Goto_XY(left_margin, vertical_margin + 2);
		cout << "  Normal    ";
		Goto_XY(left_margin, vertical_margin + 4);
		cout << "  Hard      ";
		Goto_XY(left_margin, vertical_margin + 6);
		cout << "¡ú"; SetColor(WHITE_COLOR); cout << " Custom"; SetColor(WHITE_COLOR);
		break;
	default:
		break;
	}

	Goto_XY(left_margin, vertical_margin + 8);
	cout << "Difficulty(Block/s)£º";
	Goto_XY(left_margin, vertical_margin + 9);
	for (int i = speed_min; i <= speed_max; i++) {
		cout << i;
		cout << "  ";
	}
	Goto_XY(left_margin, vertical_margin + 9);
	for (int i = speed_min; i <= speed_max; i++) {
		if (i == speed) {
			SetColor(SELECTED_COLOR);cout << i; SetColor(WHITE_COLOR);
		}
		else {
			cout << i;
		}
		cout << "  ";
	}
}
bool Game::settings()
{
	SetColor(WHITE_COLOR);
	system("cls");
	Goto_XY(0, 2);
	SetColor(GAMENAME_COLOR);
	cout << GameName;
	

	int selected = 0;
	int MAX_IDX = 3;
	int speed = speed_min;
	showSettings(selected, speed);
	while (true) {
		char ch;
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case -32:
				ch = _getch();
				switch (ch)
				{
				case 72:
					if (selected != 0) {
						selected--;
						showSettings(selected, speed);
					}
					break;
				case 80:
					if (selected != MAX_IDX) {
						selected++;
						showSettings(selected, speed);
					}
					break;
				case 75:
					if (selected == MAX_IDX && speed != speed_min) {
						speed--;
						showSettings(selected, speed);
					}
					break;
				case 77:
					if (selected == MAX_IDX && speed != speed_max) {
						speed++;
						showSettings(selected, speed);
					}
					break;
				default:
					break;
				}
				break;
			case '\r':
				system("cls");
				GHOST_SPEED = 1000 / (50 * speed);
				speed_value = speed;
				right_way_rate = speed + 1;
				return true;
				break;
			case 27://Esc
				return false;
				break;
			default:;
			}
		}
	}
}


int RECORD_MAX_IDX = 0;

//ÓÃÓÚ³Ô¶¹ÈËÉÁË¸
int Pacman_Colors[] = { WHITE_COLOR, RED_COLOR, GREEN_COLOR, YELLOW_COLOR, BLUE_GREEN_COLOR };
int PacmanColors_i = 0;
bool Game::loop()
{
	refresh();
	// record the direction and movement, use for further dev.
	int dir_pacman = -1;
	int ghost_num = ghosts.size();
	int *dir_ghosts = new int[ghost_num];
	
	int speed_adapter = 0;
	while (true) {
		dir_pacman = -1;
		for (int i = 0; i < ghost_num; i++)
			dir_ghosts[i] = -1;
		//ghosts
		if (map.freezeTime == 0) {
			++speed_adapter;
			if (speed_adapter == GHOST_SPEED) {
				speed_adapter = 0;
				//all ghosts move to player
				for (int i = 0; i < ghost_num; i++) {
					dir_ghosts[i]=ghosts[i].move(map, pac_man);
				}
			}
			pac_man.color = YELLOW_COLOR;
		}
		else { //Super pean period
			map.freezeTime--;
			PacmanColors_i = (PacmanColors_i + 1) % (sizeof(Pacman_Colors) / 4);
			pac_man.color = Pacman_Colors[PacmanColors_i];
			pac_man.print();
		}
		
		//Detect entered key
		char ch;
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case -32:
				ch = _getch();
				switch (ch)
				{
				case 72:
					pac_man.move(UP, map);
					dir_pacman = UP;
					break;
				case 80:
					pac_man.move(DOWN, map);
					dir_pacman = DOWN;
					break;
				case 75:
					pac_man.move(LEFT, map);
					dir_pacman = LEFT;
					break;
				case 77:
					pac_man.move(RIGHT, map);
					dir_pacman = RIGHT;
					break;
				default:
					break;
				}
				break;
			case 27://ESC
				return true;
			case ' ':
				pause();
				break;
			default:;
			}
		}

		//to calculate the time played
		steps.push_back(dir_pacman);
		for (int i = 0; i < ghost_num; i++)
			steps.push_back(dir_ghosts[i]);

		if (map.scores == map.target_scores) {
			return game_win();
		}

		for (auto&ghost_i : ghosts) {
			if (ghost_i.hit(pac_man,map))
				return game_over();
		}
		//layout for the information like time,score
		infoUI();

		++time_counter;
		Sleep(50);
	}
}
void Game::pause()
{
	int bias_temp=23;
	Goto_XY(MAP_SIZE * 2 + 18, INFO_MARGIN_UP + bias_temp);
	if (!play_flag) {
		SetColor(PAUSE_COLOR); cout << "GAME PAUSE"; SetColor(WHITE_COLOR);
	}
	while (true) {
		char ch;
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case 27://ESC
			case ' ':
				
				Goto_XY(MAP_SIZE * 2 + 18, INFO_MARGIN_UP + bias_temp);
				cout << "          ";
				return;
				break;
			default:;
			}
		}
		Sleep(10);
	}
	
}

bool Game::game_over()
{
	record.add(map.scores, steps, ghosts.size(), speed_value);
	record.show();
	Goto_XY(WINDOWS_SIZE_X / 2 - 8, WINDOWS_SIZE_Y - 3);
	cout << " Game Over " << endl;
	SetColor(WHITE_COLOR);
	cout << "Press any key back to the menu.." << endl;
	system("pause");
	return true;
}

bool Game::game_win()
{
	record.add(map.scores, steps, ghosts.size(), speed_value);
	record.show();
	Goto_XY(WINDOWS_SIZE_X / 2 - 14, WINDOWS_SIZE_Y - 3);
	cout << "Congratulations~You Win!!!" << endl;
	SetColor(WHITE_COLOR);
	cout << "Press any key back to the menu..." << endl;
	system("pause");
	return true;
}

extern int Ghost_Colors[];
void Game::infoUI()
{
	
	Goto_XY(MAP_SIZE * 2 + 2, WINDOWS_SIZE_Y - 1);
	printf("Time played£º%.1fs", time_counter*50.0 / 1000);

	
	Goto_XY(0, MAP_SIZE);
	string str_spliter(MAP_SIZE * 2, '-');
	cout << str_spliter;
	
	Goto_XY(0, MAP_SIZE + INFO_UI_SIZE / 2);
	string str_Space(MAP_SIZE * 2, ' ');
	cout << str_Space;
	Goto_XY(0, MAP_SIZE + INFO_UI_SIZE / 2);
	cout << "Score£º" << map.scores;

	Goto_XY(0, MAP_SIZE + INFO_UI_SIZE - 2);
	cout << str_Space;
	Goto_XY(0, MAP_SIZE + INFO_UI_SIZE - 1);
	cout << str_Space;
	if (map.freezeTime > 0) {
		Goto_XY(0, MAP_SIZE + INFO_UI_SIZE - 2);
		printf("Super pean countdown£º%.1fs", map.freezeTime*50.0 / 1000);
	
		Goto_XY(0, MAP_SIZE + INFO_UI_SIZE - 1);
		string str_time_counter((map.freezeTime)*MAP_SIZE * 2 / MAX_FREEZE_TIME, '#');
		cout << str_time_counter;
	}
}

void Game::helpUI()
{
	
	for (int i = 0; i < MAP_SIZE + INFO_UI_SIZE; i++) {
		Goto_XY(MAP_SIZE * 2, i);
		cout << "|";
	}
	int width = 28;

	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT + width / 2 - 4, INFO_MARGIN_UP - 2);
	cout << "Instructions";
	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT - 1, INFO_MARGIN_UP - 3);
	string line1(width, '-');
	cout << "+" << line1 << "+";
	for (int i = 0; i < 8; i++) {
		Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT - 1, INFO_MARGIN_UP - 2 + i);
		cout << "|";
	}
	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT - 1, INFO_MARGIN_UP - 2 + 8);
	cout << "+" << line1 << "+";
	for (int i = 0; i < 8; i++) {
		Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT - 1 + width + 1, INFO_MARGIN_UP - 2 + i);
		cout << "|";
	}
	if (!play_flag) {
		Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT + 2, INFO_MARGIN_UP);
		cout << "Control the movements£º";
		Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT + 2, INFO_MARGIN_UP + 1);
		cout << "\"¡ü\"¡¢\"¡ý\"¡¢\"¡û\"¡¢\"¡ú\"Key";
	}
	

	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT + 2, INFO_MARGIN_UP + 3);
	cout << "Pause - Space";
	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT + 2, INFO_MARGIN_UP + 4);
	cout << "Back to menu - Esc";
	width = 36;
	int bias_vertical = 10;
	int TEMP_MARGIN_LEFT = INFO_MARGIN_LEFT - 4;
	Goto_XY(MAP_SIZE * 2 + TEMP_MARGIN_LEFT - 1, INFO_MARGIN_UP + bias_vertical - 1);
	string line2(width, '-');
	cout << "+" << line2 << "+";
	for (int i = 0; i < 8; i++) {
		Goto_XY(MAP_SIZE * 2 + TEMP_MARGIN_LEFT - 1, INFO_MARGIN_UP + bias_vertical + i);
		cout << "|";
	}
	Goto_XY(MAP_SIZE * 2 + TEMP_MARGIN_LEFT - 1, INFO_MARGIN_UP + bias_vertical + 8);
	cout << "+" << line2 << "+";
	for (int i = 0; i < 8; i++) {
		Goto_XY(MAP_SIZE * 2 + TEMP_MARGIN_LEFT - 1 + width + 1, INFO_MARGIN_UP + bias_vertical + i);
		cout << "|";
	}

	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT, INFO_MARGIN_UP + 2 + bias_vertical);
	cout << "Player:";
	Position Player((MAP_SIZE * 2 + INFO_MARGIN_LEFT + 9) / 2, INFO_MARGIN_UP + 2 + bias_vertical, "¡ü", YELLOW_COLOR);
	Player.print();
	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT, INFO_MARGIN_UP + 4 + bias_vertical);
	cout << "Ghosts:";
	for (int i = 0; i < ghosts.size(); i++) {
		Position ghost((MAP_SIZE * 2 + INFO_MARGIN_LEFT + 9 + i * 2) / 2, INFO_MARGIN_UP + 4 + bias_vertical, "¡ñ", Ghost_Colors[i]);
		ghost.print();
	}
	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT, INFO_MARGIN_UP + 6 + bias_vertical);
	cout << "Super pean:";
	Position SuperPean((MAP_SIZE * 2 + INFO_MARGIN_LEFT + 13) / 2, INFO_MARGIN_UP + 6 + bias_vertical, "¨’", YELLOW_COLOR);
	SuperPean.print();
	
	Goto_XY(MAP_SIZE * 2 + INFO_MARGIN_LEFT + 2, INFO_MARGIN_UP + 10 + bias_vertical);
	cout << "Difficulty: "<< speed_value <<" Block/s";

}

void Game::refresh()
{
	system("cls");
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {		
			map.points[i][j].print();
		}
	}
	pac_man.print();
	for (auto &ghost_i : ghosts) {
		ghost_i.print();
	}
	infoUI();	//Timer,score,super pean countdown
	helpUI();	//Instructions
}
