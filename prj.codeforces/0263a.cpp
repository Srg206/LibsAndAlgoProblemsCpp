#include <iostream>
#include <cmath>
int main()
{
    int matrix[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    int x = 0;
    int y = 0;
    int x_c = 3;
    int y_c = 3;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (matrix[i][j] == 1) {
                x = j + 1;
                y = i + 1;
            }
        }
    }
    int n = abs(x_c - x) + abs(y_c - y);
    std::cout << n;
}
