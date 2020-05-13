#include "Board.h"

Board::Board(int posX, int posY)
{
	position.x = posX;
	position.y = posY;

	for (int i = 0; i < sizeof(quadrants) / sizeof(Quadrant); i++) {
		quadrants[i] = Quadrant();
	}
}

void Board::draw()
{
	for (int i = 0; i < 4; i++) {
		quadrants[i].draw(i / 2, i % 2, position.x, position.y);
	}
}

bool Board::makeMove(Move move)
{
	if (move.movementType == movementType::put) {
		int x = atoi(&move.value[1]);
		int y = atoi(&move.value[0]) / 10;
		int row = (y - 1) % SIZE;
		int column = (x - 1) % SIZE;
		int quadrantIndex = (y - 1) / SIZE + (x - 1) / SIZE;
		if ((y-1) / SIZE > 0) {
			quadrantIndex += 1;
		}
		return quadrants[quadrantIndex].put(row, column, move.player);
	}
	else {
		int quadrantIndex = atoi(&move.value[0]) - 1;
		if (move.direction == 'R') {
			quadrants[quadrantIndex].rotateRight();
			return true;
		}
		else if (move.direction == 'L') {
			quadrants[quadrantIndex].rotateLeft();
			return true;
		}
		else {
			return false;
		}
	}
}

bool Board::playerWon(int player)
{
	for (int i = 0; i < 2 * SIZE; i++) {
		for (int j = 0; j < 2 * SIZE; j++) {
			if (isPlayerOnPosition(player, j, i)) {
				// in column
				if (isPlayerOnPosition(player, j, i + 1) && isPlayerOnPosition(player, j, i + 2)
					&& isPlayerOnPosition(player, j, i + 3) && isPlayerOnPosition(player, j, i + 4)) {
					return true;
				}
				// in bevel
				if (isPlayerOnPosition(player, j + 1, i + 1) && isPlayerOnPosition(player, j + 2, i + 2)
					&& isPlayerOnPosition(player, j + 3, i + 3) && isPlayerOnPosition(player, j + 4, i + 4)) {
					return true;
				}
				// in row
				if (isPlayerOnPosition(player, j + 1, i) && isPlayerOnPosition(player, j + 2, i)
					&& isPlayerOnPosition(player, j + 3, i) && isPlayerOnPosition(player, j + 4, i)) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Board::isPlayerOnPosition(int player, int x, int y)
{
	int quadrantIndex = (y - 1) / SIZE + (x - 1) / SIZE;
	int row = (y - 1) % SIZE;
	int column = (x - 1) % SIZE;
	return quadrants[quadrantIndex].isOnPosition(player, row, column);
}
