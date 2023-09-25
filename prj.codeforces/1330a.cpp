#include<iostream>
#include <vector>
#include <array>
#include <algorithm>
int main()
{
	int amount_of_data = 0;
	std::cin >> amount_of_data;
	std::vector<int> results;

	for (int i = 0; i < amount_of_data; i++) {
		int init_amount=0;
		int addit_amount = 0;
		std::cin >> init_amount;
		std::cin >> addit_amount;
		std::vector<int> rating;
		// filling in vector
		for (int j = 0; j < init_amount; j++) {
			int tmp = 0;
			std::cin >> tmp;
			rating.push_back(tmp);
		}
		//
		std::vector<int> lost_indexes(init_amount + addit_amount + 1,0);
		for (auto it = rating.begin(); it != rating.end(); it++) {
			if (init_amount + addit_amount + 1 > *it){
				lost_indexes[*it] = 1;
			}
		}

		int used_nums = 0;
		int last_element = 0;
		for (int i = 1;i<= init_amount + addit_amount; i++) {
			if (lost_indexes[i] == 0) {
				if (used_nums >= addit_amount)
				{
					break;
				}
				used_nums++;
				lost_indexes[i] = 1;
				last_element = i;
			}
			last_element = i;
		}
		results.push_back(last_element);
	}
	for (auto it = results.begin(); it != results.end(); it++) {
		std::cout << *it << std::endl;
	}

	
	return 0;
}
