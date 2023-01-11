#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
    int a,b;
    float c;
    cout<<"Enter the first number:"<<endl;
    cin>>a;
    cout<<"Enter the second number:"<<endl;
    cin>>b;
    cout<< a << "+" << b<< "=" << a+b <<endl;
    cout<< a << "-" << b<< "=" << a-b <<endl;
    cout<< a << "*" << b<< "=" << a*b <<endl;
    cout<< a << "/" << b<< "=" << a/b <<endl;
    cout<<"Please enter the base floating point number:"<<endl;
    cin>>c;
    cout<< "10 to the power of 1, 2, 3 and 4 are:"<<endl;
    for (int i=1;i<5;i++)
    {
        i<4 ?cout<<setw(12)<<fixed<<setprecision(3)<<pow(c,i)<<endl:cout<<setw(12)<<fixed<<setprecision(3)<<pow(c,i);
    }
}
