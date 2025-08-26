#include <iostream>
#include <vector>
#include <climits>

int current3x3Sum(const std::vector<std::vector<int> >& matrix, const int& startRow, const int& startCol)
{
	int sum = 0;
	for (int r = startRow; r < startRow + 3; r++)
		for (int c = startCol; c < startCol + 3; c++)
			sum += matrix[r][c];

	return sum;
}

int main()
{
	int rows, cols;
	std::cin >> rows >> cols;
	std::vector<std::vector<int> > matrix(rows, std::vector<int>(cols));

	for (int r = 0; r < rows; r++)
		for (int c = 0; c < cols; c++)
			std::cin >> matrix[r][c];

	int maxSum = INT_MIN, maxSumRowStart = 0, maxSumColStart = 0;
	for (int r = 0; r < rows - 2; r++) {
		for (int c = 0; c < cols - 2; c++) {
			int currentSquareSum = current3x3Sum(matrix, r, c);
			if (currentSquareSum > maxSum) {
				maxSum = currentSquareSum;
				maxSumRowStart = r;
				maxSumColStart = c;
			}
		}
	}

	std::cout << "Sum = " << maxSum << std::endl;
	for (int r = maxSumRowStart; r < maxSumRowStart + 3; r++) {
		for (int c = maxSumColStart; c < maxSumColStart + 3; c++) {
			std::cout << matrix[r][c] << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}