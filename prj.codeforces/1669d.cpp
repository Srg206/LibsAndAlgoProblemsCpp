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

	std::vector<std::string> results;
	for (int i = 0; i < amount_of_data; i++) {
		std::string res = "YES";
		int len = 0;
		std::string str;
		std::cin >> len >> str;

		if (len < 3) {
			if (len == 1 && str[0] != 'W') {
				res = "NO";
			}
			if (len == 2 && str != "WW" && str != "BR" && str != "RB") {
				res = "NO";
			}
		}

		int counter = 0;
		std::string s;
		char c = ' ';
		char last_symbol = 'W';
		bool in_substr = false;
		for (int j = 0; j < len; j++) {
			if (str[j] != 'W' && last_symbol == 'W') {
				in_substr = true;
				c = ' ';
				s.clear();
				c = str[j];
				s += str[j];
			}
			if (str[j] != 'W' && last_symbol != 'W') {
				if (str[j] != c) {
					s += str[j];
				}
			}
			if ((str[j] == 'W' || j == len - 1) && in_substr) {
				if (s.size() == 1) {
					res = "NO";
					s.clear();
					c = ' ';
				}
			}


			last_symbol = str[j];
		}

		/*	17
				RWBRBWRBBBBBBWWBR*/
		results.push_back(res);
	}

	for (int i = 0; i < amount_of_data; i++) {
		std::cout << results[i] << std::endl;
	}
	return 0;
}