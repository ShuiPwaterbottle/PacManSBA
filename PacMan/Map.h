#pragma once
#include"Position.h"
#include<vector>
#include<queue>
using namespace std;

const int MAP_SIZE = 29;
const int PACMAN_X = MAP_SIZE / 2;
const int PACMAN_Y = MAP_SIZE / 2;
extern const int TIME_SPEED;
const int MAX_FREEZE_TIME = 5 * 1000 / TIME_SPEED;

//Type of the point on the map, such as these:
enum MAP_POS_TYPE { SPACE,WALL,PEAN,SUPER_PEAN};
class MapPos: public Position
{
	int type; 
public:
	//Set the type of that point
	void setType(int t);
	int getType() { return type; }
};

struct PosXY
{
	int x, y;
};

class Pacman;
class Ghost;
class Map
{
	//Every point of the map, seen as different types of elements.
	MapPos points[MAP_SIZE][MAP_SIZE];
	//Player's score
	int scores;
	//Winning score
	int target_scores;
	//The freezing time of the ghosts after eating the super pean
	int freezeTime;
	void findPath(Position &A, Position&B);

public:
	friend class Game;
	friend class Ghost;
	Map() {};
	//initialize map using file
	void init(const char* filepath, Pacman &pacman, vector<Ghost> &ghosts);
	//print the point on (x,y)
	void renew(int x, int y) { points[x][y].print(); }
	//return the type of point on (x,y)
	int goXY(int x, int y) { return points[x][y].getType(); }
	//delete the pean eaten by the player on (x,y)
	void delPean(int x, int y);
	//check (x,y) is exceed from the map or not
	bool oK(int x, int y);
	//delete the pean eaten by the player on (x,y)
	void delSuperPean(int x, int y);
	//find path
	int findDir(Position &A, Position&B);
};

