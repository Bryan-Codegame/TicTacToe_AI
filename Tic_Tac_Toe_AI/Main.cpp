//Tic-Tac-Toe
//Playing Tic Tac Toe with an AI
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <locale.h>

using namespace std;

//Global Constants
const char X = 'X';
const char O = 'O';
const char T = 'T';
const char EMPTY = ' ';
const char NO_ONE = 'N';

//Prototype Functions
void instructions();
void displayBoard(const vector<char>& board);
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);


//Function main
int main() {
	setlocale(LC_ALL, "spanish");

	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);

	instructions();
	displayBoard(board);
}

void instructions() {
	cout << "\n¡Bienvenido al juego de Gato!\n";
	cout << "Donde te enfrentarás a un digno oponente\n";
	cout << "Debes elegir un número 0 - 8 para definir una posición en el tablero: \n";
	cout << " 0 | 1 | 2 \n";
	cout << " 3 | 4 | 5 \n";
	cout << " 6 | 7 | 8 \n";

	cout << "Prepárate la batalla está a punto de comenzar.\n\n";
}

char askYesNo(string question) {
	char answer;
	do {
		cout << question << "(y/n)";
		cin >> answer;
	} while (answer != 'y' && answer != 'n');
	return answer;
}

int askNumber(string question, int high, int low) {
	int number;
	do {
		cout << question << "(" << high << " - " << low << ")";
		cin >> number;
	} while (number > high || number < low);

	return number;
}


//This function is used to define who starts playing.
char humanSymbol() {
	char go_first = askYesNo("¿Quieres empezar?");

	if (go_first == 'y')
	{
		cout << "Buena elección, la necesitarás";
		return X;
	}
	else {
		cout << "Admiro tu valentía, yo empezaré entonces";
		return O;
	}
}

char opponent(char symbol) {
	if (symbol == X) {
		return O;
	}
	else
	{
		return X;
	}
}

//Display board on console
void displayBoard(const vector<char>& board) {
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	cout << "\n";
}