#include<iostream>
#include<vector>
#include<array>
#include<cmath>
#include<string>
#include<algorithm>
int main()
{

	int amount_of_data = 0;
	int password_length = 0;
	int amount_of_special = 0;
	std::string str;
	std::vector<int> results;

	std::cin >> amount_of_data;

	for (int i = 0; i < amount_of_data; i++) {
		std::cin >> password_length;
		//std::getline(std::cin, str);  ?????????????????????????????????????????????????
		std::cin >> str;

		std::cin >> amount_of_special;
		std::vector<unsigned char> spec_abc;
		for (int j = 0; j < amount_of_special; j++) {
			unsigned char a;
			std::cin >> a;
			spec_abc.push_back(a);
		}

		std::array<unsigned int, 256> spec_abc_codes{ 0 };
		for (int i = 0; i < spec_abc.size(); i++) {
			spec_abc_codes[spec_abc[i]] = 1;
		}

		int counter = 0;
		int max_toegther = -1;
		std::vector<int> sub_str_len;
		int last_spec = 0;
		for (int i = 0; i < str.size(); i++) {
			if (spec_abc_codes[str[i]] == 1) {
				last_spec = i;
			}
		}
		if (last_spec == 0) {
			results.push_back(0);
		}
		else {
			for (int i = 0; i < str.size(); i++) {
				if (spec_abc_codes[str[i]] == 1) {
					if ((i + 1) >= str.size()) {
						sub_str_len.push_back(counter);
						counter = 0;
					}
					if (spec_abc_codes[str[i + 1]] == 1) {
						sub_str_len.push_back(counter);
						counter = 0;
					}
					else {
						sub_str_len.push_back(counter);
						if (i > 0 && spec_abc_codes[str[i - 1]] == 1) {
							counter = 0;
						}
							counter = 1;
					}
				}
				else {
					if (last_spec > i) {
						counter++;
					}
				}
			}
			sub_str_len.push_back(counter);
			int maximum = -1;
			for (int i = 0; i < sub_str_len.size(); i++) {
				if (sub_str_len[i] > maximum) {
					maximum = sub_str_len[i];
				}
			}
			results.push_back(maximum);
		}

	}
	for (int i = 0; i < results.size(); i++) {
		std::cout << results[i] << '\n';
	}
	return 0;
}