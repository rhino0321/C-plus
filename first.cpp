#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
    float a;
    cout<<"Please enter the base floating-point number:"<<endl;
    cin>>a;
    for (int i=1;i<5;i++)
    {
        if(i<4)
            cout<<setw(12)<<fixed<<setprecision(3)<<pow(a,i)<<endl;
        else
            cout<<setw(12)<<fixed<<setprecision(3)<<pow(a,i);
    }
    return 0;
}
