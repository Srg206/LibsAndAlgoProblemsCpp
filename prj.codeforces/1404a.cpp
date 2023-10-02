#include<iostream>
#include<vector>
#include<array>
#include<cmath>
#include<string>
#include<algorithm>
int main()
{

	int amount_of_data = 0;
	std::vector<std::string> results;
	std::cin >> amount_of_data;

	std::string str;
	int len = 0;
	int sub_len = 0;
	for (int i = 0; i < amount_of_data; i++) {
		std::cin >> len >> sub_len >> str;

		bool is_balanced = true;
		for (int j = 0; j <= len - sub_len; j++) {
			int count_1 = 0;
			int count_0 = 0;
			int count_quests = 0;
			for (int k = j; k < j + sub_len; k++) {
				if (str[k] == '1') {
					count_1++;
				}
				if (str[k] == '0') {
					count_0++;
				}
				if (str[k] == '?') {
					count_quests++;
				}

			}
			if ((sub_len / 2) < count_1 || (sub_len / 2) < count_0) {
				is_balanced = false;
			}
			int need_1 = (sub_len / 2) - count_1;
			int need_0 = (sub_len / 2) - count_0;
			if (need_0 == 0 && need_1 != 0 && str[j + sub_len - 1] == '?') { 
				str[j + sub_len - 1] = '1';
			}
			if (need_1 == 0 && need_0 != 0) {
				str[j + sub_len - 1] = '0';
			}
		}
		if (is_balanced) {
			results.push_back("YES");
		}
		else {
			results.push_back("NO");
		}
	}
	for (int i = 0; i < results.size(); i++) {
		std::cout << results[i] << std::endl;
	}
	return 0;
}