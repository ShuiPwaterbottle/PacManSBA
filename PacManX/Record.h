#pragma once
#include<vector>
#include<ctime>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
#include"commonh.h"

class Record;
class RecordItem //一条记录
{
	string name;//记录名（时间戳）
	int score;//分数
	int speed;//小怪移动速度
	int ghost_num;//小怪数（3~5个）
	int steps_num;//总共经历的时间周期
	vector<int> steps;//记录的每个时钟周期时吃豆人/小怪的移动方向
public:
	friend class Record;
	friend class Game;
	RecordItem() { steps_num = 0;};
	RecordItem(const string& iname, int iscore) { name = iname; score = iscore; steps_num = 0;};
	bool operator <(const RecordItem &B) { return score > B.score; }//用于降序 sort
};

class Record //记录管理器
{
	const char *filepath; //file name to store the records
	vector<RecordItem> items; //records
public:
	friend class Game;
	Record():filepath("game.record"){};
	//read the data from the file
	void read();
	//save the data to the file
	void save();
	//add a record
	void add(int the_score,const vector<int> &steps,int ghost_num,int speed);
	//show the record.
	void show();
};

