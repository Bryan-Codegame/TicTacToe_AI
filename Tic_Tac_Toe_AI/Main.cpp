//Tic-Tac-Toe
//Playing Tic Tac Toe with an AI
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <locale.h>

//Global Constants
const char X = 'X';
const char O = 'O';
const char T = 'T';
const char EMPTY = ' ';
const char NO_ONE = 'N';

//Prototype Functions
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);

using namespace std;

//Function main
int main() {
	setlocale(LC_ALL, "spanish");

	instructions();
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



