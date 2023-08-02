#include <iostream>
#include <string> 
using namespace std;

class Pet {
public:
    string name;
    int age;
    
    Pet(string name_val, int age_val){
        name = name_val;
      	age = age_val;
    }
    
    string get_status() {
        return "(" + name + ", " + to_string(age) + ")";
    }
    
    virtual string get_info(){
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
    string ans = pet->get_info();
  	cout << ans << endl;  
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
