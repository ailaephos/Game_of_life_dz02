#include<iostream>
#include"Game.h"
using namespace std;

int main()
{
	Game game;
	
	bool dalje;
	do {
		game.iscrtaj();
		game.sljedeca_generacija();
		
		cout << "Dalje (1/0): ";
		cin >> dalje;
		system("cls");
	} while (dalje);

	return 0;
}