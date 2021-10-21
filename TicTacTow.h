#pragma once
#include<iostream>
#include<Windows.h>
#include<random>
#include<string>
#include<ctime>

using namespace std;
#define cls system("cls")

char Boxes[10] = { '0','1', '2', '3', '4', '5', '6', '7', '8', '9' };

void Box() {
	cout << "\t\t" << Boxes[1] << "\t|\t" << Boxes[2] << "\t|\t" << Boxes[3] << endl;
	cout << "\t-----------------------------------------------\n";
	cout << "\t\t" << Boxes[4] << "\t|\t" << Boxes[5] << "\t|\t" << Boxes[6] << endl;
	cout << "\t-----------------------------------------------\n";
	cout << "\t\t" << Boxes[7] << "\t|\t" << Boxes[8] << "\t|\t" << Boxes[9] << endl;
}
bool TicTaTow(short index, bool player) {
	do {
		if (player == 1) {//player 1
			if (Boxes[index] != 'X' && Boxes[index] != 'O') {
				Boxes[index] = 'X';
				return 1;
			}
		}
		else {//player 2
			if (Boxes[index] != 'X' && Boxes[index] != 'O') {
				Boxes[index] = 'O';
				return 1;
			}
		}
		return 0;
	} while (true);
}
void Player(short turn, string& name) {
	short index;
	char symbol='O';
	do {
	lb:
		cls;
		if (turn%2)
			symbol = 'X';
		else
			symbol = 'O';
		cout << name << "'s Turn! ("<<symbol<<")\n";
		Box();
		cout << "Enter Index:";
		cin >> index;
		if (index > 9) {
			cout << "Invalid Index Selected!\nChoose 1-9!";
			Sleep(500);
			goto lb;
		}
		cls;
	} while (!TicTaTow(index, turn % 2));
}
void Computer(short turn, string& name) {
	short index;
	cls;
	cout << name << "'s Turn!\n";
	Box();
	do {
		srand(time(0));
		index = rand() % 9;
	} while (!TicTaTow(index + 1, turn % 2));
}
bool Win() {
	if (Boxes[1] == Boxes[2] && Boxes[2] == Boxes[3])
		return 1;
	if (Boxes[1] == Boxes[5] && Boxes[5] == Boxes[9])
		return 1;
	if (Boxes[1] == Boxes[4] && Boxes[4] == Boxes[7])
		return 1;
	if (Boxes[2] == Boxes[5] && Boxes[5] == Boxes[8])
		return 1;
	if (Boxes[4] == Boxes[5] && Boxes[5] == Boxes[6])
		return 1;
	if (Boxes[3] == Boxes[5] && Boxes[5] == Boxes[7])
		return 1;
	if (Boxes[3] == Boxes[6] && Boxes[6] == Boxes[9])
		return 1;
	if (Boxes[1] == Boxes[2] && Boxes[2] == Boxes[3])
		return 1;
	if (Boxes[7] == Boxes[8] && Boxes[8] == Boxes[9])
		return 1;
	else
		return 0;
}

