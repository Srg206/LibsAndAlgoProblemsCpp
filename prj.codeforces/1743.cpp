#include<iostream>
#include<vector>
#include<array>
#include<cmath>
#include<string>
#include<algorithm>

class pyramid {
public:
	pyramid(int h) {
		height = h;
		steps.resize(height);
		for (int i = 0; i < height; i++) {
			steps[i].resize(i);
		}
	}
	int operator()(int i, int j) {
		return steps[i][j];

	}
	void operator()(int i, int j, int val) {
		steps[i][j]=val;

	}
	int geth() {
		return height;
	}
private:
	int height;
	std::vector<std::vector<int>> steps;

};

int main()
{
	int amount_of_data = 0;
	std::cin >> amount_of_data;
	std::vector<pyramid> results;


	for (int i = 0; i < amount_of_data; i++) {
		int len = 0;
		std::cin >> len;
		pyramid py(len);
		for (int i = 0; i < len; i++) {
			py(i, 0, 1);
			py(i, i-1,0);

		}
		
		results.push_back(py);
		
	}


	for (int i = 0; i < amount_of_data; i++) {
		for (int k = 0; k <results[i].geth(); k++) {
			for (int j = 0; j < k; j++) {
				std::cout << results[i](k, j);
			}
			std::cout << '\n';
		}
	}

	return 0;
}