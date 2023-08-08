#include <iostream>
#include <cstring>
using namespace std;

void swap(int *a, int *b);

int main()
{
    int time, len, i = 0;
    cin >> time;
    while(i < time)
    {
        cin >> len;
        int arr[len], count = 0;
        for (int i = 0; i < len; i++)
        {
            int num;
            cin >> num;
            arr[i] = num;
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (arr[i] > arr[j])
                {
                    swap(arr+i, arr+j);
                    count++;
                }
            }
        }
        cout << "Optimal train swapping takes " << count << " swaps." << endl;
        i++;
    }
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}
