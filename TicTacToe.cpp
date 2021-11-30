#include "TicTacToe.h"
#include <iostream>
#include <vector>
using namespace std;
bool isOk(int col, int row)
{
	return (col <= 9) && (col >= 0) && (row >= 0) && (row <= 9);
}
/*-----------------------------------*/
int TicTacToe::countXO(int cur_row, int cur_col, int row, int col)
{
	int count = 1;
	if (Box[cur_row][cur_col].value != -1)
	{
		for (int i = 1; i <= 4; i++)
		{
			if (isOk(cur_row + i * row, cur_col + i * col))
			{
				if (Box[cur_row][cur_col].value == Box[cur_row + i * row][cur_col + i * col].value)
					count++;
				else break;
			}
			else break;
		}
		for (int i = 1; i <= 4; i++)
		{
			if (isOk(cur_row - i * row, cur_col - i * col))
			{
				if (Box[cur_row][cur_col].value == Box[cur_row - i * row][cur_col - i * col].value)
					count++;
				else break;
			}
			else break;
		}
	}
	return count;
}
void TicTacToe::printLines(int columns)//ke hang ngang
{
	cout << "   ";
	for (int i = 0; i < columns; i++)
	{
		cout << " ---";
	}
	cout << endl;
}
void TicTacToe::printNumbers(int columns)//in chi so cac o
{
	cout << "   ";
	for (int i = 0; i < columns; i++)
	{
		cout << "  " << i << " ";
	}
	cout << endl;
}
void TicTacToe::drawBoard()
{
	string arr[10][10];
	system("cls");
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 10; j++)
		{
			if (Box[i][j].value==-1)
			    arr[i][j] = " |  ";
			else
			{
				if (Box[i][j].value == 1)
					arr[i][j] = " | x";
				if (Box[i][j].value == 2)
					arr[i][j] = " | o";
			}

		}
	}
	printNumbers(10);
	printLines(10);
	for (int i = 0; i < 10; i++)
	{

		cout << " " << i;
		for (int j = 0; j < 10; j++)
		{
			cout << arr[i][j];
		}
		cout << " | " << endl;
		printLines(10);
	}
}
bool TicTacToe::isWin(int cur_x,int cur_y)
{
	bool check = false;
	int row1[4] = { 1,0 };//dang doc
	int col1[4] = { 0,1 };
	int row2[4] = { 1,1 };//cheo chinh-cheo phu
	int col2[4] = { 1,-1 };
	/*kiem tra duong thang*/
	if (countXO(cur_x, cur_y, row1[0], col1[0]) >= 4 || countXO(cur_x, cur_y, row1[1], col1[1]) >= 4)
		check = true;
	/*kiem tra duong cheo*/
	if (countXO(cur_x, cur_y, row2[0], col2[0]) >= 4 || countXO(cur_x, cur_y, row2[1], col2[1]) >= 4)
		check = true;
	return check;
}
int TicTacToe::boxPoint(int x, int y, int Player)//danh gia diem cua  tung nuoc di
{
	{
		int value = 0;
		if (Box[x][y].value != -1)
		{
			return 0;
		}
		else
		{
			this->Tick(x, y, Player);
			if (isWin(x, y)) return 99999;
			else
			{
				int x1[8] = { 0,0,1,-1,1,1,-1,-1 };//tren duoi trai phai
				int y1[8] = { 1,-1,0,0,1,-1,-1,1 };//cac duong cheo
				int v[8] = { 0,0,0,0,0,0,0,0 };//dem cac o cung mau
				for (int i = 0; i < 8; i++)
				{
					for (int j = 1; j <= 3; j++)
					{
						if (Box[x + j * x1[i]][y + j * y1[i]].value == Box[x + x1[i]][y + y1[i]].value && Box[x + x1[i]][y + y1[i]].value != -1 && isOk(x + j * x1[i], y + j * y1[i]))
							v[i]++;
						else if (Box[x + j * x1[i]][y + j * y1[i]].value != -1 && Box[x + j * x1[i]][y + j * y1[i]].value != Box[x + x1[i]][y + y1[i]].value)
						{
							break;
						}
					}
				}
				Box[x][y] = box(-1);
				int countPoint = 0;
				for (int i = 0; i < 8; i++)
				{
					if (countPoint < v[i])
						countPoint = v[i];
				}
				return countPoint;
			}
		}
	}
}
void TicTacToe::Tick(int x, int y, int Player)//danh co
{
	Box[x][y] = box(Player);
}
bool TicTacToe::isDraw()
{
	int count = 0;
	bool check = false;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (Box[i][j].value != -1) count++;
	if (count >= 100) check = true;
	return check;
}