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
        int getCapacity() const{ return capacity; }
        int getUsed() const { return used; }
        record(const record& other); //copy constructor
        record& operator =(const record& rightside); // assignment operator
        double& operator[](int index);
        ~record() { delete [] a; } //Destructor
    private:
        double *a;
        int capacity;
        int used;
};

int main(){
    record jason;
    double next;
    cin >> next;
    while (next >= 0)
    {
        jason.addElement(next);
        cin >> next;
    }
    record vincent = jason;
    for (int i = 0; i < vincent.getUsed(); i++)
        cout << vincent[i] << " ";
    cout << endl;
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

double& record::operator [](int index)
{
    return a[index];
}
record::record(const record& other) :capacity(other.getCapacity()), used(other.getUsed())
{
    a = new double[capacity];
    for (int i = 0; i <used; i++)
        a[i] = other.a[i];
}
