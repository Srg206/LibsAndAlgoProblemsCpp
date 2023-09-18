#include<iostream>
#include <vector>	

int main()
{
	long long int a, n, m;
	std::cin >> n >> m >> a;
	if (n % a == 0){
		if (m % a == 0) {
			std::cout << (n / a) * (m / a);
		}
		else {
			std::cout << (n / a) * ((m / a)+1);
		}
	}
	else {
		if (m % a == 0) {
			std::cout << (m / a) * ((n / a)+1);
		}
		else {
			std::cout << ((m / a)+1) * ((n / a)+1);
		}
	}
	return 0;
}
