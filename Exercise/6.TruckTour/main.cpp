#include <iostream>
#include <queue>

bool canFinish(std::queue<int> litres, std::queue<int> distances)
{
	int fuel = 0;
	while (litres.size() && distances.size()) {
		int fuelToPump = litres.front();
		int distanceToNext = distances.front();
		litres.pop(); distances.pop();

		fuel += fuelToPump;
		if (fuel < distanceToNext) // can't continue to next pump from current position
			return false;

		fuel -= distanceToNext;
	}

	return true;
}

int main()
{
	int n;
	std::cin >> n;

	std::queue<int> litres, distances;

	while (n--) {
		int petrolAmount, distanceToNextPump;
		std::cin >> petrolAmount >> distanceToNextPump;

		litres.push(petrolAmount);
		distances.push(distanceToNextPump);
	}

	int index = 0;
	for ( ; index < litres.size(); index++) {

		if (canFinish(litres, distances))
			break;

		// return the previous args so that we can loop trough the full circle
		int curLiter = litres.front();
		int curDistance = distances.front();

		litres.pop();
		distances.pop();

		litres.push(curLiter);
		distances.push(curDistance);
	}

	std::cout << index << std::endl;

	return 0;
}