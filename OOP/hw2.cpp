#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/* use template to fullfill binary tree */
template<class T>
class Node
{
    public:
        Node(T val);
        void main(Node<T>*);
        T data;
        ~Node(){
            delete left;
            delete right;
        }
    private:
        Node<T>* left;
        Node<T>* right;
        Node<T>* insert(Node<T>*, T);
        void printInOrder(const Node<T>*) const;
};

int main()
{
    string type;
    getline(cin, type);
    if (type == "char")
    {
        Node<char>* root = nullptr;
        root->main(root);
    }
    else if (type == "int")
    {
        Node<int>* root = nullptr;
        root->main(root);
    }
    return 0;
}

template<class T>
Node<T>::Node(T val) : data(val), left(nullptr), right(nullptr){}

template<class T>
Node<T>* Node<T>::insert(Node* root, T num)
{
    if (root == nullptr)
        return new Node<T>(num);
    if (root->data > num)
        root->left = insert(root->left, num);
    else
        root->right = insert(root->right, num);
    return root;
}

template<class T>
void Node<T>::printInOrder(const Node<T>* root) const
{
    if (root == nullptr)
        return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

template<class T>
void Node<T>::main(Node<T>* root)
{
    T num;
    string inputline;
    getline(cin, inputline);
    istringstream iss(inputline);
    while (iss >> num)
    {
        root = root->insert(root, num);
    }
    root->printInOrder(root);
    cout << endl;
    delete root;
}
