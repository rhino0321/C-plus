#include <iostream>
using namespace std;

class money
{
    public:
        money(int dollar, int cent);
        money();
        void input();
        void output() const;
    private:
        int I_dollar(const double&) const;
        int I_cent(const double&) const;
        int dollar;
        int cent;
};

int main()
{
    money my(10, 9), your;
    your.input();
    cout << "Your amount is ";
    your.output();
    cout << "My amount is ";
    my.output();
    return 0;
}

money::money(int dollar_val, int cent_val) : dollar(dollar_val), cent(cent_val)
{}

money::money()
{}

void money::input()
{
    double input;
    cout << "Enter an amount of money : $";
    cin >> input;
    dollar = I_dollar(input);
    cent = I_cent(input);
}

void money::output() const
{
    cout << "$" << dollar << ".";
    if (cent >= 10)
        cout << cent << endl;
    else 
        cout << "0" << cent << endl; 
}

int money::I_dollar(const double& input) const
{ return (input * 100) / 100; }

int money::I_cent(const double& input) const
{ return int(input * 100) % 100; }

