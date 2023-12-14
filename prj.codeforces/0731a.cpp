#include<iostream>
#include<string>



int max(int a, int b) {
	return (a > b) ? a : b;
}
int min(int a, int b) {
	return (a < b) ? a : b;
}

int main()
{
	int now_index = 'a';
	std::string str;
	std::cin >> str;
	int sum_shifts = 0;
	for (int i = 0; i < str.size(); i++) {
		sum_shifts = sum_shifts + (min(abs(str[i] - now_index), 26 - abs(str[i] - now_index)));
		now_index = str[i];
	}
	std::cout << sum_shifts;

	return 0;
}