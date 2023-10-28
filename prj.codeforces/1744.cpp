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

		for (int j = 0; j < len; j++) {
			if (str2[j] == c) {
				for (int k = j; str2[k] != 'g'; k++) {
					counter++;
				}
				maximum_distance = max(maximum_distance, counter);
				counter = 0;
			}

		}

		results.push_back(maximum_distance);
	}

	for (int i = 0; i < amount_of_data; i++) {
		std::cout << results[i] << std::endl;
	}
	return 0;
}