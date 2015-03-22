#include "TicTacToe.h"
#include<Windows.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

char field; // postion where were we want to play

TicTacToe::TicTacToe() // constructor
{
	// initialising postions
	for (int rows = 0; rows < 3; rows++)
	{
		for (int cols = 0; cols < 3; cols++)
		{
			Board[rows][cols] = '#';

		}

	}
	currentPlayer = 'X';
}

TicTacToe::~TicTacToe() // deconstructor
{
	// do nothing
}

void TicTacToe::setPlayer(char player = 'X')
{
	currentPlayer = player;
}

char TicTacToe::getPlayer(void)
{
	return currentPlayer;
}

// restarting the game
void TicTacToe::restart()
{
	system("cls");
	// initialising postions
	for (int rows = 0; rows < 3; rows++)
	{
		for (int cols = 0; cols < 3; cols++)
		{
			Board[rows][cols] = '#';

		}

	}

}

void TicTacToe::print()
{
	int rows, cols;
	int boardpostion = 1;

	//displaying
	cout <<endl<<" "<< "--------------------" << "\n";
	for (rows = 0; rows < 3; rows++)
	{ 
		cout << " || ";
		for (cols = 0; cols < 3; cols++)
		{
			cout<<" "<< Board[rows][cols] << " || ";
		}
	
		cout <<endl<<" "<< "--------------------" << "\n";
	}

}
// changing player
void TicTacToe::changePlayer()
{
	if (currentPlayer == 'X')
	{
		currentPlayer = 'O';
	}
	else
	{
		currentPlayer = 'X';
	}
}

bool TicTacToe::move( int field)
{

	bool isvalid;
	// changing player
	
	switch (field)
	{
	case 1:
		isvalid = validateMove(0, 0);// check if it's an empty space
		if (isvalid == true) {
			Board[0][0] = currentPlayer;// allow player to make a move
			return true;
		}
		else {
			return  false;//if the space is taken, then it's an error move
		}
		break;
	case 2:
		isvalid = validateMove(0, 1);// check if it's an empty space
		if (isvalid == true)
		{
			Board[0][1] = currentPlayer;// allow player to make a move
			return true;
		}
		else {
			return  false;//if the space is taken, then it's an error move
		}
		break;
	case 3:
		isvalid = validateMove(0, 2);// check if it's an empty space
		if (isvalid == true)
		{
			Board[0][2] = currentPlayer;// allow player to make a move
			return true;
		}
		else {
			return  false;//if the space is taken, then it's an error move
		}
		break;
	case 4:
		isvalid = validateMove(1, 0);// check if it's an empty space
		if (isvalid)
		{
			Board[1][0] = currentPlayer;// allow player to make a move
			return true;
		}
		else {
			return  false;//if the space is taken, then it's an error move
		}
		break;
	case 5:
		isvalid = validateMove(1, 1);// check if it's an empty space
		if (isvalid == true)
		{
			Board[1][1] = currentPlayer;// allow player to make a move
			return true;
		}
		else {
			return  false;//if the space is taken, then it's an error move
		}
		break;
	case 6:
		isvalid = validateMove(1, 2);// check if it's an empty space
		if (isvalid == true)
		{
			Board[1][2] = currentPlayer;// allow player to make a move
			return true;
		}
		else {
			return  false;//if the space is taken, then it's an error move
		}
		break;
	case 7:
		isvalid = validateMove(2, 0);// check if it's an empty space
		if (isvalid == true)
		{
			Board[2][0] = currentPlayer;// allow player to make a move
			return true;
		}
		else {
			return  false;//if the space is taken, then it's an error move
		}
		break;
	case 8:
		isvalid = validateMove(2, 1);// check if it's an empty space
		if (isvalid == true)
		{
			Board[2][1] = currentPlayer;// allow player to make a move
			return true;
		}
		else {
			return  false;//if the space is taken, then it's an error move
		}
		break;
	case 9:
		isvalid = validateMove(2, 2);// check if it's an empty space
		if (isvalid == true)
		{
			Board[2][2] = currentPlayer;// allow player to make a move
			return true;
		}
		else {
			return  false;//if the space is taken, then it's an error move
		}
		break;
	default: // enter a 1>=value <=9 or a character
		return false;
	}
}

//Checking if the play has not played in the same box as the previouse player

bool TicTacToe::validateMove(int row, int col)
{
	if (Board[row][col] != 'X' && Board[row][col] != 'O')
		return true; //the move is legal
	else
		return false; // not ilegal
}



// isWon funtion starts here
bool TicTacToe::isWon(int playtimes)
{
	int i, j;
	// check for draw
	if (playtimes == 9)
		return false;
	//horizontal check for winner
	for (i = 0; i < 3; i++)
	{
		int count = 0; 
		for (j = 0; j < 3; j++)
		{
			if (Board[i][j] == currentPlayer)
				count++;
			if (count == 3)
				return true;
		}
	}

	//vertical check
	for (i = 0; i < 3; i++)
	{
		int count = 0; 
		for (j = 0; j < 3; j++)
		{
			if (Board[j][i] == currentPlayer)
				count++;
			if (count == 3)
				return true;
		}
	}

	// checking for diagonal winner
	if ((Board[0][0] == currentPlayer) && (Board[1][1] == currentPlayer))
	{
		if (Board[2][2] == currentPlayer)
		{
			return true;
		}
	}
	else if ((Board[0][2] == currentPlayer) && (Board[1][1] == currentPlayer))
	{
		if (Board[2][0] == currentPlayer)
		{
			return true;
		}
	}
	
	return false;
} // end isWOn



