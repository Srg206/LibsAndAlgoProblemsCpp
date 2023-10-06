#include<iostream>
#include<vector>
#include<array>
#include<cmath>
#include<string>
#include<algorithm>

int min(int a, int b) {
	int min = 0;
	a > b ? min = b : min = a;
	return min;
}
int max(int a, int b) {
	int max = 0;
	a > b ? max = a : max = b;
	return max;
}

int main()
{

	int amount_of_data = 0;

	std::vector<int> results;

	std::cin >> amount_of_data;

	for (int j = 0; j < amount_of_data; j++) {
		std::vector<std::string> matrix;
		int sum_of_score = 0;

		for (int i = 0; i < 10; i++) {
			std::string tmp;
			std::cin >> tmp;
			matrix.push_back(tmp);
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (matrix[i][j] == 'X') {
					int dist = 0;
					if (i <= 4 && j <= 4) {
						dist = max(4 - i, 4 - j);
					}
					else if (i <= 4 && j >= 5) {
						dist = max(4 - i, j - 5);
					}
					else if (i >= 5 && j <= 4) {
						dist = max(i - 5, 4 - j);

					}
					else if (i >= 5 && j >= 5) {
						dist = max(i - 5, j - 5);

					}
					int score = 5 - dist;
					sum_of_score += score;
				}
			}
		}
		results.push_back(sum_of_score);
	}

	for (int i = 0; i < amount_of_data; i++) {
		std::cout<< results[i]<<std::endl;
	}
	return 0;
}