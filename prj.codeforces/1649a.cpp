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
	std::vector<int> results;
	std::cin >> amount_of_data;

	for (int i = 0; i < amount_of_data; i++) {
		int len = 0;
		std::cin >> len;
		int counter_of_groups = 0;
		int max_counter = 0;
		int counter = 0;

		std::vector<int> levels;
		for (int j = 0; j < len; j++) {
			int a = 0;
			std::cin >> a;
			levels.push_back(a);
		}


		std::vector<int> gaps;
		int first_ind = 0;
		int last_ind = 0;
		for (int j = 0; j < levels.size(); j++) {
			if (levels[j] == 0) {
				first_ind = j;
				break;
			}
		}
		for (int j = 0; j < levels.size(); j++) {
			if (levels[j] == 0) {
				counter++;
				last_ind = j;
			}
			if (levels[j] == 1 && j != 0) {
				if (counter != 0) {
					gaps.push_back(counter);
				}
				counter = 0;
			}
		}
		
		if (gaps.size() > 1) {
			results.push_back(min(levels.size() - 1,last_ind-first_ind+2));
		}
		else if (gaps.size() == 0) {
			results.push_back(0);
		}
		else if (gaps.size() == 1) {
			results.push_back(gaps[0]+1);
		}
	}
	for (int i = 0; i < amount_of_data; i++) {
		std::cout << results[i]<<std::endl;

	}


	return 0;
}