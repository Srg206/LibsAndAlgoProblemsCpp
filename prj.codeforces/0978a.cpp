#include<iostream>
#include <list>


int main()
{
	std::list<int> Arr;
	std::list<int> FinishArr;
	int _size = 0;
	std::cin >> _size;
	for (int i = 0; i < _size; i++)
	{
		int a = 0;
		std::cin >> a;
		Arr.push_front(a);
	}
	std::list<int>::iterator it;
	std::list<int>::iterator i;
	for (it = Arr.begin(); it != Arr.end(); ++it) {
		int kolvo_finish = count(FinishArr.begin(), FinishArr.end(), *it);
		if (kolvo_finish == 0)
		{
			FinishArr.push_front(*it);
		}
	}	
	std::cout<<FinishArr.size() <<std::endl;
	for (i = FinishArr.begin(); i != FinishArr.end(); ++i)
	{
		std::cout << *i << " ";
	}


	return 0;
}
