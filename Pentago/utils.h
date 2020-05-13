
struct Position {
	int x;
	int y;
};

enum movementType { rotation = 0, put = 1, unknown = 2 };

struct Move {
	int movementType;
	char value[2];
	char direction;
	int player;
};

Move readCommand();
void clearLastCommand();

void gotoxy(int x, int y);