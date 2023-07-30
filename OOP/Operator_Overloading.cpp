#include <iostream>
using namespace std;

class money
{
    public:
        money(int dollar, int cent);
        money();
        void input();
        void output() const;
        int get_dollar() const;
        int get_cent() const;
    private:
        int I_dollar(const double&) const;
        int I_cent(const double&) const;
        int dollar;
        int cent;
};

bool operator ==(const money&, const money&);
const money operator +(const money&, const money&);
const money operator -(const money&, const money&);

int main()
{
    money my(10, 9), your, sum, dif;
    your.input();
    cout << "Your amount is ";
    your.output(); cout << endl;
    cout << "My amount is ";
    my.output(); cout << endl;
    if (my == your)
        cout << "We are equal!" << endl;
    else
        cout << "One of us is richer!" << endl;
    sum = your + my;
    dif = your - my;
    your.output(); cout << " + "; my.output(); cout << " equals "; sum.output(); cout << endl;
    your.output(); cout << " - "; my.output(); cout << " equals "; dif.output(); cout << endl;
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
        cout << cent;
    else 
        cout << "0" << cent;
}

int money::I_dollar(const double& input) const
{ return (input * 100) / 100; }

int money::I_cent(const double& input) const
{ return int(input * 100) % 100; }

bool operator ==(const money& amount1, const money& amount2)
{ return (amount1.get_dollar() == amount2.get_dollar() && amount1.get_cent() == amount2.get_cent()); }

const money operator +(const money& amount1, const money& amount2)
{
    int sum = (amount1.get_dollar() + amount2.get_dollar())* 100 + (amount1.get_cent() + amount2.get_cent());
    return money(sum / 100, sum % 100);
}

const money operator -(const money& amount1, const money& amount2)
{
    int sum = (amount1.get_dollar() * 100 + amount1.get_cent()) - (amount2.get_dollar() * 100 + amount2.get_cent());
    return money(sum / 100, sum % 100);
}

int money::get_dollar() const
{ return dollar; }

int money::get_cent() const
{ return cent; }
