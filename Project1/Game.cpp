#include "Game.h"

Game::Game()
{
	set_generacija();
}
void Game::sljedeca_generacija()
{
	for (int i = 1; i < REDAKA - 1; i++)
	{
		for (int j = 1; j < STUPACA - 1; j++)
		{
			_sljedeca_generacija[i][j] = _generacija[i][j];
		}
	}
	for (int i = 1; i < REDAKA - 1; i++)
	{
		for (int j = 1; j < STUPACA - 1; j++)
		{
			int zivi_susjedi = 0;

			if (_generacija[i - 1][j])
				zivi_susjedi++;
			if (_generacija[i - 1][j - 1])
				zivi_susjedi++;
			if (_generacija[i - 1][j + 1])
				zivi_susjedi++;
			if (_generacija[i][j - 1])
				zivi_susjedi++;
			if (_generacija[i + 1][j - 1])
				zivi_susjedi++;
			if (_generacija[i + 1][j])
				zivi_susjedi++;
			if (_generacija[i + 1][j + 1])
				zivi_susjedi++;
			if (_generacija[i ][j + 1])
				zivi_susjedi++;

			if (_generacija[i][j] == true && (zivi_susjedi < 2 || zivi_susjedi > 3))
			{
				_sljedeca_generacija[i][j] = false;
			}
			else if (_generacija[i][j] == false && zivi_susjedi == 3)
			{
				_sljedeca_generacija[i][j] = true;
			}
			else if (_generacija[i][j] == true && (zivi_susjedi == 2 || zivi_susjedi == 3))
			{
				_sljedeca_generacija[i][j] = true;
			}
		}
	}
	for (int i = 1; i < REDAKA - 1; i++)
	{
		for (int j = 1; j < STUPACA - 1; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}	
}
void Game::iscrtaj()
{
	for (int i = 1; i < REDAKA - 1; i++)
	{
		for (int j = 1; j < STUPACA - 1; j++)
		{
			if (_generacija[i][j] == true)
			{
				cout << " O ";
			}
			else
			{
				cout << "   ";
			}		
		}
		cout << endl;
	}
}
void Game::set_generacija()
{
	bool _generacija[REDAKA][STUPACA];
	srand(time(nullptr));

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0;  j < STUPACA; j++)
		{
			slucajna_vrijednost();
			if (slucajna_vrijednost() && i != 0 && j !=0 && i!= REDAKA -1 && j!=STUPACA - 1 )
			{
				_generacija[i][j] = true;
				this->_generacija[i][j] = _generacija[i][j];
			}
			else
			{
				_generacija[i][j] = false;
				this->_generacija[i][j] = _generacija[i][j];
			}
		}
	}
}
bool Game::slucajna_vrijednost()
{
	return rand() % 100 < 25;
}
