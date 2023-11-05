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
		int len = 0;
		char c = ' ';
		std::string str;
		std::cin >> len >> c >> str;
		std::string str2 = str;
		for (int j = len; str[j - len] != 'g'; j++) {
			str2 += str[j - len];
		}
		str2 += 'g';
		int maximum_distance = -1;
		int counter = 0;

		int index_c = -1;
		int index_g = -1;
		bool is_open = false;
		for (int j = 0; j < str2.size(); j++) {
			if (str2[j] == c && !is_open) {
				index_c = j;
				is_open = true;
			}
			if (str2[j] == 'g' && is_open) {
				maximum_distance = max(maximum_distance, j - index_c);
				is_open = false;

			}
		}

		results.push_back(maximum_distance);
	}

	for (int i = 0; i < amount_of_data; i++) {
		std::cout << results[i] << std::endl;
	}
	return 0;
}