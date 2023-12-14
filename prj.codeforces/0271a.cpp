#include<iostream>

int main()
{
	int y = 0;
	std::cin >> y;
	for (int i = y+1; ; i++) {
		int a, b, c, d;
		a = i % 10;
		b = (i / 10) % 10;
		c = (i / 100) % 10;
		d = (i / 1000);
		if (a != b && a != c && a != d && b != c && b != d && c != d) {
			std::cout << i;
			break;
		}


	}
	

	return 0;
}
