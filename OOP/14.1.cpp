#include <iostream>
using namespace std;

class employee
{
    public:
        employee():name("unname"), ssn("undefine ssn"), netpay(0){}
        employee(const string& thename, const string& thessn):name(thename), ssn(thessn), netpay(0){}
        string getname() const{
            return name;
        }
        string getssn() const{
            return ssn;
        }
        double getnetplay() const{
            return netpay;
        }
        void setname(const string& newname){
            name = newname;
        }
        void setssn(const string& newssn){
            ssn = newssn;
        }
        void setnetpay(const double& newnetpay){
            netpay = newnetpay;
        }
        void printcheck() const{
            cout << "this printcheck function shouldn't be called" << endl;
            exit(1);
        }
        virtual ~employee() = default;
    private:
        string name;
        string ssn;
    protected:
        double netpay;
};

class hourlyemployee : public employee
{
    public:
        hourlyemployee() : employee(), wageRate(0), hours(0){}
        hourlyemployee(const string& thename, const string& thessn) :employee(thename, thessn), wageRate(0), hours(0){}
        void setrate(double newWageRate){
            wageRate = newWageRate;
        }
        double getwagerate() const{
            return wageRate;
        }
        double gethours() const{
            return hours;
        }
        void setHours(double hoursworked){
            hours = hoursworked;
        }
        void printcheck(){
            netpay = (wageRate * hours);
            cout << "employee : " << getname() << endl;
            cout << "ssn : " << getssn() << endl;
            cout << "netpay : " << netpay << endl;
        }
    private:
        double wageRate;
        double hours;
};
void printinfo(employee *emp)
{
    if (dynamic_cast<hourlyemployee*> (emp))
    {
        hourlyemployee *ans = static_cast<hourlyemployee*> (emp);
        ans->printcheck();
    }
}
int main(){
    hourlyemployee jason("jason", "311512062");
    jason.setHours(5);
    jason.setrate(170);
    cout << "work hours : " << jason.gethours() << endl;
    cout << "rate : " << jason.getwagerate() << endl;
    jason.printcheck();
}
