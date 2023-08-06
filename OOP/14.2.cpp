#include <iostream>
using namespace std;
/* Copy Constructor, Assignment operator, Destructor */
/* use reference & is more efficiency */
class record
{
    public:
        record():capacity(50), used(0)
        { a = new double[capacity]; }
        record(int capacity):capacity(capacity), used(0)
        { a = new double[capacity]; }
        void addElement(double element)
        { a[used] = element; used++; }
        void emptyarray();
        int getCapacity() const{ return capacity; }
        int getUsed() const { return used; }
        record(const record& other); //copy constructor
        record& operator =(const record& rightside); // assignment operator
        double& operator[](int index);
        void printinfo() const;
        ~record() { delete [] a; } //Destructor
    protected:
        double *a;
        int capacity;
        int used;
};

class recordB : public record
{
    public:
        recordB() : record(),usedb(0)
        { b = new double[capacity]; }
        recordB(int capacity) : record(capacity), usedb(0)
        { b = new double[capacity]; }
        recordB(const recordB& other); /*derive constructor*/
        recordB& operator =(const recordB& rightside); /*derive assignment operator*/
        double& operator[](int index);
        void backup();
        void restore();
        void printinfo() const;
        ~recordB() { delete [] b; }
    private:
        double *b;
        int usedb;

};
int main(){
    recordB jason;
    double next;
    cin >> next;
    while (next >= 0)
    {
        jason.addElement(next);
        cin >> next;
    }
    //jason.backup();
    // recordB vincent;
    // vincent = jason;
    // vincent.printinfo();
    // vincent.record::printinfo();
    jason.record::printinfo();
    jason.backup();
    jason.printinfo();
    jason.emptyarray();
    cout << jason.getUsed() << " numbers stored in array.\n";
    jason.restore();
    jason.record::printinfo();
}

record& record::operator =(const record& rightside)
{
    if (capacity != rightside.capacity)
    {
        delete [] a;
        a = new double[rightside.capacity];
    }
    capacity = rightside.capacity;
    used = rightside.used;
    for (int i = 0; i < used; i++)
        a[i] = rightside.a[i];
    return *this;
}

recordB& recordB::operator =(const recordB& rightside)
{
    record::operator =(rightside); 
    if (capacity != rightside.capacity)
    {
        delete [] b;
        b = new double[rightside.capacity];
    }
    usedb = rightside.usedb;
    for (int i = 0; i < usedb; i++)
        b[i] = rightside.b[i];
    return *this;
}

double& record::operator [](int index)
{
    return a[index];
}

double& recordB::operator [](int index)
{
    return b[index];
}

void record::emptyarray()
{
    for(int i = 0; i < used; i++)
        a[i] = 0;
    used = 0;
}

record::record(const record& other) : capacity(other.getCapacity()), used(other.getUsed())
{
    a = new double[capacity];
    for (int i = 0; i <used; i++)
        a[i] = other.a[i];
}

recordB::recordB(const recordB& other) : record(other), usedb(0)
{
    b = new double[capacity];
    usedb = other.usedb;
    for (int i = 0; i < usedb; i++)
        b[i] = other.b[i];
}

void recordB::backup()
{
    usedb = used;
    for (int i = 0; i < usedb; i++)
        b[i] = a[i];
}

void recordB::restore()
{
    used = usedb;
    for (int i = 0; i < used; i++)
        a[i] = b[i];
}

void record::printinfo() const
{
    for (int i = 0; i < used; i++)
        cout << a[i] << " ";
    cout << endl;
}

void recordB::printinfo() const
{
    for (int i = 0; i < usedb; i++)
        cout << b[i] << " ";
    cout << endl;
}