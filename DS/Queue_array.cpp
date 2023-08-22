#include <iostream>
/*缺點:Front 和 rear 會不斷增加, 導致記憶體空閒, 需用Circular Queue*/
using namespace std;

class Queue
{
    public:
        Queue(int); //Constructor
        void Add(int);
        int Pop();
        bool IsFull();
        bool IsEmpty();
        ~Queue(); //Destructor
    private:
        void Full();
        void Empty();

        int *arr;
        int Maxsize; //Size of array
        int Front;
        int rear;
};

int main()
{
    Queue s(5);
    s.Add(1);
    s.Add(2);
    s.Add(3);
    s.Add(4);
    s.Add(5);
    while (!(s.IsEmpty()))
        cout << "pop element : " << s.Pop() << endl;
    return 0;
}

Queue::Queue(int Size):Maxsize(Size)
{
    arr = new int[Maxsize];
    Front = -1;
    rear = -1;
}

void Queue::Add(int value)
{
    if (IsFull())
        Full();
    else
        arr[++rear] = value;
}

int Queue::Pop()
{
    if (IsEmpty())
    {
        Empty();
        return -1;
    }
    else
        return arr[++Front];
}

bool Queue::IsFull()
{
    return (rear == (Maxsize - 1));
}

bool Queue::IsEmpty()
{
    return (Front == rear);
}

void Queue::Full()
{
    cerr << "out of maxsize" << endl;
}
void Queue::Empty()
{
    cerr << "Empty" << endl;
}
Queue::~Queue()
{
    delete [] arr;
}
