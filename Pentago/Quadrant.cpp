#include "Quadrant.h"
#include "utils.h"


Quadrant::Quadrant()
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			tab[i][j] = boardState::empty;
		}
	}
}


void Quadrant::draw(int row, int col, int marginX, int marginY)
{
	int c = col * SIZE + 1;
	int r = row * SIZE + 1;
	for (int i = 0; i < SIZE + 3; i++) {
		gotoxy(col * (SIZE + 2) + marginX, row * (SIZE + 1) + i + marginY);
		if (i > 1 && i < SIZE + 2 && col == 0) {
			std::cout << r;
			r += 1;
		}
		else if (col == 0 && row == 0) {
			std::cout << " ";
		}
		for (int j = 0; j <= SIZE + 1; j++) {
			if (i == 0 && row > 0) {
				continue;
			}
			else if (i == 0 && row == 0) {
				if (j != 0 && j != SIZE + 1) {
					std::cout << c;
					c += 1;
				}
				else {
					std::cout << " ";
				}
			}
			else if (i == 1 || i == SIZE + 2) {
				std::cout << "-";
			}
			else if (j == 0 || j == SIZE + 1) {
				std::cout << "|";
			}
			else {
				std::cout << boardSign[tab[i - 2][j - 1]];
			}
		}
		std::cout << std::endl;
	}
}

bool Quadrant::put(int row, int column, int player)
{
	if (tab[row][column] == boardState::empty) {
		tab[row][column] = player;
		return true;
	}
	return false;
}

void Quadrant::rotateRight()
{
	int temp[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			temp[i][j] = tab[i][j];
		}
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			tab[i][j] = temp[SIZE - j - 1][i];
		}
	}
}

void Quadrant::rotateLeft()
{
	int temp[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			temp[i][j] = tab[i][j];
		}
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			tab[i][j] = temp[j][SIZE - i - 1];
		}
	}
}

bool Quadrant::isOnPosition(int player, int x, int y)
{
	if (tab[y][x] == boardSign[player]) {
		return true;
	}
	return false;
}


