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
        int get_Front() const{return Front;}
        int get_rear() const{return rear;}
        void queue_clear();
        void doublecapacity();
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
    Queue s(6);
    s.Add(1);
    cout << "front:" << s.get_Front() << " rear:" << s.get_rear() << endl;
    s.Add(2);
    cout << "front:" << s.get_Front() << " rear:" << s.get_rear() << endl;
    s.Add(3);
    cout << "front:" << s.get_Front() << " rear:" << s.get_rear() << endl;
    s.Add(4);
    cout << "front:" << s.get_Front() << " rear:" << s.get_rear() << endl;
    s.Add(5);
    cout << "front:" << s.get_Front() << " rear:" << s.get_rear() << endl;
    s.Add(6);
    cout << "front:" << s.get_Front() << " rear:" << s.get_rear() << endl;
    while (!(s.IsEmpty()))
        cout << "front:" << s.get_Front() << " rear:" << s.get_rear() << " pop element:" << s.Pop() << endl;
    s.Add(7);
    cout << "front:" << s.get_Front() << " rear:" << s.get_rear() << endl;
    s.queue_clear();
    cout << "front:" << s.get_Front() << " rear:" << s.get_rear() << endl;
    return 0;
}

Queue::Queue(int Size):Maxsize(Size)
{
    arr = new int[Maxsize];
    for (int i = 0; i < Maxsize; i++)
        arr[i] = 0;
    Front = 0;
    rear = 0;
}

void Queue::queue_clear()
{
    for (int i = Front + 1; i < rear + 1; i++)
        arr[i] = 0;
    Front = 0;
    rear = 0;
}

void Queue::Add(int value)
{
    if (IsFull())
    {
        Full();
        doublecapacity();
    }
    rear = (rear + 1) % Maxsize;
    arr[rear] = value;
}

void Queue::doublecapacity()
{
    int *back = new int[Maxsize*2];
    for (int i = 0; i < Maxsize*2; i++)
    {
        if (i < Maxsize)
            back[i] = arr[i];
        else
            back[i] = 0;
    }
    Maxsize *= 2;
    delete [] arr;
    arr = back;
}

int Queue::Pop()
{
    if (IsEmpty())
    {
        Empty();
        return -1;
    }
    else
    {
        Front = (Front + 1) % Maxsize;
        int temp = arr[Front];
        arr[Front] = 0;
        return temp;
    }
}

bool Queue::IsFull()
{
    return (((rear + 1) % Maxsize) == Front);
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
