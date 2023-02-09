#include <iostream>
#include <iomanip>
#include <cmath>
/*long long binary(long x, int &i);
int main()
{
    using namespace std;
    long x;
    cout << "Enter a decimal value:" << endl;
    cin >> x;
    while (x >= 0)
    {
        int i = -1;
        cout << "The binary value of " << x << " is " << binary(x, i) << endl;
        cout << "Enter a decimal value:" << endl;
        cin >> x;
    }
    cout << "Exit!!";
    return 0;
}
long long binary(long x, int &i)
{
    i++;
    if (x == 0)
        return 0;
    else
    {
        if (x % 2 == 1)
            return pow(10, i)+binary(x / 2, i);
        else
            return binary(x / 2, i);
    }
}*/
int gcd(int n1, int n2);
int lcm(int n1, int n2);
int main()
{
    using namespace std;
    int r5[5],r4[4],r3[3],r2[2],r1;
    cout << "Input five integer number:" << endl;
    for (int i=0; i<5; i++)
        cin >> r5[i];
    for (int i=0; i<4; i++)
        r4[i]=gcd(r5[i], r5[i+1]);
    for (int i=0; i<3; i++)
        r3[i]=gcd(r4[i], r4[i+1]);
    for (int i=0; i<2; i++)
        r2[i]=gcd(r3[i], r3[i+1]);
    r1 = gcd(r2[0], r2[1]);
    for (int i=0; i<5; i++)
    {
        r5[i]/=r1;
    }
    cout << "g.c.d. : " << r1 << endl;
    cout << "l.c.m. : " << r1*lcm(lcm(lcm(lcm(r5[0], r5[1]), r5[2]), r5[3]), r5[4]);
}
int gcd(int n1, int n2)
{
    if(n1<n2)
    {
        int temp=n1;
        n1=n2;
        n2=temp;
    }
    if (n2 == 0)
        return n1;
    else
        return gcd(n2,n1%n2);
}
int lcm(int n1, int n2)
{
    return n1*n2/gcd(n1, n2);
}
