#pragma once

#include<string>
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
#include"commonh.h"


enum DIRECTION { UP, DOWN, LEFT, RIGHT };

class Position
{
protected:
	string key;//The string of that point
	int x, y;  //The coordinate of that point
	int color; 
public:
	friend class Map;
	Position() {
		color = YELLOW_COLOR;
	}
	Position(int a, int b, const string str,int icolor = YELLOW_COLOR) {
		setXY(a, b);
		color = icolor;
		setKey(str);
	}
	//Set the string
	void setKey(const string str);
	//Set the coordinate
	void setXY(int a, int b);
	//Print the string on particular coordinate
	void print();
	//Clear the string on particular coordinate
	void clear();
};

