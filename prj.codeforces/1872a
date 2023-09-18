#include<iostream>
#include <vector>	

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int t = 0;

	std::vector<int> results;

	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> a;
		std::cin >> b;
		std::cin >> c;
		int min = a > b ? b : a;
		int max = a + b - min;
		int kolvo = 0;
		while (max > min)
		{
			max = max - c;
			min = min + c;
			kolvo++;
		}
		results.emplace_back(kolvo);
	}

	for (auto it = results.begin(); it != results.end(); it++) {
		int index = std::distance(results.begin(), it);
		std::cout << *it << std::endl;
	}

	return 0;
}
