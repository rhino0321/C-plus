/* size : sides of die */
/* time of rolling die */
#include <stdio.h>
#include <stdlib.h>
const int siz=6;
const int time=5;
int count;
void problem4(int [], int, int);
int main()
{
    int die[time], idx = 0, sum = 0;
    problem4(die, idx, sum);
    printf("count=%d\n", count);
    system("pause");
    return 0;
}
void problem4(int die[], int idx, int sum)
{
    if(idx == time)
    {
        if(sum == 15)
            count++;
        else
            count=count;
    }
    else
    {

        for (int i=0; i<siz; i++)
        {
            int temp = sum;
            die[idx] = (i+1);
            temp += die[idx];
            if ( idx+1 <= time)
                problem4(die, idx+1, temp);
        }

    }
}
