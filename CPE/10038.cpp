#include <iostream>
using namespace std;

int main()
{
    int len;
    cin >> len;
    int arr[len], flag = 0;
    for (int i = 0; i < len; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }
    for (int i = 0; i < len - 1; i++)
    {
        if (abs(arr[i] - arr[i+1]) >= len)
            flag = 1;
    }
    if (flag)
        cout << "Not jolly";
    else
        cout << "Jolly";
    return 0;
}
