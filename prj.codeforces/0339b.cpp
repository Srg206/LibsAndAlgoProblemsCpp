#include<iostream>
#include<vector>

int min(int a, int b) {
	int min = 0;
	a > b ? min = b : min = a;
	return min;
}
int max(int a, int b) {
	int max = 0;
	a > b ? max = a : max = b;
	return max;
}

int main()
{
	long long int amount_of_houses = 0;
	long long int amount_of_things = 0;
	std::vector<long long int> things;
	std::cin >> amount_of_houses >> amount_of_things;
	for (int i = 0; i < amount_of_things; i++) {
		long long int tmp = 0;
		std::cin >> tmp;
		things.push_back(tmp);
	}
	long long int counter = things[0]-1;
	for (int i = 1; i < amount_of_things; i++) {
		long long int deltatime = 0;
		if (things[i - 1] > things[i]) {
			deltatime=amount_of_houses-(things[i-1]-things[i]);
		}
		else {
			deltatime = things[i] - things[i - 1];
		}
		counter += deltatime;
	}
	std::cout << counter;

	return 0;
}