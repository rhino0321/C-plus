#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void newline();
const int MaxSize = 10;
void DisplayMatrix(const int [][MaxSize],const int,const int);
void GenerateMatrix(int [][MaxSize],const int,const int);
void SortMatrix(int [][MaxSize],const int,const int);
void InsertionSort(int [],const int);

typedef struct
{
    long id;
    char gender[10];
    int age;
    int money;
}student;

int main()
{
    // student s[5];
    // s[0] = {9413599, "Male", 25, 10001};
    // s[1] = {9513622, "Male", 22, 500};
    // s[2] = {9613812, "Female", 20, 30};
    // s[3] = {9713964, "Female", 18, 66000};
    // double avr_age, sum_money;
    // cout << "Please enter your student id: ";
    // cin >> s[4].id;
    // cout << "Gender (M/F): ";
    // cin.getline(s[4].gender, 5);
    // newline();
    // cout << "Age: ";
    // cin >> s[4].age;
    // cout << "The amount of money in your own: ";
    // cin >> s[4].money;
    // avr_age = double(s[0].age + s[1].age + s[2].age + s[3].age + s[4].age) / 5;
    // sum_money = s[0].money + s[1].money + s[2].money + s[3].money + s[4].money;
    // for (int i = 0; i < size; i++)
    // {
    //     if (s[i].age >= 21 && s[i].money > 10000)
    //         cout << "id " << s[i].id << " is a adult & rich " << s[i].gender << endl;
    //     else if (s[i].age >= 21 && s[i].money <= 10000)
    //         cout << "id " << s[i].id << " is a adult & poor " << s[i].gender << endl;
    //     else if (s[i].age < 21 && s[i].money > 10000)
    //         cout << "id " << s[i].id << " is a young & rich " << s[i].gender << endl;
    //     else
    //         cout << "id " << s[i].id << " is a young & poor " << s[i].gender << endl;
    // }
    // cout << "This group is " << avr_age << " years old in average." << endl;
    // cout << "This group has $" << sum_money << " now" << endl;
    int row, col;
    int arr[MaxSize][MaxSize];
    cout << "Please enter the number of rows: ";
    cin >> row;
    cout << "Please enter the number of columns: ";
    cin >> col;
    cout << "The original matrix is" << endl;
    GenerateMatrix(arr, row, col);
    DisplayMatrix(arr, row, col);
    SortMatrix(arr, row, col);
    cout << "The modified matrix is" << endl;
    DisplayMatrix(arr, row, col);
    return 0;
}

void newline()
{
    char nextchar;
    do
    {
        cin.get(nextchar);
    } while (nextchar != '\n');
}

void DisplayMatrix(const int arr[][MaxSize], const int row, const int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void GenerateMatrix(int arr[][MaxSize], const int row, const int col)
{
    srand(time(0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 20 + 1;
        }
    }
}

void SortMatrix(int arr[][MaxSize], const int row, const int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            int key = arr[i][j];
            int idx = j - 1;
            while (idx >= 0 && arr[i][idx] < key)
            {
                arr[i][idx+1] = arr[i][idx];
                idx--;
            }
            arr[i][idx+1] = key;
        }
    }
}
