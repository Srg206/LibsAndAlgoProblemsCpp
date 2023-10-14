#include<iostream>
#include<vector>
#include<array>
#include<cmath>
#include<string>
#include<algorithm>


int main()
{
	int amount_of_data = 0;
	std::cin >> amount_of_data;
	std::vector<int> results;


	for (int i = 0; i < amount_of_data; i++) {
		int len = 0;
		std::cin >> len;
		std::vector<int> array;
		for (int i = 0; i < len; i++) {
			int a;
			std::cin >> a;
			array.push_back(a);
		}		
		for (int i = 1; i < len; i++) {
			array[i] = array[i-1] & array[i];
		}
		results.push_back(array[len-1]);
	}


	for (int i = 0; i < amount_of_data; i++) {
		std::cout << results[i] << std::endl;
	}

	return 0;
}