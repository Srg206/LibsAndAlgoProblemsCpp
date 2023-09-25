#include<iostream>
int main()
{	
	int amount = 0;
	int delta = 0;
	int counter = 0;
	std::cin >> amount>>delta;


	int* numbers = new int[amount];
	for (int i = 0; i < amount; i++) {
		std::cin >> numbers[i];
	}
	for (int i = 1; i < amount; i++) {
		if (numbers[i] <= numbers[i - 1])
		{
			while (numbers[i] <= numbers[i - 1]) {
				numbers[i] += delta;
				counter++;
			}
		}

	}
	std::cout << counter;




	return 0;
}
