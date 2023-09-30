#include<iostream>
#include<vector>
int main()
{
	int amount = 0;
	int delta = 0;
	int counter = 0;
	std::cin >> amount >> delta;

	std::vector<int> numbers;
	for (int i = 0; i < amount; i++) {
		int a;
		std::cin >> a;
		numbers.push_back(a);
	}
	for (int i = 1; i < amount; i++) {
		if (numbers[i] <= numbers[i - 1]) {
			while (numbers[i] <= numbers[i - 1]) {
				numbers[i] += delta;
				counter++;
			}
		}
	}
	std::cout << counter;
	return 0;
}
