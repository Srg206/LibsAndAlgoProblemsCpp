#include<iostream>
#include <list>
#include <vector>
#include <string>
int main()
{
	int k = 0;
	int x = 0;
	int y = 0;
	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int Amount_Operations=0;
		std::cin >> x;
		std::cin >> y;
		int tmp = y;
		for (; (tmp % x) != 0; tmp--,Amount_Operations++)
		{

		}
		int Max_Decrease=x;
		while (Max_Decrease*10 < tmp)
		{
			Max_Decrease = Max_Decrease * 10;
		}
		//std::cout<< Max_Decrease <<std::endl;
		for (int i = Max_Decrease; i >= x; i /= 10)
		{
	//	std::cout<< i <<std::endl;
			while (tmp>=i)
			{
				tmp -= i;
				Amount_Operations++;
			}
		}

		std::cout << Amount_Operations <<std::endl;

	}
	return 0;
}
