#include "Ghost.h"

Ghost::Ghost(int x, int y)
{
	init_x = x;
	init_y = y;
	setXY(x, y);
	go = UP;
	color = RED_COLOR;
	setKey("●");
}
int Ghost::move(Map & map,Pacman &pacman) //check for movement
{
	int res = -1;//返回值：走的方向
	int tempX = x, tempY = y;
	bool flag = true;
	while (flag) {
		int dir = map.findDir(*this, pacman); // bfs
		switch (dir)
		{
		case UP:
			go = UP;
			--y;
			break;
		case DOWN:
			go = DOWN;
			++y;
			break;
		case LEFT:
			go = LEFT;
			--x;
			break;
		case RIGHT:
			go = RIGHT;
			++x;
			break;
		default:
			break;
		}
		if (!map.oK(x, y) || map.goXY(x, y) == WALL ) {
			x = tempX; y = tempY;
		}
		else {
			flag = false;
			res = dir;
			map.renew(tempX, tempY);
		}
		print();
	}
	return res;
}

bool Ghost::hit(Pacman & pacman, Map &map)
{
	int a, b;
	pacman.getXY(a, b);
	if (a == x && b == y) {
		if (map.freezeTime > 0) {
			map.renew(x,y);
			x = init_x;
			y = init_y;
			print();
			pacman.print();
			return false;
		}
		else {
			return true;
		}
	}
	else
		return false;
}
void Ghost::getXY(int& a, int& b)
{
	a = x;
	b = y;
	return;
}