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
class RecordItem //һ����¼
{
	string name;//��¼����ʱ�����
	int score;//����
	int speed;//С���ƶ��ٶ�
	int ghost_num;//С������3~5����
	int steps_num;//�ܹ�������ʱ������
	vector<int> steps;//��¼��ÿ��ʱ������ʱ�Զ���/С�ֵ��ƶ�����
public:
	friend class Record;
	friend class Game;
	RecordItem() { steps_num = 0;};
	RecordItem(const string& iname, int iscore) { name = iname; score = iscore; steps_num = 0;};
	bool operator <(const RecordItem &B) { return score > B.score; }//���ڽ��� sort
};

class Record //��¼������
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

