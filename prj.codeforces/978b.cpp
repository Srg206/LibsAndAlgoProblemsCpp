#include<iostream>
#include <list>
#include <vector>
#include <string>
int main()
{
	int len = 0;
	std::string str;
	std::cin >> len;
	std::cin >> str;

	int kolvo = 0;
	int AllToDelete = 0;
	for (auto it = str.cbegin(); it != str.cend(); ++it) 
	{
		if (*it != 'x')
		{
			kolvo = 0;
		}
		else
		{
			kolvo++;
			if (kolvo >= 3)
			{
				AllToDelete++;
			}
		}
	}

	std::cout << AllToDelete;
	return 0;
}
