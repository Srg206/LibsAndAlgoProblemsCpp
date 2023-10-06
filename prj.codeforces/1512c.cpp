#include<iostream>
#include<vector>
#include<array>
#include<cmath>
#include<string>
#include<algorithm>

void Amount_of_signs(std::string s, int& nuls, int& ones, int& quests) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '?') {
			quests++;
		}
		if (s[i] == '0') {
			nuls++;
		}
		if (s[i] == '1') {
			ones++;
		}
	}

}
bool Can_be_Polindrom(std::string s) {
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i] && s[i] != '?' && s[s.size() - 1 - i] != '?') {
			return false;
		}
	}
	return true;

}

int main()
{

	int amount_of_data = 0;
	std::string str;
	std::vector<std::string> results;

	std::cin >> amount_of_data;

	for (int j = 0; j < amount_of_data; j++) {
		int nuls = 0;
		int ones = 0;
	//	std::string str;
		std::cin >> nuls >> ones >> str;
		int len = nuls + ones;
		if (!Can_be_Polindrom(str)) {
			results.push_back("-1");
			continue;
		}

		int count_0 = 0;
		int count_1 = 0;
		int count_quests = 0;
		Amount_of_signs(str, count_0, count_1, count_quests);

		if (count_0 > nuls || count_1>ones) {
			results.push_back("-1");
			continue;
		}


		for (int i = 0; i < len / 2; i++) {
			if (str[i] == '0' && str[len - 1 - i] == '?' && count_0 < nuls) {
				str[len - 1 - i] = '0';
				count_0++;
				count_quests--;
			}
			if (str[i] == '1' && str[len - 1 - i] == '?' && count_1 < ones) {
				str[len - 1 - i] = '1';
				count_1++;
				count_quests--;

			}
		}

		for (int i = 0; i < len / 2; i++) {
			if (str[len - 1 - i] == '0' && str[i] == '?') {
				str[i] = '0';
				count_0++;
				count_quests--;
			}
			if (str[len - 1 - i] == '1' && str[i] == '?') {
				str[i] = '1';
				count_1++;
				count_quests--;
			}
		}


		//Amount_of_signs(str, count_0, count_1, count_quests);

		if (count_quests % 2 == 0) {
			if ((nuls - count_0) % 2 == 0 && (ones - count_1) % 2 == 0) {
				for (int i = 0; i < len / 2; i++) {
					if (nuls - count_0 > 1) {
						if (str[i] == '?') {
							str[i] = '0';
							str[len - 1 - i] = '0';
							count_0 += 2;

						}
					}
					else if (ones - count_1 > 1) {
						if (str[i] == '?') {
							str[i] = '1';
							str[len - 1 - i] = '1';
							count_1 += 2;

						}
					}
					else {
						results.push_back(str);
						break;
					}
				}
			}
			else {
				results.push_back("-1");
				continue;
			}
		}
		else {
			if (nuls - count_0 + ones - count_1 != count_quests) {
				results.push_back("-1");
				continue;
			}
			if ((nuls - count_0) % 2 != 0 && (nuls - count_0) > 0) {
				str[len / 2] = '0';
				count_0--;
			}

			if ((ones - count_1) % 2 != 0 && (ones - count_1) > 0) {
				str[len / 2] = '1';
				count_1--;

			}
			int it = 0;
			for (int i = 0; i < len / 2; i++) {
				if (nuls - count_0 > 1) {
					if (str[i] == '?') {
						str[i] = '0';
						str[len - 1 - i] = '0';
						count_0 += 2;

					}
				}
				else if (ones - count_1 > 1) {
					if (str[i] == '?') {
						str[i] = '1';
						str[len - 1 - i] = '1';
						count_1 += 2;

					}
				}
				else {
					results.push_back(str);
					break;
				}
			}

		}	
		if (j == results.size()) {
			results.push_back(str);
		}
	}
	//std::cout << "\n";


	for (int i = 0; i < results.size(); i++) {

		std::cout << results[i];
		if (i + 1 != results.size()) {
			std::cout << '\n';

		}
	}
	return 0;
}