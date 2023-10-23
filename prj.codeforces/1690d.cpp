#include<iostream>
#include<vector>
#include<array>
#include<cmath>
#include<string>
#include<algorithm>
#include<limits.h>


int max(int a, int b) {
	return (a > b) ? a : b;
}
int min(int a, int b) {
	return (a < b) ? a : b;
}

int main()
{
	int amount_of_data = 0;
	std::cin >> amount_of_data;

	std::vector<int> results;
	for (int i = 0; i < amount_of_data; i++) {
		int len=0;
		int sub_len = 0;
		std::cin >> len >> sub_len;
		std::string str;
		std::cin >> str;
		std::vector<int> gaps;
		int min_counter = 1000000000;
		for (int j = 0; j <= len - sub_len; j++) {
			int counter = 0;
			for (int k = j; k < j + sub_len; k++) {
				if (str[k] == 'W') {
					counter++;
				}
			}
			//gaps.push_back(counter);
			min_counter = min(counter, min_counter);
		}
		/*int minimum = 100000000;
		for (int j : gaps) {
			if (j < minimum) {
				minimum = j;
			}
		}*/
		results.push_back(min_counter);

	}

	for (int i = 0; i < amount_of_data; i++) {
		std::cout << results[i]<<std::endl;
	}
	return 0;
}