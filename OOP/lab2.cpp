#include <iostream>
#include <initializer_list>
#include <stdexcept>
using namespace std;

/**
 * A dynamic array (vector) implementation for generic types.
 * 
 * This class provides functionality similar to the standard vector in C++,
 * allowing elements of type T to be stored and managed in a dynamic array.
 *
 * Attributes:
 *  - arr: A dynamic array used to store elements.
 *  - capacity: Total amount of space currently allocated for the vector.
 *  - space: Current number of elements stored in the vector.
 * 
 * Public Methods:
 *  - Vector(): Default constructor. Initializes the vector with a default capacity of 10.
 *  - Vector(int len): Constructor that initializes the vector with a given length.
 *  - Vector(int len, T value): Constructor that initializes the vector with a given length and fills it with the provided value.
 *  - Vector(std::initializer_list<T> initList): Constructor that initializes the vector with a list of values.
 *  - Vector(const Vector &other): Copy constructor to create a vector as a copy of another vector.
 *  - ~Vector(): Destructor to free up dynamically allocated memory.
 *  - size(): Returns the current number of elements stored in the vector.
 *  - push_back(const T &value): Adds an element to the end of the vector.
 *  - pop_back(): Removes and returns the last element of the vector.
 *  - operator[](size_t index): Overloaded subscript operator to return a reference to the element at the given index.
 *  - const operator[](size_t index) const: Overloaded subscript operator to access vector elements.
 *  - operator=(const Vector &other): Overloaded assignment operator to copy the contents from one vector to another.
 *  - operator+(const Vector &other) const: Overloaded addition operator to concatenate two vectors.
 *  - operator+=(const Vector &other): Overloaded addition assignment operator to concatenate two vectors.
 */
template <typename T>
class Vector {
   private:
    T *arr;
    size_t capacity;
    size_t space;

   public:
    Vector();
    Vector(size_t len);
    Vector(size_t len, T value);
    Vector(std::initializer_list<T> initList);
    Vector(const Vector &other);
    ~Vector();

    size_t size() const;
    void push_back(const T &value);
    T pop_back();
    T &operator[](size_t index);
    const T &operator[](size_t index) const;
    Vector &operator=(const Vector &other);

    Vector operator+(const Vector &other) const;
    Vector &operator+=(const Vector &other);
};

// Default constructor
// Thus we can initialize a vector like this:
// Vector<int> v;
template <typename T>
Vector<T>::Vector() : space(0), capacity(10) {
    arr = new T[capacity];
    // TODO: Allocate memory for the array and initialize it with default values.
}

// Constructor with length
// Thus we can initialize a vector like this:
// Vector<int> v(5);
template <typename T>
Vector<T>::Vector(size_t len) : space(len), capacity(len * 2) {
    arr = new T[capacity];
    // TODO: Allocate memory for the array and initialize it with default values.
}

// Constructor with length and initial value
// Thus we can initialize a vector like this:
// Vector<int> v(5, 10);
template <typename T>
Vector<T>::Vector(size_t len, T value) : space(len), capacity(len * 2) {
    arr = new T[capacity];
    for (int i = 0; i < space; i++)
        arr[i] = value;
    // TODO: Allocate memory for the array and initialize it with the given value.
}

// Constructor with initializer list
// Thus we can initialize a vector like this:
// Vector<int> v = {1, 2, 3, 4, 5};
template <typename T>
Vector<T>::Vector(std::initializer_list<T> initList)
    : space(initList.size()), capacity(initList.size() * 2) {
    arr = new T[capacity];
    size_t i = 0;
    for (const T &value : initList) {
        arr[i++] = value;
    }
}

// Copy constructor
// Copy all properties (capacity, space, value of arr) from one vector to another
// Thus we can initialize a vector like this:
// Vector<int> v1(v2);
template <typename T>
Vector<T>::Vector(const Vector &other) {
    capacity = other.capacity;
    space = other.space;
    arr = new T[capacity];
    for (int i = 0; i < space; i++)
        arr[i] = other.arr[i];
    // TODO: Copy all properties from other to this vector.
}

// Destructor
template <typename T>
Vector<T>::~Vector() {
    delete [] arr;
    // TODO: Free up dynamically allocated memory.
}

// Append an element to the end of the vector
// NOTE: If the vector is full, double the capacity and reassign the array pointer.
template <typename T>
void Vector<T>::push_back(const T &value) {
    if (space == capacity)
    {
        T* back = new T[capacity * 2];
        for (int i = 0; i < space; i++)
            back[i] = arr[i];
        capacity *= 2;
        delete [] arr;
        arr = back;
    }
    else 
        arr[space++] = value;
    // TODO: Check if the vector is full.
    // If so, double the capacity and reassign the array pointer.
    // Then append the element to the end of the vector.
}

// Remove and return the last element of the vector
template <typename T>
T Vector<T>::pop_back() {
    if (space > 0) {
        return arr[--space];
        // TODO: Remove and return the last element of the vector.
    }
    else {
        throw std::out_of_range("Vector is empty");
    }
}

// Return the current number of elements stored in the vector
template <typename T>
size_t Vector<T>::size() const {
    return space;
    // TODO:
}

// Overloaded assignment operator
// Copy all properties (capacity, space, value of arr) from one vector to another
template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other) {
    // TODO: Copy all properties from other to this vector.
    // Steps:
    // 1. free up the memory of the current vector.
    // 2. copy all properties from other to this vector.
    // 3. return *this.
    delete [] arr;
    arr = new T[other.capacity];
    capacity = other.capacity;
    space = other.space;
    for (int i = 0; i < space; i++)
        arr[i] = other.arr[i];
    return *this;
}

// Overloaded subscript operator.
// Return a reference to the element at the given index,
// so that we can ASSIGN a new value to the element
template <typename T>
T &Vector<T>::operator[](size_t index) {
    if (index >= space) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

// Overloaded subscript operator.
// Return a const reference to the element at the given index,
// so that we can READ the value of the element
template <typename T>
const T &Vector<T>::operator[](size_t index) const {
    if (index >= space) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

// Overloaded stream insertion operator.
// Print the vector to the output stream in the following format:
// [element1, element2, element3, ...]
template <typename T>
std::ostream &operator<<(std::ostream &out, const Vector<T> &v) {
    // TODO
    out << "[";
    for (int i = 0; i < v.size(); i++)
    {
        if (i == 0)
            out << v[i];
        else
            out << ", " << v[i];
    }
    out << "]";
    return out;
}

// Overloaded stream extraction operator.
// Read a value from the input stream and append it to the vector.
template <typename T>
std::istream &operator>>(std::istream &in, Vector<T> &v) {
    // TODO
    T value;
    in >> value;
    v.push_back(value);
    return in;
}

// Overloaded addition operator.
// Concatenate two vectors and return a new vector.
// For example, if v1 = [1, 2, 3] and v2 = [4, 5, 6],
// then v1 + v2 = [1, 2, 3, 4, 5, 6].
template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &other) const {
    // TODO
    Vector <T> z(space + other.space);
    for (int i = 0; i < space; i++)
        z[i] = arr[i];
    for (int i = 0; i < other.space; i++)
        z[space + i] = other.arr[i];
    return z;
}

// Overloaded addition assignment operator.
// Concatenate two vectors and assign the result to the first vector.
template <typename T>
Vector<T> &Vector<T>::operator+=(const Vector<T> &other) {
    // Steps:
    // 1. Calculate the new size and capacity
    // 2. Allocate new memory
    // 3. Copy the elements from the current vector
    // 4. Copy the elements from the other vector
    // 5. Clean up and reassign
    // 6. Return *this
    T* z = new T(capacity + other.capacity);
    for (int i = 0; i < space; i++)
        z[i] = arr[i];
    for (int i = 0; i < other.space; i++)
        z[space + i] = other.arr[i];
    delete [] arr;
    arr = z;
    space += other.space;
    capacity = space * 2;
    return *this;

}

int main() {
    // DO NOT MODIFY MAIN FUNCTION
    // DO NOT MODIFY MAIN FUNCTION
    // DO NOT MODIFY MAIN FUNCTION

    // Test Initialization
    Vector<int> v1;
    Vector<int> v2(5);
    Vector<int> v3(5, 10);
    Vector<int> v4{1, 2, 3, 4, 5};
    Vector<int> v5(v4);

    // Test input (Read from stdin)
    // >> -1 -2 -3 -4 -5
    for (int i = 0; i < 5; i++) {
        cin >> v1;
    }

    // Test size
    cout << v1.size() << endl;    // 5
    cout << v2.size() << endl;    // 5
    cout << v3.size() << endl;    // 5
    cout << v4.size() << endl;    // 5
    cout << v5.size() << endl;    // 5

    // Test output (Print to stdout)
    cout << v1 << endl;    // [-1, -2, -3, -4, -5]
    cout << v2 << endl;    // [0, 0, 0, 0, 0]
    cout << v3 << endl;    // [10, 10, 10, 10, 10]
    cout << v4 << endl;    // [1, 2, 3, 4, 5]
    cout << v5 << endl;    // [1, 2, 3, 4, 5]

    // Test Push Back
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);
    v1.push_back(10);
    cout << v1 << endl;    // [-1, -2, -3, -4, -5, 6, 7, 8, 9, 10]

    // Test Pop Back
    int pop1 = v1.pop_back();
    int pop2 = v1.pop_back();
    int pop3 = v1.pop_back();
    cout << pop1 << endl;    // 10
    cout << pop2 << endl;    // 9
    cout << pop3 << endl;    // 8
    cout << v1 << endl;      // [-1, -2, -3, -4, -5, 6, 7]

    // Test Subscript Operator
    cout << v1[0] << endl;    // -1
    cout << v1[1] << endl;    // -2
    cout << v1[2] << endl;    // -3

    v5[0] = 5;
    v5[1] = 20;
    v5[2] = 13;
    cout << v4 << endl;    // [1, 2, 3, 4, 5]
    cout << v5 << endl;    // [5, 20, 13, 4, 5]

    // Test Assignment Operator
    v1 = v3;
    cout << v1 << endl;    // [10, 10, 10, 10, 10]

    // Test Addition Operator
    Vector<int> v6 = v4 + v5;
    cout << v6 << endl;    // [1, 2, 3, 4, 5, 5, 20, 13, 4, 5]

    // Test Addition Assignment Operator
    v6 += v4;
    cout << v4 << endl;    // [1, 2, 3, 4, 5]
    cout << v6 << endl;    // [1, 2, 3, 4, 5, 5, 20, 13, 4, 5, 1, 2, 3, 4, 5]

    // Test template
    Vector<string> v7;
    v7.push_back("I");
    v7.push_back("don't");
    v7.pop_back();
    v7.push_back("love");
    v7.push_back("C++");
    cout << v7 << endl;    // [I, love, C++]

    return 0;
}
