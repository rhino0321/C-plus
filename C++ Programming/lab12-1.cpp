#include <iostream>
#include <cstring>
using namespace std;

// function declaration
void InsertionSort(int *, int);
int* resize(int *, int, int);
void medium(int *, int);

int main()
{
    int *array;
    int n, x, count = 0;

    cout << "Enter a size first: ";
    cin >> n;
    array = new int [n];
    cout << "Enter a sequence (stop by -1):" << endl;
    while (cin >> x)
    {
        count++;
        if (x == -1) break;
        else
        {
            if (count > n)
            {
                array = resize(array, count, x);
            }
            else
                array[count - 1] = x;
        }
    }
    InsertionSort(array, count - 1);
    medium(array, count - 1);
    return 0;
}

void InsertionSort(int *vec,int size)
{
    for (int jdx = 1; jdx < size; jdx++)
    {
        int key = vec[jdx];
        int idx = jdx - 1;
        while ( idx >= 0 && vec[idx] > key)
        {
            vec[idx+1] = vec[idx];
            --idx;
        }
        vec[idx+1] = key;
    }
}

int* resize(int *array, int count, int x)
{
    int *resize_arr = new int[count];
    memcpy(resize_arr, array, (count - 1) * sizeof(int));
    resize_arr[count - 1] = x;
    delete [] array;
    array = resize_arr;
    return array;
}

void medium(int *array, int size)
{
    if (size % 2 == 0)
    {
        cout << "The medium are "
             << array[(size / 2) - 1]
             << " and "
             << array[(size / 2)]
             << ".";
    }
    else
    {
        cout << "The medium is "
             << array[size / 2];
    }
    cout << endl;
}