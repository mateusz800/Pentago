#include <windows.h>
#include <iostream>

#include "utils.h"


Move readCommand() {
	char command[4];
	gotoxy(5, 16);
	printf("Command: ");
	std::cin >> command;
	Move move;
	toupper(command[0]);
	if (command[0] == 'R') {
		move.movementType = movementType::rotation;
		move.value[0] = command[1];
		toupper(command[2]);
		move.direction = command[2];
	}
	else if(command[0]>='0' && command[0]<='9'){
		move.movementType = movementType::put;
		move.value[0] = command[0];
		move.value[1] = command[1];
	}
	else {
		move.movementType = movementType::unknown;
	}
	return move;
}

void gotoxy(int x, int y)
{
	COORD coordinates;   
	coordinates.X = x;    
	coordinates.Y = y;     
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

