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
		int counter_B = 0;
		int max_counter = -1000000000;
		for (int j = 0; j < sub_len; j++) {
			if (str[j] == 'B') {
				counter_B++;
			}
		}
		max_counter = counter_B;
		for (int j = 0; j <= len - sub_len; j++){
			if (str[j] == str[j+sub_len]) {
				
			}
			else {
				if (str[j] == 'W' && str[j + sub_len] == 'B') {
					counter_B++;
					max_counter = max(counter_B, max_counter);
				}
				if (str[j] == 'B' && str[j + sub_len] == 'W') {
					counter_B--;
					max_counter = max(counter_B, max_counter);
				}
			}
		}
		if (sub_len < max_counter) {
			max_counter = sub_len;
		}
		results.push_back(sub_len-max_counter);
	}

	for (int i = 0; i < amount_of_data; i++) {
		std::cout << results[i]<<std::endl;
	}
	return 0;
}