#pragma once
#include <iostream>
#include<vector>
using namespace std;
class box
{
public:
	int value;
public:
	box()
	{
		value = -1;
	}
	box(int i)
	{
		value = i;
	}
	~box() {}
};
class TicTacToe
{
public:
	box Box[10][10];
public:
	TicTacToe() {}
	int countXO(int cur_row, int cur_col, int row, int col);
	
	void printLines(int columns);// ke ngang
	
	void printNumbers(int columns);//Ve so hang so cot
	
	void drawBoard();//Ve ban co
	
	bool isWin(int cur_x, int cur_y);//kiem tra dieu kien thang
	
	int boxPoint(int x, int y, int Player);//danh gia diem cua nuoc di
	
	void Tick(int x, int y, int Player);// danh co
	
	bool isDraw();
};

