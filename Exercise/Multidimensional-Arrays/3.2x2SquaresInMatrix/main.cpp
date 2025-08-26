#include <iostream>
#include <vector>

bool checkSquare(const std::vector<std::vector<char> >& matrix, const int& currentRow, const int& currentCol)
{
	return matrix[currentRow][currentCol] == matrix[currentRow][currentCol + 1] &&
		   matrix[currentRow][currentCol] == matrix[currentRow + 1][currentCol] &&
		   matrix[currentRow][currentCol] == matrix[currentRow + 1][currentCol + 1];
}

int main()
{
	int rows, cols;
	std::cin >> rows >> cols;

	std::vector<std::vector<char> > matrix(rows, std::vector<char>(cols));

	for (int r = 0; r < matrix.size(); r++)
		for (int c = 0; c < matrix[r].size(); c++)
			std::cin >> matrix[r][c];

	int squares = 0;
	for (int row = 0; row < rows - 1; row++) {
		for (int col = 0; col < cols - 1; col++) {
			if (checkSquare(matrix, row, col))
				squares++;
		}
	}

	std::cout << squares << std::endl;

	return 0;
}