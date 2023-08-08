#include <iostream>

using namespace std;

int count_cycle(int);

int main()
{
    int up, down, cycle = 0;
    cin >> up >> down;
    if (up < down)
    {
        int temp = up;
        up = down;
        down = temp;
    }
    for (int i = down; i <= up; i++)
    {
        int temp = count_cycle(i);
        if (temp > cycle)
            cycle = temp;
    }
    cout << cycle << endl;
    return 0;
}

int count_cycle(int num)
{
    int count = 1;
    while(num != 1)
    {
        if (num % 2 != 0)
            num = 3 * num + 1;
        else
            num /= 2;
        count++;
    }
    return count;
}
