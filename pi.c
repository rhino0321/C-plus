#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10000000
int main()
{
    srand(time(NULL));
    long long int number_in_circle = 0;
    for (int toss = 0; toss < size; toss++)
    {
        double x = ((double) rand()) * 2 / RAND_MAX - 1;
        double y = ((double) rand()) * 2 / RAND_MAX - 1;
        double distance_squared = x * x + y * y;
        if (distance_squared <= 1)
            number_in_circle++;
    }
    double pi_estimate = 4 * number_in_circle / ((double) size);
    printf("%.2lf\n", pi_estimate);
    return 0;
}
