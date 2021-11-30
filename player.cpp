#include<iostream>
#include<string>
#include<fstream>
#include"player.h"

using namespace std;

int count = 0;


//phuong thuc class player
player::player(string name, int num_win, int num_lose) {
    set(name, num_win, num_lose);
}

void player::set(string name, int num_win, int num_lose) {
    this->name = name;
    this->num_win = num_win;
    this->num_lose = num_lose;

}
string player::getName() {
    return name;
}

int player::getWin() {
    return num_win;
}

int player::getLose() {
    return num_lose;
}


//them data

void player::addData(string s) {

    player p;
    p.name = s;
    p.num_win = 0;
    p.num_lose = 0;

    ofstream write;
    write.open("info_player.txt", ios::app);
    write << "\n" << p.name;
    write << "\n" << p.num_win;
    write << "\n" << p.num_lose;
    write.close();
}

//show data

void player::show(player p) {
    cout << "\n\t---INFOMATION PLAYERS---";
    cout << "\n\tTEN : " << p.name;
    cout << "\n\tSo tran WIN : " << p.num_win;
    cout << "\n\tSo tran LOSE : " << p.num_lose;
}
//hien thi data
void player::readData() {
    player p;
    ifstream read;
    read.open("info_player.txt");
    while (!read.eof()) {
        read >> p.name;
        read >> p.num_win;
        read >> p.num_lose;
        show(p);
    }
    read.close();
}

//tim data
/*	string player::searchData(string s) {
    ifstream read;
    read.open("info_player.txt");
    while (!read.eof()) {
        read >> point.name;
        read >> point.num_win;
        read >> point.num_lose;
        if (point.name == s) {
            return s;
        }
    }
} */
//cap nhat data

void player::updateData(string s, int win, int lose) {

    player point; //player de doc - ghi data
    ofstream tempFile;
    tempFile.open("temp.txt");
    ifstream read;
    read.open("info_player.txt");
    while (!read.eof()) {

        read >> point.name;
        read >> point.num_win;
        read >> point.num_lose;
        if (point.name != s) {
            tempFile << "\n" << point.name;
            tempFile << "\n" << point.num_win;
            tempFile << "\n" << point.num_lose;
        }
        else {
            tempFile << "\n" << point.name;
            tempFile << "\n" << point.num_win + win;
            tempFile << "\n" << point.num_lose + lose;
        }
    }
    read.close();
    tempFile.close();
    remove("info_player.txt");
    rename("temp.txt", "info_player.txt");
}







