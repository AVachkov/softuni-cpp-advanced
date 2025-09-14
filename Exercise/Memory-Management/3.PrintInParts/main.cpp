#include <iostream>

int main()
{
	int rows, cols;
	std::cin >> rows >> cols;

	int * * const matrix = new int * [rows];
	// what "int * * matrix" means:
	// every row of "matrix" contains a single pointer
	// that single pointer points to array

	// what "new int * [rows]" means
	// dynamically allocating array of "rows" elements
	// each element of that array is of type "int *"

	// visualisation:
	// each "int *" element can be used to point to array
	// int * * matrix is just the start of our matrix ([0][0])
	//        ---------
	// row 0  | int * | -------------> [][][][][][][][]
	//        ---------
	// row 1  | int * | -------------> [][][][][][][][]
	//        ---------
	// row 2  | int * | -------------> [][][][][][][][]
	//        ---------

	for (int curRow = 0; curRow < rows; curRow++) {
		matrix[curRow] = new int[cols];
		for (int curCol = 0; curCol < cols; curCol++) {
			std::cin >> matrix[curRow][curCol];
		}
	}

	int r, c;
	std::cin >> r >> c;

	for (int row = 0; row < r; row++) {
		for (int col = 0; col < c; col++) {
			std::cout << matrix[row][col] << ' ';
 		}
		std::cout << std::endl;
	}

	for (int curRow = 0; curRow < rows; curRow++)
		delete[] matrix[curRow];
	delete[] matrix;

	return 0;
}
