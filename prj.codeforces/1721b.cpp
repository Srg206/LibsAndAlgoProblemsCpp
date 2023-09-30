#include<iostream>
#include <vector>
#include <array>
#include <algorithm>
int main()
{
	int amount_of_data = 0;
	std::cin >> amount_of_data;
	int map_width = 0;
	int map_height = 0;
	int laser_x = 0;
	int laser_y = 0;
	int fatal_distance = 0;
	std::vector<int> results;


	for (int i = 0; i < amount_of_data; i++) {
		std::cin >> map_height >> map_width >> laser_y >> laser_x >> fatal_distance;
		
		int start_dead_x = laser_x-fatal_distance;
		int start_dead_y = laser_y-fatal_distance;
		int finish_dead_x = laser_x+fatal_distance;
		int finish_dead_y = laser_y+fatal_distance;

		bool is_blocked_up = start_dead_y <= 1;
		bool is_blocked_down = finish_dead_y >= map_height;
		bool is_blocked_left = start_dead_x <= 1;
		bool is_blocked_right = finish_dead_x >= map_width;

		if ((is_blocked_down && is_blocked_up)|| (is_blocked_left && is_blocked_right) || (is_blocked_left && is_blocked_up ) || (is_blocked_right && is_blocked_down)) {
			results.push_back(-1);
		}
		else {
			results.push_back(map_height+map_width-2);
		}
	}


	for (auto it = results.begin(); it != results.end(); it++) {
		std::cout << *it << std::endl;
	}

	
	return 0;
}
