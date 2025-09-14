#include <iostream>

char * * allocateMatrix(const int & rows, const int & cols)
{
	char * * matrix = new char * [rows];
	for (int curRow = 0; curRow < rows; curRow++)
		matrix[curRow] = new char[cols];
	return matrix;
}

void deallocateMatrix(char * * matrix, const int & rows)
{
	for (int row = 0; row < rows; row++)
		delete[] matrix[row];
	delete[] matrix;
}

char * * readMatrix(std::istream & is, int & rows, int & cols)
{
	is >> rows >> cols;

	char * * matrix = allocateMatrix(rows, cols);
	for (int curRow = 0; curRow < rows; curRow++) {
		for (int curCol = 0; curCol < cols; curCol++)
			std::cin >> matrix[curRow][curCol];
	}
	return matrix;
}

char * * fillMatrix(char * * matrix, const int & rows, const int & cols, const char & fillChar)
{
	for (int curRow = 0; curRow < rows; curRow++) {
		for (int curCol = 0; curCol < cols; curCol++)
			matrix[curRow][curCol] = fillChar;
	}
	return matrix;
}

bool checkCoordinates(const int & rowIndexToCheck, const int & colIndexToCheck, const int & rows, const int & cols)
{
	return rowIndexToCheck >= 0 && rowIndexToCheck < rows &&
		   colIndexToCheck >= 0 && colIndexToCheck < cols;
}

void increment3x3Square(char * * matrix, const int & mineRow, const int & mineCol, const int & rows, const int & cols)
{
	for (int curRow = mineRow - 1; curRow <= mineRow + 1; curRow++) {
		for (int curCol = mineCol - 1; curCol <= mineCol + 1; curCol++) {
			if (checkCoordinates(curRow, curCol, rows, cols))
				matrix[curRow][curCol]++;
		}
	}
}

int main()
{
	int rows, cols;

	char * * matrix = readMatrix(std::cin, rows, cols);
	char * * resultMatrix = allocateMatrix(rows, cols);
	fillMatrix(resultMatrix, rows, cols, 0);

	for (int curRow = 0; curRow < rows; curRow++) {
		for (int curCol = 0; curCol < cols; curCol++) {
			if (matrix[curRow][curCol] == '!')
				increment3x3Square(resultMatrix, curRow, curCol, rows, cols);
		}
	}

	for (int curRow = 0; curRow < rows; curRow++) {
		for (int curCol = 0; curCol < cols; curCol++) {
			std::cout << static_cast<int>(resultMatrix[curRow][curCol]);
		}
		std::cout << std::endl;
	}

	deallocateMatrix(resultMatrix, rows);
	deallocateMatrix(matrix, rows);

	return 0;
}