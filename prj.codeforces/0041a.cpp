#include<iostream>
#include<string>

int main()
{
	std::string ber_str;
	std::string bir_str;

	std::string result="YES";
	std::cin >> ber_str >> bir_str;
	if (ber_str.size() != bir_str.size()) {
		result = "NO";
	}
	else {
		for (int i = 0; i < ber_str.size(); i++) {
			if (ber_str[i] != bir_str[bir_str.size() - 1 - i]) {
				result = "NO";
				break;
			}
		}
	}
	std::cout << result;

	return 0;
}