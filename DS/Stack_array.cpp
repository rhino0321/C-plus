#include <iostream>
using namespace std;

class Stack
{
    public:
        Stack(int); //Constructor
        void Add(int);
        int Pop();
        bool IsFull();
        bool IsEmpty();
        ~Stack(); //Destructor
    private:
        void Full();
        void Empty();

        int *arr;
        int Maxsize; //Size of array
        int top; //high position in array that contains an element
};

int main()
{
    Stack s(5);
    s.Add(1);
    s.Add(2);
    s.Add(3);
    s.Add(4);
    s.Add(5);
    while (!(s.IsEmpty()))
        cout << "pop element : " << s.Pop() << endl;
    return 0;
}

Stack::Stack(int Size):Maxsize(Size)
{
    arr = new int[Maxsize];
    top = -1;
}

void Stack::Add(int value)
{
    if (IsFull())
        Full();
    else
        arr[++top] = value;
}

int Stack::Pop()
{
    if (IsEmpty())
    {
        Empty();
        return -1;
    }
    else
        return arr[top--];
}

bool Stack::IsFull()
{
    return (top == (Maxsize - 1));
}

bool Stack::IsEmpty()
{
    return (top == -1);
}

void Stack::Full()
{
    cerr << "out of maxsize" << endl;
}
void Stack::Empty()
{
    cerr << "Empty" << endl;
}
Stack::~Stack()
{
    delete [] arr;
}
