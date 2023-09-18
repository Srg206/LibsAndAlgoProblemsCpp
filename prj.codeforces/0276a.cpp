#include <iostream>

int main()
{
    int n = 0;
    int k = 0;
    std::cin >> n;
    std::cin >> k;
    int **arr=new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[2];
    }
    int *list_num=new int[n];    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            std::cin >> arr[i][j];
        }
    }
    int ans = 0;
    int Amount_of_ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i][1] >= k) {
            ans = arr[i][0] - (arr[i][1] - k);
            list_num[i] = ans;
        }
        else {
            ans = arr[i][0];
            list_num[i] = ans;
        }
    }
    int maximum = -1000000000;
    for (int i = 0; i < n; i++) {
        if (list_num[i] > maximum) {
            maximum = list_num[i];
        }
    }
    std::cout << maximum << std::endl;
}
