#include<iostream>
#include<vector>
#include<string>

int main()
{

	int amount_of_data = 0;
	int len = 0;
	int together_elements = 0;
	std::string str;
	std::vector<int> results;
	std::cin >> amount_of_data;
	for (int i = 0; i < amount_of_data; i++) {
		std::cin >> len >> together_elements >> str;

		int counter = 0;
		for (int j = 0; j < len; j++) {
			if (str[j] == 'B') {
				for (int k = j; k < j + together_elements && k<len; k++) {
					str[k] = 'W';
				}
				counter += 1;
				j += together_elements-1;
			}
		}
		results.push_back(counter);

	}


	for (int i = 0; i < amount_of_data; i++) {
		std::cout << results[i]<<std::endl;
	}


	return 0;
}