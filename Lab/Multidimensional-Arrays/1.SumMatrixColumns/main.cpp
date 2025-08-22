#include <iostream>
#include <vector>

void readMatrix(const size_t rows, const size_t cols, std::vector<std::vector<int>>& out)
{
	for (size_t r = 0; r < rows; r++) {
		for (size_t c = 0; c < cols; c++) {
			std::cin >> out[r][c];
		}
	}
}

int main()
{
	int rows, cols;
	std::cin >> rows >> cols;

	std::vector<std::vector<int> > matrix(rows, std::vector<int>(cols));

	readMatrix(rows, cols, matrix);

	for (size_t col = 0; col < matrix[0].size(); col++) {
		int colSum = 0;
		for (size_t row = 0; row < matrix.size(); row++) {
			colSum += matrix[row][col];
		}
		std::cout << colSum << std::endl;
	}

	return 0;
}