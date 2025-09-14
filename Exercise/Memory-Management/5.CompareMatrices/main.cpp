#include <iostream>
#include <sstream>

void deallocateMatrix(int * * matrix, const int & rows)
{
	for (int curRow = 0; curRow < rows; curRow++)
		delete[] matrix[curRow];
	delete[] matrix;
}

int * * readMatrix(std::istream & inputStream, int & rowsOut, int & colsOut)
{
	std::cin >> rowsOut >> std::ws;

	int * * matrix = new int * [rowsOut];

	colsOut = 0; // sum up later
	for (int curRow = 0; curRow < rowsOut; curRow++) {
		std::string line;
		std::getline(inputStream, line);
		std::istringstream iss(line);

		const int cols = line.size() / 2 + 1;
		matrix[curRow] = new int[cols];

		int num;
		int curCol = 0;
		for ( ; iss >> num; curCol++)
			matrix[curRow][curCol] = num;
		colsOut = curCol;
	}

	return matrix;
}


bool compare(int * * a, int * * b,
			 const int & rowsA, const int & colsA,
			 const int & rowsB, const int & colsB)
{
	if (rowsA != rowsB || colsA != colsB)
		return false;

	for (int curRow = 0; curRow < rowsA; curRow++) {
		for (int curCol = 0; curCol < colsA; curCol++) {
			if (a[curRow][curCol] != b[curRow][curCol])
				return false;
		}
	}

	return true;
}


int main()
{
	int rowsA, rowsB;
	int colsA, colsB;

	int * * a = readMatrix(std::cin, rowsA, colsA);
	int * * b = readMatrix(std::cin, rowsB, colsB);

	std::cout << (compare(a, b, rowsA, colsA, rowsB, colsB) ? "equal" : "not equal") << std::endl;

	deallocateMatrix(a, rowsA);
	deallocateMatrix(b, rowsB);

	return 0;
}