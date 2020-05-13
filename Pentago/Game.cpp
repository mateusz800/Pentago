
#include "Game.h"


Game::Game()
{
	board = new Board(5, 5);
}

Game::~Game() {
	delete board;
}


void Game::run()
{
	char command[2];
	bool player2 = false;
	char sign;
	bool moveSuccesfull = false;
	drawInstruction();
	while (true) {
		moveSuccesfull = false;
		gotoxy(5, 2);
		printf("Player %d move", int(player2 + 1));
		board->draw();
		while (!moveSuccesfull) {
			clearLastCommand();
			Move move = readCommand();
			if (move.movementType == movementType::unknown) {
				gotoxy(8, 18);
				printf("Incorrect move or command");
				continue;
			}
			clearErrorMessage();
			move.player = int(player2 + 1);
			moveSuccesfull = board->makeMove(move);

			if (!moveSuccesfull) {
				gotoxy(8, 18);
				printf("Incorrect move or command");
			}
		}
		if (board->playerWon(int(player2 + 1))) {
			printf("Won player %d", int(player2 + 1));
			break;
		}
		player2 = !player2;
	}
	std::cin >> sign;
}

void Game::drawInstruction()
{
	gotoxy(25, 6);
	printf("Commands:");
	gotoxy(28, 8);
	printf("<y><x>  - put ball in given location eg. 11");
	gotoxy(28, 9);
	printf("R<quadrant number (1-4)>R  - Rotate selected part of board 90 degrees right");
	gotoxy(28, 10);
	printf("R<quadrant number (1-4)>R  - Rotate selected part of board 90 degrees left");
}

void Game::clearErrorMessage() {
	gotoxy(8, 18);
	for (int i = 0; i < 30; i++) {
		std::cout << " ";
	}
}

void Game::clearLastCommand() {
	gotoxy(5, 16);
	for (int i = 0; i < 30; i++) {
		std::cout << " ";
	}
}