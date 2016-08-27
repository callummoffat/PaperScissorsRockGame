#include "stdafx.h"
#include "Game.h"


Game::Game()
{
	computerScore = 0;
	playerScore = 0;
}

Game::~Game()
{
	computerScore = 0;
	playerScore = 0;
}

int Game::getComputerMove()
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 3);
	
	int move = dist6(rng);
	return move;
}

int Game::getPlayerMove()
{
	while (true)
	{
		string move = "";
		cout << "\nPress 1 for paper, 2 for scissors or 3 for rock."
			<< "\n________________________________________________\n";
		system("pause");
		cout << "\nWhat is your decision? ";
		cin >> move;

		if (move == "1") {
			return 1;
		}
		else if (move == "2")
		{
			return 2;
		}
		else if (move == "3")
		{
			return 3;
		}
		else
		{
			cerr << "ERROR : INVALID SELECTION. PLEASE TRY AGAIN.";
		}
	}
	return 0;
    

		

}

string Game::getPlayerName()
{
	string name;
	cout << "\nWhat is your name? ";
	cin >> name;
	return name;
}

void Game::play()
{
	cout << "\nWelcome!";
	string name = getPlayerName();

	while (playerScore < 2 && computerScore < 2)
	{
		int playersMove = getPlayerMove();
		int computersMove = getComputerMove();

		if (playersMove == computersMove)
		{
			cout << "\nThe match was a draw!";
		}
		else
		{
			if ((playersMove == 1 && computersMove == 3) || (playersMove == 2 && computersMove == 1) || (playersMove == 3 && computersMove == 2))
			{
				cout << "\nCongratulations, " << name << "! You won this round!";
				playerScore++;
			}
			else 
			{
				cout << "\nSorry, " << name << ". You lost this round...";
				computerScore++;
			}
		}
		
	}

	if (playerScore > computerScore)
	{
		cout << "\nCongratulations! You won this best out of 3 match!";
	}
	else
	{
		cout << "\n Too bad. You lost this best out of 3 match...";
	}



}


Game::~Game()
{
}
