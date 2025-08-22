#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <iomanip>

double getAverage(const std::vector<double>& grades)
{
	double sum = 0.0;
	for (const double& grade : grades)
		sum += grade;

	return sum / (double)grades.size();
}

int main()
{
	std::map<std::string, std::vector<double>> studentGrades;

	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::string name;
		std::cin >> name;

		double grade;
		std::cin >> grade;

		studentGrades[name].push_back(grade);
	}

	std::cout << std::fixed << std::setprecision(2);
	for (const std::pair<const std::string, std::vector<double>>& pair : studentGrades) {
		std::cout << pair.first << " -> ";
		for (const double& grade : pair.second)
			std::cout << grade << ' ';

		std::cout << "(avg: " << getAverage(pair.second) << ")" << std::endl;
	}

	return 0;
}