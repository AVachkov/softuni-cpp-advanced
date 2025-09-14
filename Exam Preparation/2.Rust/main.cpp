#include <iostream>

//
// Best and most understandable way to solve this problem
//

#define DIMENSION 10
#define NORMAL_CELL '.'
#define STAINLESS_CELL '#'
#define RUST_CELL '!'
#define TEMP_CELL '?' // you can choose any char for this one

void rustCell(char matrix[][DIMENSION], const int & curRow, const int & curCol)
{
	if (curRow < 0 || curRow >= DIMENSION || curCol < 0 || curCol >= DIMENSION)
		return;

	if (matrix[curRow][curCol] == NORMAL_CELL)
		matrix[curRow][curCol] = TEMP_CELL;
}

int main()
{
	char matrix[DIMENSION][DIMENSION];

	for (int curRow = 0; curRow < DIMENSION; curRow++) {
		for (int curCol = 0; curCol < DIMENSION; curCol++) {
			std::cin >> matrix[curRow][curCol];
		}
	}

	int ticks;
	std::cin >> ticks;

	while (ticks--) {

		for (int curRow = 0; curRow < DIMENSION; curRow++) {
			for (int curCol = 0; curCol < DIMENSION; curCol++) {
				if (matrix[curRow][curCol] == RUST_CELL) {
					rustCell(matrix, curRow - 1, curCol); // above
					rustCell(matrix, curRow + 1, curCol); // below
					rustCell(matrix, curRow, curCol - 1); // left
					rustCell(matrix, curRow, curCol + 1); // right
				}
			}
		}

		for (int curRow = 0; curRow < DIMENSION; curRow++) {
			for (int curCol = 0; curCol < DIMENSION; curCol++) {
				if (matrix[curRow][curCol] == TEMP_CELL) {
					matrix[curRow][curCol] = RUST_CELL;
				}
			}
		}
	}

	for (int curRow = 0; curRow < DIMENSION; curRow++) {
		for (int curCol = 0; curCol < DIMENSION; curCol++) {
			std::cout << matrix[curRow][curCol];
		}
		std::cout << std::endl;
	}

	return 0;
}