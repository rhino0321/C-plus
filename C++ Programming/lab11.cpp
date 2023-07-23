#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    int **m = new int*[2];
    int p1, p2;
    cout << "Please enter the degree of polynomial 1: ";
    cin >> p1;
    m[0] = new int[p1];
    cout << "Please enter the coefficient in order: ";
    for (int i = 0; i < p1 + 1; i++)
    {
        cin >> m[0][i];
        cout << m[0][i] << " ";
    }
    cout << endl;
    cout << "Please enter the degree of polynomial 2: ";
    cin >> p2;
    m[1] = new int[p2];
    cout << "Please enter the coefficient in order: ";
    for (int i = 0; i < p2 + 1; i++)
    {
        cin >> m[1][i];
        cout << m[1][i] << " ";
        m[0][p1-(p2-i)] += m[1][i];
    }
    cout << endl;
    cout << "Sum = ";
    for (int i = 0; i < p1 + 1; i++)
    {
        cout << m[0][i] << " ";
    }
    cout << endl;

    delete[] m[0];
    delete[] m[1];
    delete[] m; 
    // srand(time(0));
    // int n, same, rd;
    // cout << "Please enter a number: ";
    // cin >> n;
    // while (n > 0)
    // {
    //     int *m = new int [n];
    //     for (int i = 0; i < n; i++)
    //     {
    //         do
    //         {
    //             same = 0;
    //             rd = rand() % n + 1;
    //             if (i == 0)
    //             {
    //                 m[i] = rd;
    //             }
    //             else
    //             {
    //                 for (int j = 0; j < i; j++)
    //                 {
    //                     if (rd == m[j])
    //                     {
    //                         same = 1;
    //                         break;
    //                     }
    //                 }
    //             }
    //         } while (same == 1);
    //         m[i] = rd;
    //         cout << m[i] << " ";
    //     }
    //     cout << endl;
    //     delete[] m;
    //     cout << "Please enter a number: ";
    //     cin >> n;
    // }
    return 0;
}