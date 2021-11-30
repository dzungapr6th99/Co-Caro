#pragma once
#include <iostream>
#include<string>
using namespace std;
class player
{
public:
	string name;
	int num_win;
	int num_lose;

public:
	player() 
	{
		name = "";
		num_win = 0;
		num_lose = 0;
	};
	player(string name, int num_win, int num_lose);
	~player() {};
	void set(string name, int num_win, int num_lose);
	string getName();

	int getWin();

	int getLose();

	void show(player p);

	void addData(string s);

	player searchData(player p);

	void readData();

	void updateData(string s, int win, int lose);
};