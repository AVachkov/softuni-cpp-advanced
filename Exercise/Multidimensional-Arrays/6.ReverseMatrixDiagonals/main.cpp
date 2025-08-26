#include <iostream>
#include <vector>
#include <sstream>

bool checkMatrixBounds(const std::vector<std::vector<int> >& matrix, const int& row, const int& col)
{
	return (row >= 0 && row < matrix.size()) && (col >= 0 && col < matrix[row].size());
}

void printReverseDiag(std::ostream& outputString, const std::vector<std::vector<int> >& matrix, int row, int col)
{
	while (checkMatrixBounds(matrix, row, col)) {
		outputString << matrix[row][col] << ' ';

		row--; col++;
	}
	outputString << std::endl;
}

int main()
{
	int rows, cols;
	std::cin >> rows >> cols;
	std::vector<std::vector<int> > matrix(rows, std::vector<int>(cols));

	for (int r = 0; r < rows; r++)
		for (int c = 0; c < cols; c++)
			std::cin >> matrix[r][c];

	for (int c = cols - 1; c >= 0; c--)
		printReverseDiag(std::cout, matrix, matrix.size() - 1, c);

	for (int r = rows - 2; r >= 0; r--)
		printReverseDiag(std::cout, matrix, r, 0);

	return 0;
}