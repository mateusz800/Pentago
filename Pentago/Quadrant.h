#pragma once

#include <iostream>

#define SIZE 3

struct Result {
	int type;
	int position;
};

class Quadrant
{
public:
	Quadrant();
	void draw(int row, int col, int marginX, int marginY);
	bool put(int row, int column, int player);
	void rotateRight();
	void rotateLeft();
	bool isOnPosition(int player, int x, int y);
	
private:
	const enum boardState { empty = 0, player1 = 1, player2 = 2 };
	const char* boardSign = ".xo";
	int tab[SIZE][SIZE];
};

