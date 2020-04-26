#pragma once
#include<vector>
#include<ctime>
#include<iostream>
using namespace std;
class Game
{
public:
	Game ();
	void sljedeca_generacija();
	void iscrtaj();

private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	void set_generacija();
	bool slucajna_vrijednost();



	


};

