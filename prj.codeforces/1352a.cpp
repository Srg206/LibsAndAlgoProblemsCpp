#include <iostream>
#include <cmath>
#include <vector>

int main()
{
    int del = 0;
    int n = 0;
    int Am_digits = 0;
    int Am_nuls = 0;
    std::cin >> n;
    std::vector<int> arr;       
    for (int i = 0; i < n; i++) {                    
        int z;
        std::cin >> z;
        arr.push_back(z);       
    }                               
    for (auto it = arr.begin(); it != arr.end(); it++) {
        int num = *it;
        int tmp = num;
        while (tmp > 0) {
            if (tmp % 10 == 0) {
                Am_nuls++;
            }
            Am_digits++;
            tmp = tmp / 10;
        }
        del = Am_digits - Am_nuls;
        int slog = 0;
        tmp = num;
        std::cout << del << std::endl;
        for (int i = 0; i < Am_digits; i++) {
            if (tmp % 10 != 0) {
                slog = (tmp % 10) * pow(10, i);
                std::cout << slog << " ";

                tmp = tmp / 10;
            }
            else{
                tmp = tmp / 10;
            }
        }
        Am_digits = 0;
        Am_nuls = 0;
    }
   
    return 0;
}
