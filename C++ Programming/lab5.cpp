#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    /*srand(time(0));
    char computer,player1;
    cout<<"Enter s, r, p for player 1:";
    cin>>player1;;
    int x = rand()%3 + 1;
    switch(x)
    {
        case 1:
            computer='s';
            break;
        case 2:
            computer='r';
            break;
        case 3:
            computer='p';
            break;
    }
    cout<<"Enter s, r, p for player 2:"<<computer<<endl;
    if((player1=='r'&&computer=='s')||(player1=='s'&&computer=='p')||(player1=='p'&&computer=='r'))
        cout<<"Player 1 win!";
    else if((computer=='r'&&player1=='s')||(computer=='s'&&player1=='p')||(computer=='p'&&player1=='r'))
        cout<<"Player 2 win!";
    else
        cout<<"Two players tie!";*/
    int value1,value2,gcd,temp,flag=1,lcm;//temp用來存放value1的因數
    cout<<"Input value 1:"<<endl;
    cin>>value1;
    cout<<"Input value 2:"<<endl;
    cin>>value2;
    if(!(value2%value1))
    {
        gcd=value1;
        flag=0;
    }
    for(int i=1;(i<=(value1/2))&&flag;i++)
    {
        if(!(value1%i))
            temp=i;
        if(!(value2%temp))
            gcd=temp;
    }
    lcm=value1*value2/gcd;
    cout<<"g.c.d.:"<<gcd<<endl;
    cout<<"l.c.m.:"<<lcm<<endl;
    return 0;
}
