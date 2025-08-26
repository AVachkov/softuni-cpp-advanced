#include <iostream>
#include <sstream>
#include <vector>

void readMatrix(std::istream& inputStream, std::vector<std::vector<int>>& matrix)
{
	for (int row = 0; row < matrix.size(); row++) {
		for (int col = 0; col < matrix[row].size(); col++) {
			inputStream >> matrix[row][col];
		}
	}
}

int main()
{
	int rows, cols;
	std::cin >> rows >> cols;

	std::vector<std::vector<int> > matrix(rows, std::vector<int>(cols));

	readMatrix(std::cin, matrix);

	int target;
	std::cin >> target;

	bool isFound = false;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (matrix[row][col] == target) {
				isFound = true;
				std::cout << row << ' ' << col << std::endl;
			}
		}
	}

	if (!isFound)
		std::cout << "not found" << std::endl;

	return 0;
}