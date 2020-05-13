#pragma once
#include "Board.h"

class Game 
{
public:
	Game();
	~Game();

	virtual void run();

private:
	Board* board;
	void drawInstruction();
	void clearErrorMessage();
	void clearLastCommand();
};

