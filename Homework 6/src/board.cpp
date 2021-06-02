#include "board.h"

Board::Board() {
int i = 0, j = 0;

	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++) {
			gameBoard[i][j].setSymbol(WATER);
			gameBoard[i][j].getPosition()->setRow(i);
			gameBoard[i][j].getPosition()->setColumn(j);
		}
}

char Board::getSymbol(int row, int col) {
    return gameBoard[row][col].getSymbol();
}




void Board::printGameBoard (bool showPegs) {
	int i = 0, j = 0;

	printf ("  0 1 2 3 4 5 6 7 8 9\n");

	for (i = 0; i < ROWS; i++) {
		printf ("%d ", i);

		for (j = 0; j < COLS; j++) {
			if (showPegs == true)
				printf ("%c ", gameBoard [i][j].getSymbol());
			else {
				switch (gameBoard [i][j].getSymbol()) {
					case HIT:   printf ("%c ", HIT);   break;
					case MISS:  printf ("%c ", MISS);  break;
					case WATER:
					default:    printf ("%c ", WATER); break;
				}
			}
		}

		putchar ('\n');
	}
}


void Board::putShipOnGameBoard (Watercraft ship,
	                     Coordinate position, int direction) {

	int i = ship.getLength() - 1;

	for (i = 0; i < ship.getLength(); i++) {
		if (direction == HORIZONTAL)
			gameBoard [position.getRow()][position.getColumn() + i].setSymbol(ship.getSymbol());
		else /* VERTICAL */
			gameBoard [position.getRow() + i][position.getColumn()].setSymbol(ship.getSymbol());
	}
}

bool Board::convertStringtoPosition (Coordinate position[], char *stringPosition, int length) {

	bool flag = true;
	char temp = '\0';
	int i = 0, j = 0, k = 1;

	/* checks if length of input is good */
	if (strlen (stringPosition)/2 == length) {
		/* loops through the length of the ship */
		for (i = 0; i < length && flag; i++) {
			/* checks if each cell is a digit */
			if (isdigit (stringPosition[j]) && isdigit (stringPosition[k])) {
				position[i].setRow(stringPosition[j] - '0');
				position[i].setColumn(stringPosition[k] - '0');

				j += 2;
				k += 2;
			} else {
				flag = false;
			}
		}
	} else {
		flag = false;
	}

	return flag;
}



bool Board::isValidLocation (Coordinate position,
				         int direction, int length) {

	int i = length - 1;
	bool isValid = true;

	for (i = 0; isValid && i < length; i++) {
		if (direction == HORIZONTAL) {
			if (gameBoard [position.getRow()][position.getColumn() + i].getSymbol() != WATER &&
				(position.getColumn() + i) < COLS)
				isValid = false;
		} else { /* VERTICAL */
			if (gameBoard [position.getRow() + i][position.getColumn()].getSymbol() != WATER &&
				(position.getRow() + i) < ROWS)
				isValid = false;
		}
	}

	return isValid;
}

Coordinate Board::generatePosition (int direction, int length) {

	Coordinate position;
	if (direction == HORIZONTAL) {
		position.setRow(getRandomNumber (0, ROWS));
		position.setColumn(getRandomNumber (0, COLS - length));
	} else { /* VERTICAL */
		position.setRow(getRandomNumber (0, ROWS - length));
		position.setColumn(getRandomNumber (0, COLS));
	}

	return position;
}


void Board::manuallyPlaceShipsOnGameBoard (Watercraft* ship[]) {
	char       stringPosition[11] = "";
	int        i = 0, j = 0;

	Coordinate position[5];
	bool    isValid = false;

	std::cin.ignore(32767, '\n');

	for (i = 0; i < NUM_OF_SHIPS; i++) {

		while (true) {
			system ("cls");
			printGameBoard (true);
			std::cout<<"> Please enter the "<<(*ship[i]).getLength()<<" cells to place the "<<(*ship[i]).getName()<<" across (no spaces):\n";
			std::cout<<"> ";
			std::cin>>stringPosition;

			/* convertStringtoPosition returns false if unsuccessful */
			if (convertStringtoPosition (position, stringPosition, (*ship[i]).getLength())) {

				isValid = true;

				for (j = 0; j < (*ship[i]).getLength(); j++) {

					if (gameBoard[position[j].getRow()][position[j].getColumn()].getSymbol() == WATER) {
						gameBoard[position[j].getRow()][position[j].getColumn()].setSymbol((*ship[i]).getSymbol());
					} else {
						isValid = false;
						std::cout<<"> Invalid input!\n";

						if (j != 0)
							while (j >= 0) {
								gameBoard[position[j].getRow()][position[j].getColumn()].setSymbol(WATER);
								j--;
							}

						break;
					}
				}
			} else {
				isValid = false;
				std::cout<<"> Invalid input!\n";
			}

			if (isValid == true) break;
		}

	}
}

void Board::randomlyPlaceShipsOnGameBoard (Watercraft* ship[]) {
	Coordinate position;
	int direction = -1;
	int i = 0;

	for (i = 0; i < NUM_OF_SHIPS; i++) {
		while (true) {
			direction = getRandomNumber (0, 1); /* 0 -> horizontal, 1 -> vertical */
			position = generatePosition (direction, (*ship[i]).getLength());

			if (isValidLocation (position, direction, (*ship[i]).getLength())) break;
		}

		putShipOnGameBoard (*ship[i], position, direction);
	}

}

void Board::updateGameBoard (Coordinate target) {

	switch (gameBoard[target.getRow()][target.getColumn()].getSymbol()) {
		/* miss */
		case WATER:
			gameBoard[target.getRow()][target.getColumn()].setSymbol(MISS);
			break;

		/* hit */
		case CARRIER:
		case BATTLESHIP:
		case CRUISER:
		case SUBMARINE:
		case DESTROYER:
			gameBoard[target.getRow()][target.getColumn()].setSymbol(HIT);
			break;

		case HIT:
		case MISS:
		default:
			break;
	}

}



short Board::checkShot (Coordinate target) {

	int hit = -2;

	switch (gameBoard[target.getRow()][target.getColumn()].getSymbol()) {
		/* miss */
		case WATER:
			hit = 0;
			break;

		/* hit */
		case CARRIER:
		case BATTLESHIP:
		case CRUISER:
		case SUBMARINE:
		case DESTROYER:
			hit = 1;
			break;

		case HIT:
		case MISS:
		default:
			hit = -1;
			break;
	}

	return hit;

}
