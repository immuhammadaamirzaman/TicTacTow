#include"TicTacTow.h"

void main(){
	string player1, player2,playerName;
	char option;
	srand(time(0));
	bool t = rand() % 2;
	static uint16_t c = t+1;
	
	cout << "1)Computer\t2)2 Players\nChoose:";
	cin >> option;
	
	if (option == '1') {
		cout << "Enter Player 1 Name:";
		cin >> player1;
		do {
			playerName = c % 2 ? player1 : "CPU";
			if (c % 2) {
				Player(c, playerName);
				if (Win()) {
					cls;
					cout << player1 << " Won\n";
					Sleep(1000);
					break;
				}
			}
			else {
				Computer(c, playerName);
				if (Win()) {
					cls;
					cout<< "CPU Won\n";
					Sleep(1000);
					break;
				}
			}
			Sleep(300);
			cls;
			c++;
		} while (c <= 9);
	}
	else if (option == '2') {//2 Players
		cls;
		cout << "Enter Player 1 Name:";
		cin >> player1;
		cout << "Enter Player 2 Name:";
		cin >> player2;
		cls;
		cout << player1 << " : X\n" << player2 << " : O\n";
		Sleep(1000);
		do {
			playerName = c % 2 ? player1 : player2;
			if (c % 2) {
				Player(c, playerName);
				if (Win()) {
					cls;
					cout << player1 << " Won\n";
					Sleep(1000);
					break;
				}
			}
			else {
				Player(c, playerName);
				if (Win()) {
					cls;
					cout << player2 << " Won\n";
					Sleep(1000);
					break;
				}
			}
			Sleep(200);
			cls;
			c++;
		} while (c <= 9);
	}
	Box();
	system("pause");
}
