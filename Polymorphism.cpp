#include <iostream>

using namespace std;

// 1. Parent class (Base Class)
class Animal {
public:
    // Virtual member function
    virtual void makeSound() {
        cout << "Some generic animal sound." << endl;
    }
};

// 2. First Derived class overriding the function
class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Woof! Woof!" << endl;
    }
};

// 2. Second Derived class overriding the function
class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow! Meow!" << endl;
    }
};

int main() {
    // 3. Demonstrate runtime polymorphism using base-class pointers
    
    // Create base class pointers pointing to derived class objects
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    // Call the overridden function through the base-class pointers
    cout << "Dog object via Animal pointer: ";
    animal1->makeSound(); // Triggers Dog's makeSound() at runtime

    cout << "Cat object via Animal pointer: ";
    animal2->makeSound(); // Triggers Cat's makeSound() at runtime

    // Clean up dynamically allocated memory
    delete animal1;
    delete animal2;

    return 0;
}
