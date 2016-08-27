#pragma once
#include <iostream>
#include <random>
#include <string>

using namespace std;

class Game
{
public:
	Game();
	~Game();
	const int _Paper = 1;
	const int _Scissors = 2;
	const int _Rock = 3;
	void play();
private:
	int getPlayerMove();
	int getComputerMove();
	string getPlayerName();
	int playerScore;
	int computerScore;


};

