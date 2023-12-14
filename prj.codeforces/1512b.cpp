#include<iostream>
#include<vector>
#include<string>


int main()
{
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;
	int amount_of_data = 0;
	std::vector<std::vector<std::string>> results;
	std::vector<int> len;
	std::cin >> amount_of_data;
	for (int i = 0; i < amount_of_data; i++) {
		int matrix_size = 0;
		std::cin >> matrix_size;
		std::vector<std::string> matrix;
		for (int j = 0; j < matrix_size; j++) {
			//getline(std::cin,matrix[j]);
			std::string s;
			std::cin >> s;
			matrix.push_back(s);
		}


		int dot_counter = 0;
		for (int j = 0; j < matrix_size; j++) {
			for (int k = 0; k < matrix_size; k++) {
				if (matrix[j][k] == '*' && dot_counter == 0) {
					x1 = k;
					y1 = j;
				}
				if (matrix[j][k] == '*' && dot_counter == 1) {
					x2 = k;
					y2 = j;
				}
			}
		}



		if (x1 ==x2) {
			matrix[y1][(x1+1)%matrix_size] = '*';
			matrix[y2][(x1 + 1) % matrix_size] = '*';
		}
		if (y1 == y2) {
			matrix[(y1+1)%matrix_size][x1] = '*';
			matrix[(y2+1)%matrix_size][x2] = '*';
		}
		if (x1 > x2 && y1 < y2) {
			matrix[y1][x2] = '*';
			matrix[y2][x1] = '*';
		}
		if (x1 < x2 && y1 > y2) {
			matrix[y1][x2] = '*';
			matrix[y2][x1] = '*';
		}


		results.push_back(matrix);
		len.push_back(matrix_size);
	}

	for (int i = 0; i < amount_of_data; i++) {
		for (int j = 0; j < len[i]; j++) {
			for (int k = 0; k < len[i]; k++) {
				std::cout << results[i][j][k];
			}
			std::cout << std::endl;
		}
	}

	

	return 0;
}