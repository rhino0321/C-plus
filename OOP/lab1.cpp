#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class Pet {
public:
    string name;
    int age;
    
    Pet(string name, int age) :name(name), age(age){
    }
    
    string get_status() {
        return "(" + name + ", " + to_string(age) + ")";
    }
    
    string get_info(){
        return "Unknown species" + get_status();
    }

    virtual ~Pet() = default;
};

class Cat : public Pet {
public:
    Cat(string name, int age) : Pet(name, age){}
    string get_info(){
        return "Cat" + get_status();
    };
};

class Dog : public Pet {
public:
    Dog(string name, int age) : Pet(name, age){}
    string get_info(){
        return "Dog" + get_status();
    };
};

void printInfo(Pet *pet) {
    if (dynamic_cast<const Dog*> (pet))
    {
        Dog* vdog = static_cast<Dog*> (pet);
        string ans = vdog->get_info();
        cout << ans << endl;
    }
    else
    {
        Cat* vcat = static_cast<Cat*> (pet);
        string ans = vcat->get_info();
        cout << ans << endl;
    }
}

int main() { 
    
    string catName, dogName;
  	int catAge, dogAge;
  	cin >> catName >> catAge >> dogName >> dogAge;
  
  	Cat cat(catName, catAge);
  	Dog dog(dogName, dogAge);

    printInfo(&cat);
    printInfo(&dog);

    return 0;
}

