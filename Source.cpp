#include<iostream>
#include<vector>
#include"TicTacToe.h"
#include "player.h"
#include <string>
#include <fstream>
using namespace std;
void PVP()
{
	TicTacToe caro;
	player p;
	string s1, s2;
	cout << "Nhap ten nguoi choi 1: ";
	cin>>s1;
	cout << "Nhap ten nguoi choi 2: ";
	cin >> s2;
	p.addData(s1);
	p.addData(s2);
	while (!caro.isDraw())
	{
		caro.drawBoard();
		int row, col;
		cout << "Player 1 move: ";
		cin >> row >> col;
		caro.Tick(row, col, 1);
		caro.drawBoard();
		if (caro.isWin(row, col))
		{
			cout << "Player 1 win";
			p.updateData(s1, 1, 0);
			p.updateData(s2, 0, 1);
			break;
		}
		cout << "Player 2 move: ";
		cin >> row >> col;
		caro.Tick(row, col, 2);
		caro.drawBoard();
		if (caro.isWin(row, col))
		{
			cout << "Player 2 win";
			p.updateData(s2, 1, 0);
			p.updateData(s1, 0, 1);
			break;
		}
		if (caro.isDraw())
		{
			cout << "Draw";
			break;
		}
	}
}
int findPosition(int a, vector<int> b)//tim vi tri de them phan tu
{
	unsigned int j = 0;
	while (a > b[j] && j < b.size() - 1)
		j++;
	return j;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
vector<vector<int>> FindThreeBestMove(TicTacToe a, int player)//tim 3 nuoc di toi uu nhat
{
	vector<int> movePoint;
	vector<vector<int>> a1;
	int max = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (a.boxPoint(i, j, player) != 0)
			{
				int point = a.boxPoint(i, j, player);
				vector <int> b;
				b.push_back(i);
				b.push_back(j);
				if (a1.size() == 0)
				{
					a1.push_back(b);
					movePoint.push_back(point);
				}
				else
				{
					unsigned int k = findPosition(point, movePoint);
					if (k >= movePoint.size() - 1)
					{
						a1.push_back(b);
						movePoint.push_back(point);
					}
					else
					{
						a1.insert(a1.begin() + k, b);
						movePoint.insert(movePoint.begin() + k, point);
					}
				}
			}
	vector<vector<int>> result;
	for (unsigned int i = a1.size(); i > a1.size() - 5; i--)
		result.push_back(a1[i - 1]);
	return result;
}
int minimax(TicTacToe a, vector<int> move, int minmaxPlayer, int depth, int bot, int player)
{
	if (a.boxPoint(move[0], move[1], minmaxPlayer) == 99999 || depth == 0)//khi thang hoac do sau =0
		//return (a.boxPoint(move[0], move[1], minmaxPlayer));
	{
		if (minmaxPlayer == bot) return 99999; //(a.boxPoint(move[0], move[1], minmaxPlayer));
		else return -99999;//-(a.boxPoint(move[0], move[1], minmaxPlayer));
	}
	//return (a.boxPoint(move[0], move[1], minmaxPlayer));
	else
	{
		if (minmaxPlayer == bot)//luot may di, can tim gia tri max
		{
			int mx = -99999;
			vector<vector<int>> predictMove = FindThreeBestMove(a, bot);//cac nuoc di kha thi
			for (unsigned int i = 0; i < predictMove.size(); i++)//xet tung truong hop
			{
				a.Tick(predictMove[i][0], predictMove[i][1], bot);
				mx = max(mx, minimax(a, predictMove[i], player, depth - 1, bot, player));
			}
			return mx;
		}
		else//luot nguo di, can tim gia tri min
		{
			int mn = 99999;
			vector<vector<int>> predictMove = FindThreeBestMove(a, player);// du doan nc di cua nguoi choi
			for (unsigned int i = 0; i < predictMove.size(); i++)//xet tung truong hop
			{
				a.Tick(predictMove[i][0], predictMove[i][1], player);
				mn = min(mn, minimax(a, predictMove[i], bot, depth - 1, bot, player));
			}
			return mn;
		}
	}
}
void PVC()
{
	int row1, col1, row2, col2;
	int Player = 1, bot = 2;
	TicTacToe caro;
	while (true)
	{
		system("cls");
		caro.drawBoard();
		cout << "Player 1 move: " << endl;
		cin >> row1;
		cin >> col1;
		caro.Tick(row1, col1, Player);
		caro.drawBoard();
		if (caro.isWin(row1, col1))
		{
			cout << "Player win";
			break;
		}
		vector<vector<int>> PredictMove = FindThreeBestMove(caro, bot);
		int predict = 0;
		for (unsigned int i = 0; i < PredictMove.size(); i++)
		{
			int max = 0;
			if (max < minimax(caro, PredictMove[i], 5, bot, bot, Player))
			{
				max = minimax(caro, PredictMove[i], 5, bot, bot, Player);
				predict = i;
			}
		}
		row2 = PredictMove[predict][0];
		col2 = PredictMove[predict][1];
		caro.Tick(row2, col2, bot);
		caro.drawBoard();
		if (caro.isWin(row2, col2))
		{
			cout << "Computer win";
			break;
		}
	}
}
void guild()
{
	int c=0;
	cout << "Ban lan luot nhap toa do=(so dong,so cot)" << endl;
	cout << "Ban khong duoc nhap len toa do da nhap,neu ban nhap sai se nhap lai" << endl;
	cout << "Neu ben nao co >=4 quan co cua minh giong nhau lien tiep thi se thang" << endl;
	cout << "Neu tat ca cac o bi danh het ma chua co nguoi thang thi 2 ben se hoa" << endl;
	cout << "     2-Bat Dau Choi" << endl;
	cout << "     3-Thoat" << endl;
	
	while (c != 2 && c != 3)
	{
		cout << "Ban muon chon: ";
		cin >> c;
	}
	if (c == 2) PVC();
	if (c == 3) 
		system("cls");
}
void mainMenu()
{
	cout << "-------------MAIN MENU---------------" << endl;;
	cout << "1. Play with other player" << endl;
	cout << "2. Play with bot" << endl;
	cout << "3. Replay" << endl;
	cout << "4. Player's Information " << endl;
	cout << "5. Guild" << endl;
	cout << "6. Exit" << endl;
}
void printInfor()
{
	player p;
	system("cls");
	p.readData();
	string s;
	cout << "Nhap ki tu bat ki de thoat: ";
	cin >> s;
	system("cls");
}
int main()
{
	
	int choice = 0;
	while (choice != 6)
	{
		mainMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1: 
			PVP();
		case 2:
			PVC();
		case 3:
		case 4:
			printInfor();
		case 5:
			guild();
		case 6:
			break;
		}
		
	}
	return 0;
}