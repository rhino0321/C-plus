#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#define MaxSize 10

void checkspace(int [], int &, string);
void display(int [], int, string);
void GenerateMatrix(int [][MaxSize], const int, const int);
void Product(int [][MaxSize], int [][MaxSize], int [][MaxSize], const int, const int);

int main()
{
    // string str1;
    // int space[10], space_use = 0;
    // cout << "Enter your sentence: " << endl;
    // getline(cin, str1);
    // checkspace(space, space_use, str1);
    // display(space, space_use, str1);
    srand(time(0));
    int row, col;
    cout << "Please enter the number of rows and cols: ";
    cin >> row >> col;
    int matrix1[MaxSize][MaxSize], matrix2[MaxSize][MaxSize], matrix3[MaxSize][MaxSize];
    cout << "The Matrix1: rows=" << row << ", cols=" << col << endl;
    GenerateMatrix(matrix1, row, col);
    cout << "The Matrix2: rows=" << col << ", cols=" << row << endl;
    GenerateMatrix(matrix2, col, row);
    cout << "The Matrix3: rows=" << row << ", cols=" << row << endl;
    Product(matrix1, matrix2, matrix3, row, col);
    return 0;
}

void checkspace(int space[], int &space_use, string str1)
{
    int i=0;
    while (i < str1.length())
    {
        i = str1.find(" ", ++i); // ++i means search space from space next char
        if (i == string::npos)
            break;
        else
        {
            space[space_use] = i;
            space_use++;
        }
    }
}

void display(int space[], int space_use, string str1)
{
    int start=0;
    cout << "There are " << space_use + 1 << " words in your sentence." << endl;
    cout << "They are";
    for (int i=0; i<space_use; i++)
    {
        if (i != space_use - 1)
        {
            cout << " \"" << str1.substr(start, space[i] - start) << "\",";
            start = space[i] + 1;
        }
        else
        {
            cout << " \"" << str1.substr(start, space[i] - start) << "\" and";
            start = space[i] + 1;
        }

    }
    cout << " \"" << str1.substr(start, str1.length() - start + 1) << "\"" << endl;
}

void GenerateMatrix(int arr[][MaxSize], const int row, const int col)
{
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            arr[i][j] = rand() % 9 + 1;
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void Product(int arr1[][MaxSize], int arr2[][MaxSize], int arr3[][MaxSize], const int row, const int col)
{
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<row; j++)
        {
            arr3[i][j] = 0;
            for (int k=0; k<col; k++)
            {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
            cout << arr3[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}