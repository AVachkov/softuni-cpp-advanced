#include <iostream>
#include <vector>

const int INCREMENT = +1;
const int DECREMENT = -1;

void printMatrix(const std::vector<std::vector<char> >& matrix)
{
	for (const std::vector<char>& row : matrix) {
		for (const char& ch : row) {
			std::cout << ch;
		}
		std::cout << std::endl;
	}
}

int main()
{
	int rows, cols;
	std::cin >> rows >> cols;
	std::vector<std::vector<char> > matrix(rows, std::vector<char>(cols));

	std::string snake;
	std::cin >> snake;

	int col = 0, snakeIdx = 0;
	int op = INCREMENT;
	for (int row = 0; row < rows; row++) {
		for (int iterations = 0; iterations < cols; iterations++) {
			matrix[row][col] = snake[snakeIdx % snake.size()];
			snakeIdx++;
			col += op;
		}

		if (op == INCREMENT) {
			// switch direction (left)
			col = cols - 1;
			op = DECREMENT;
		}
		else {
			// direction - right
			col = 0;
			op = INCREMENT;
		}
	}

	printMatrix(matrix);

	return 0;
}