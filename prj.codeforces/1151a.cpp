#include<iostream>
#include<vector>
#include<array>
#include<cmath>
#include<string>
#include<algorithm>

int min(int a, int b) {
	int min = 0;
	a > b ? min=b : min=a;
	return min;
}
int max(int a, int b) {
	int max = 0;
	a > b ? max=a : max=b;
	return max;
}

int main()
{
	int len = 0;
	std::string str;
	std::string gen="ACTG";

	std::cin >> len >> str;
	std::vector<int> sum_shifts;

	for (int i = 0; i <= len - 4; i++) {
		int shifts = 0;
		for (int j = i,k=0; k<4; j++,k++) {
			int a = str[j]-'A'+1;
			int b = gen[k]-'A'+1;
			int m= min(abs(a - b), 26-max(a,b)+min(a,b));
			shifts += m;
		}
		sum_shifts.push_back(shifts);
	}

	int minimum = 1000000;
	for (int i = 0; i < sum_shifts.size(); i++) {
		minimum = min(minimum, sum_shifts[i]);
	}
	std::cout << minimum;
	return 0;
}