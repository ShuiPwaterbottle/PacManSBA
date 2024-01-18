#include "player.h"

void Pacman::init(int x, int y)
{
	color = YELLOW_COLOR;
	setXY(x, y);
	go = UP;
	setKey("¡ü");
}
void Pacman::move(int dir, Map &map)
{
	if (dir == -1) return;
	int tempX=x, tempY=y; // use for test next position is legal or not
	switch (dir)
	{
	case UP:
		--y;
		setKey("¡ü");
		break;
	case DOWN:
		++y;
		setKey("¡ý");
		break;
	case LEFT:
		--x;
		setKey("¡û");
		break;
	case RIGHT:
		++x;
		setKey("¡ú");
		break;
	default:
		break;
	}
	if (!map.oK(x, y) || map.goXY(x, y) == WALL) {
		x = tempX; y = tempY;
	}
	else if(map.goXY(x, y) == PEAN){
		map.delPean(x, y);
		map.renew(tempX, tempY);
	}
	else if (map.goXY(x, y) == SUPER_PEAN) {
		map.delSuperPean(x, y);
		map.renew(tempX, tempY);
	}
	else {
		map.renew(tempX, tempY);
	}
	print();
}

void Pacman::getXY(int & a, int & b)
{
	a = x;
	b = y;
	return ;
}
