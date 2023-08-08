#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n1, n2, digit = 0, carry = 0, flag = 0;
    cin >> n1 >> n2;
    double sum = (double)n1 + (double)n2;
    while (floor(sum / pow(10,digit)))
    {
        digit++;
    }
    int d =(int)digit;
    int arr1[d], arr2[d];
    for (int i = d - 1; i >= 0; i--)
    {
        arr1[i] = n1 % 10;
        n1 /= 10;
        arr2[i] = n2 % 10;
        n2 /= 10;
        if (arr1[i] + arr2[i] + flag >= 10)
        {
            carry++;
            flag = 1;
        }
        else
            flag = 0;
    }
    if (!carry)
        cout << "No carry operation.";
    else if (carry == 1)
        cout << carry << " carry operation.";
    else
        cout << carry << " carry operations.";
    return 0;
}
