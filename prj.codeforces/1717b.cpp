#include<iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
int main()
{
	int amount_of_data = 0;
	std::cin >> amount_of_data;
	std::vector<std::vector<std::vector<char>>> results;
	for (int i = 0; i < amount_of_data; i++) {
		int matrix_size = 0;
		int fatal_distance = 0;
		int first_x = 0;
		int first_y = 0;
		std::cin >> matrix_size;
		std::cin >> fatal_distance;
		std::cin >> first_x;
		std::cin >> first_y;
		first_x-=1;
		first_y-=1;
		std::vector<std::vector<char>> map(matrix_size, std::vector<char>(matrix_size, '.'));
		map[first_y][first_x] = 'X';
		int x_in_str = matrix_size/fatal_distance;
		//climbing up the matrix
		int startx = first_x;
		for (int i = first_y; i>=0; i--){
			for (int j = 0; j < x_in_str; j++) {
				int x = (startx + (j * fatal_distance)) % matrix_size;
				map[i][x] = 'X';
			}
			startx = (startx + 1) % matrix_size;
		}
		//going down the matrix
		startx = first_x;
		for (int i = first_y; i < matrix_size; i++) {
			for (int j = 0; j < x_in_str; j++) {
				int x = (startx + (j * fatal_distance)) % matrix_size;
				map[i][x] = 'X';
			}
			startx = (startx - 1+fatal_distance) % matrix_size;
		}
		results.push_back(map);
	}


	for (auto it = results.begin(); it != results.end(); it++) {
		for (auto i = (*it).begin(); i != (*it).end(); i++) {
			for (auto j = (*i).begin(); j != (*i).end(); j++) {
				std::cout << *j;
			}
			std::cout << '\n';
		}
	}

	
	return 0;
}
