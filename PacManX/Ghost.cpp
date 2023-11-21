#include "Ghost.h"

Ghost::Ghost(int x, int y)
{
	init_x = x;
	init_y = y;
	setXY(x, y);
	go = UP;
	color = RED_COLOR;
	setKey("��");
}
extern int right_way_rate;
int Ghost::move(Map & map,Pacman &pacman)
{
	int res = -1;//����ֵ���ߵķ���

	//�ȱ���x,y ��ֹ��һ��λ�ò��Ϸ�
	int tempX = x, tempY = y;
	bool flag = true;//���ڱ�־���Ƿ�������һ��
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
		if (!map.oK(x, y) || map.goXY(x, y) == WALL) {
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

int Ghost::move(int dir, Map & map, Pacman & pacman)
{
	if (dir == -1) return dir;
	//�ȱ���x,y ��ֹ��һ��λ�ò��Ϸ�
	int tempX = x, tempY = y;
	bool flag = true;//���ڱ�־���Ƿ�������һ��
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
	if (!map.oK(x, y) || map.goXY(x, y) == WALL) {
		x = tempX; y = tempY;
	}
	else {
		flag = false;
		map.renew(tempX, tempY);
	}
	print();
	return dir;
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