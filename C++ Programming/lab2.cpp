#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
    char a,b;
    cout<<"Enter s, r, p for player 1:";
    cin>>a;
    cout<<"Enter s, r, p for player 2:";
    cin>>b;
    if((a=='r'&&b=='s')||(a=='s'&&b=='p')||(a=='p'&&b=='r'))
        cout<<"Player 1 win!\n\n";
    else if((b=='r'&&a=='s')||(b=='s'&&a=='p')||(b=='p'&&a=='r'))
        cout<<"Player 2 win!\n\n";
    else
        cout<<"Two players tie!\n\n";
    char x;
    int y,sum,xx;
    cout<<"Welcome to the book-buying system!!\n"<<"The following are the list and the cost:\n"<<
            "(A) Computer science: An Overview\t$30\n"<<"(B) Absolute C++\t$20\n"<<"(C) C++ How to program\t$40\n"
            <<"Please enter A, B, C to choose of books:"<<endl;
    cin>>x;
    xx=int(x);
    while(!(xx>=65&&xx<=67)&&!(xx>=97&&xx<=99))
    {
        cout<<"Sorry, item ("<<x<<") doesn't on our list.\n";
        cin>>x;
        xx=int(x);
    }
    cout<<"Now enter the quantity of books:"<<endl;
    cin>>y;
    switch(x)
    {
        case 'A':
            sum=30*y;
            break;
        case 'B':
            sum=20*y;
            break;
        case 'C':
            sum=40*y;
            break;
        case 'a':
            sum=30*y;
            break;
        case 'b':
            sum=20*y;
            break;
        case 'c':
            sum=40*y;
            break;
    }
    if(x=='A'||x=='B'||x=='C'||x=='a'||x=='b'||x=='c')
        cout<<"The total  cost of item ("<<'x'<<") is $"<<sum<<". Thanks for your coming.";
    return 0;
}
