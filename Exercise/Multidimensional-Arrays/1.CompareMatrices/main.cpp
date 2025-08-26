#include <iostream>
#include <string>
#include <sstream>

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

void readMatrix(int outMatrix[][MAX_COLS], const int& rows, std::istream& inputStream, int& outCols)
{
	std::string line;
	for (int row = 0; row < rows; row++) {
		std::getline(inputStream, line);
		std::istringstream iss(line);

		int num, col;
		for (col = 0; iss >> num && col < MAX_COLS; col++)
			outMatrix[row][col] = num;

		outCols = col;
	}
}

bool compareMatrices(int first[][MAX_COLS], const int firstMatrixRows, const int firstMatrixCols, int second[][MAX_COLS], const int secondMatrixRows, const int secondMatrixCols)
{
	if (firstMatrixRows != secondMatrixRows || firstMatrixCols != secondMatrixCols)
		return false; // now we know we are comparing two equal in size matrices

	// It doesn't matter whether we use the rows/cols from the first or second matrix
	// reaching this loop means they're guaranteed to be equal
	for (size_t r = 0; r < firstMatrixRows; r++) {
		for (size_t c = 0; c < firstMatrixCols; c++) {
			if (first[r][c] != second[r][c])
				return false;
		}
	}

	return true;
}

int main()
{
	int firstMatrix[MAX_ROWS][MAX_COLS], secondMatrix[MAX_ROWS][MAX_COLS];
	int firstMatrixRows, secondMatrixRows;
	int firstMatrixCols, secondMatrixCols;


	std::cin >> firstMatrixRows >> std::ws; // std::ws alternative is std::cin.ignore()
	readMatrix(firstMatrix, firstMatrixRows, std::cin, firstMatrixCols);


	std::cin >> secondMatrixRows >> std::ws;
	readMatrix(secondMatrix, secondMatrixRows, std::cin, secondMatrixCols);


	std::cout << (compareMatrices(firstMatrix, firstMatrixRows, firstMatrixCols, secondMatrix, secondMatrixRows, secondMatrixCols) ? "equal" : "not equal") << std::endl;

	return 0;
}