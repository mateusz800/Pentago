#pragma once
#include "Quadrant.h"
#include "utils.h"

class Board
{
public:
	Board(int posX, int posY);
	void draw();
	bool makeMove(Move move);
	bool playerWon(int player);
private:
	Quadrant quadrants[4];
	Position position;
	bool isPlayerOnPosition(int player, int x, int y);
};

