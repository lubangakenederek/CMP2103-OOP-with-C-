# C++ Polymorphism Assignment Explanation

This document explains the C++ program implemented to satisfy the requirements of the Object-Oriented Programming (OOP) assignment on **Polymorphism**.

## How the Code Meets the Requirements

### 1. Base Class with a Virtual Function
We defined a parent class called `Animal`. Inside it, we created a member function called `makeSound()`. By placing the `virtual` keyword before it, we tell the C++ compiler to decide which version of this function to run at **runtime** rather than compile-time.

```cpp
class Animal {
public:
    virtual void makeSound() { ... }
};
```

### 2. Two Derived Classes with Overrides
We created two child classes: `Dog` and `Cat`, which inherit from `Animal`. Both classes rewrite (override) the `makeSound()` function to produce their specific sounds using the `override` keyword for clarity and safety.

```cpp
class Dog : public Animal {
    void makeSound() override { ... }
};
```

### 3. Demonstrating Runtime Polymorphism
In the `main()` function, we declared pointers of the parent type (`Animal*`) but assigned them to newly allocated child objects (`new Dog()` and `new Cat()`). 

When we call `->makeSound()`, C++ looks at what the pointer is *actually pointing to* at runtime, resolving the call dynamically:
* `animal1->makeSound()` outputs **"Woof! Woof!"**
* `animal2->makeSound()` outputs **"Meow! Meow!"**

```cpp
Animal* animal1 = new Dog();
animal1->makeSound();
```

## Key Concepts Used
* **`using namespace std;`**: Avoids typing `std::` before `cout` and `endl`.
* **Runtime Polymorphism**: The ability for different classes to respond uniquely to the exact same function call.
* **Memory Management**: Used `delete` to safely free up heap memory allocated by `new`.
