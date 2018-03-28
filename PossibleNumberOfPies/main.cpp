#include <iostream>
#include <vector>

int pumpkinCount(std::vector<int> ingredients) {
	int minValue = INT_MAX;

	// checks if there are ingredients missing
	for (int i : ingredients)
		if (i == 0)
			return 0;

	// checks all ingredients for the most we can make
	if (ingredients[0] / 1 < minValue)
		minValue = ingredients[0] / 1;

	if (ingredients[1] / 3 < minValue)
		minValue = ingredients[1] / 3;

	if (ingredients[2] / 4 < minValue)
		minValue = ingredients[2] / 4;

	if (ingredients[3] / 3 < minValue)
		minValue = ingredients[3] / 3;

	return minValue;
}

int appleCount(std::vector<int> ingredients) {
	int minValue = INT_MAX;

	// checks if there are ingredients missing
	for (int i : ingredients)
		if (i == 0)
			return 0;

	// checks all ingredients for the most we can make
	if (ingredients[0] / 1 < minValue)
		minValue = ingredients[0] / 1;

	if (ingredients[1] / 4 < minValue)
		minValue = ingredients[1] / 4;

	if (ingredients[2] / 3 < minValue)
		minValue = ingredients[2] / 3;

	if (ingredients[3] / 2 < minValue)
		minValue = ingredients[3] / 2;

	return minValue;
}

void maxPies(int pumpkinPieCount, int applePieCount, std::vector<int> ingredients, int &maxP, int &maxA) {
	maxA = applePieCount;
	maxP = 0;
	std::vector<int> currentIngredients;
	int maxValue = applePieCount;
	int temp = 0;

	// checking all possile combinations
	for (int i = pumpkinPieCount; i > 0; i--) {

		// passing leftover ingredients for apple to use
		currentIngredients = { ingredients[1],ingredients[2] - 3 * i,ingredients[3] - 4 * i,ingredients[4] - 3 * i };
		temp = i + appleCount(currentIngredients);

		if (temp >= maxValue) {
			maxValue = temp;
			maxP = i;
			maxA = appleCount(currentIngredients);
			
		}
	}

	// use this loop twice to get all possible pie combos
	for (int i = pumpkinPieCount; i > 0; i--) {

		// passing leftover ingredients for apple to use
		currentIngredients = { ingredients[1],ingredients[2] - 3 * i,ingredients[3] - 4 * i,ingredients[4] - 3 * i };
		temp = i + appleCount(currentIngredients);

		if (temp >= maxValue) {
			maxValue = temp;
			maxP = i;
			maxA = appleCount(currentIngredients);
			std::cout << maxP << " pumpkin pies and " << maxA << " apple pies" << std::endl;
		}
	}
}

int main() {
	char eater;
	int pumpkin, apple, eggs, milk, sugar;
	
	while (true) {
		// reads in all the ingredients 
		std::cin >> pumpkin >> eater >> apple >> eater >> eggs >> eater >> milk >> eater >> sugar;

		// seting up my ingredients
		std::vector<int> ingredients = { pumpkin, apple, eggs, milk, sugar };
		std::vector<int> pumpkinPie = { pumpkin, eggs, milk,  sugar };
		std::vector<int> applePie = { apple,  eggs,  milk,  sugar };

		int maxP = 0;
		int maxA = 0;

		// find the the most pies that can be made
		maxPies(pumpkinCount(pumpkinPie), appleCount(applePie), ingredients, maxP, maxA);

		//std::cout << maxP << " pumpkin pies and " << maxA << " apple pies" << std::endl;
	}
}
