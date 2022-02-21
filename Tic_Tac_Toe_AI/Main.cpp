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
const char TIE = 'T';
const char EMPTY = ' ';
const char NO_ONE = 'N';

//Prototype Functions
char winner(const vector<char>& board);
void instructions();
void displayBoard(const vector<char>& board);
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
bool isLegal(int move, const vector<char>& board);

//Function main
int main() {
	setlocale(LC_ALL, "spanish");

	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);

	instructions();
	displayBoard(board);
}

//Return the piece winner a tie or noBody
char winner(const vector<char>& board)
{
	//This are the posibilities to win.
	const int WINNING_POS[8][3] = { {0, 1, 2},
									{3, 4, 5},
									{6, 7, 8},
									{0, 3, 6},
									{1, 4, 7},
									{2, 5, 8},
									{2, 4, 6},
									{0, 4, 8} };

	const int TOTAL_ROWS = 8;

	//Return the winner
	for (int row = 0; row < TOTAL_ROWS; row++)
	{
		if ((board[WINNING_POS[row][0]] != EMPTY) &&
			(board[WINNING_POS[row][0]] == board[WINNING_POS[row][1]]) &&
			(board[WINNING_POS[row][1]] == board[WINNING_POS[row][2]])) 
		{
			return board[WINNING_POS[row][0]];
		}

	}

	//Return a Tie
	if (count(board.begin(), board.end(), EMPTY) == 0) {
		return TIE;
	}

	//Return that no one is the winner yet
	return NO_ONE;
}

void instructions() {
	cout << "\n�Bienvenido al juego de Gato!\n";
	cout << "Donde te enfrentar�s a un digno oponente\n";
	cout << "Debes elegir un n�mero 0 - 8 para definir una posici�n en el tablero: \n";
	cout << " 0 | 1 | 2 \n";
	cout << " 3 | 4 | 5 \n";
	cout << " 6 | 7 | 8 \n";

	cout << "Prep�rate la batalla est� a punto de comenzar.\n\n";
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
	char go_first = askYesNo("�Quieres empezar?");

	if (go_first == 'y')
	{
		cout << "Buena elecci�n, la necesitar�s";
		return X;
	}
	else {
		cout << "Admiro tu valent�a, yo empezar� entonces";
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


