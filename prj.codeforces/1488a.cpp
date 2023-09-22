#include<iostream>
#include <list>
#include <vector>
#include <string>
int main()
{
	int k = 0;
	int x = 0;
	int y = 0;
	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++){
		int amount_of_operations = 0;
		std::cin >> x;
		std::cin >> y;
		int tmp = y;
		for (; (tmp % x) != 0; tmp--, amount_of_operations++){

		}
		int max_decrease = x;
		while (max_decrease * 10 < tmp){
			max_decrease = max_decrease * 10;
		}
		for (int i = max_decrease; i >= x; i /= 10){
			while (tmp >= i){
				tmp -= i;
				amount_of_operations++;
			}
		}

		std::cout << amount_of_operations << std::endl;

	}
	return 0;
}
