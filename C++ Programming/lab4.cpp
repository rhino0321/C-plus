#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    /*int i,j,flag,cont=1;
    while(cont)
    {
        cout<<"Enter the size of multiplication table(1~9):";
        cin>>flag;
        switch(flag)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                for(i=1;i1<=flag;i++)
                {
                    for(j=1;j<=flag;j++)
                    {
                        cout<< i << "*" << j << "="<<setw(2)<< i*j <<"\t";
                    }
                    while (i!=flag)
                    {
                        cout<<endl;
                        break;
                    }
                }
                cont=0;
                break;
            default:
                cout<<"The size of multiplication table should be 1~9."<<endl;
                break;
        }
    }*/
    int num,flag,j,sum;
    cout<<"Enter an integer value"<<endl;
    cin>>num;
    cout<<"All prime numbers below 28 are:"<<endl;
    for (int i=2;i<num;i++)
    {
        sum=0;
        flag=i/2;
        for(j=1;j<=flag;j++)
        {
            if(i%j==0)
                sum++;
            else
                sum=sum;
        }
        if(sum==1)
            cout<<i<<" ";
    }
    return 0;
}
