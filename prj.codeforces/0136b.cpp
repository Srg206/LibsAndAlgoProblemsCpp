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
std::string Convert_to_third_deg(int a) {
	std::string str;
	while (a > 0) {
		str.push_back('0' + (a % 3));
		a /= 3;
	}
	return str;
}


int main()
{
	int number1 = 0;
	int number2 = 0;
	std::cin >> number1 >> number2;
	std::string string_1 = Convert_to_third_deg(number1);
	std::string string_2 = Convert_to_third_deg(number2);
	int max_size = max(string_1.size(), string_2.size());
	int min_size = min(string_1.size(), string_2.size());
	for (int i = min_size; i < max_size; i++) {
		if (string_1.size() < string_2.size()) {
			string_1.push_back('0');
		}
		else {
			string_2.push_back('0');
		}
	}
	std::string result;
	result.resize(string_2.size());
	for (int i = 0; i < string_2.size(); i++) {
		if (string_1[i] > string_2[i]) {
			result[i] = (3 - (string_1[i] - string_2[i])) + '0';
		}
		else {
			result[i] = (string_2[i] - string_1[i]) + '0';
		}
	}
	int res = 0;
	for (int i = 0; i < result.size(); i++) {
		res += pow(3, i) * (result[i] - '0');
	}

	std::cout << res;

	return 0;
}