# C++ Multilevel Inheritance Demonstration

This document explains a complete C++ program demonstrating **Multilevel Inheritance**, an Object-Oriented Programming (OOP) concept where a class is derived from another derived class.

---

## Complete Source Code

```cpp
#include <iostream>
#include <string>
using namespace std;

// 1. Grandparent Class (Base Class)
class Vehicle {
public:
    // Data member
    string brand = "Tesla";

    // Member function
    void startEngine() {
        cout << "Engine started... Vroom!" << endl;
    }
};

// 2. Parent Class (Derived from Vehicle)
class Car : public Vehicle {
public:
    // Data member
    int numberOfDoors = 4;

    // Member function
    void drive() {
        cout << "The car is driving on the road." << endl;
    }
};

// 3. Child Class (Derived from Car)
class ElectricCar : public Car {
public:
    // Data member
    int batteryCapacity = 100; // in kWh

    // Member function
    void charge() {
        cout << "Charging the battery... Currently at " << batteryCapacity << "% capacity." << endl;
    }
};

// Main function to run the demonstration
int main() {
    // 4. Create an object of the most derived class (ElectricCar)
    ElectricCar myEv;

    cout << "--- Demonstrating Inherited Members ---" << endl;
    
    // Accessing a data member inherited from the Grandparent class (Vehicle)
    cout << "Vehicle Brand: " << myEv.brand << endl;

    // Accessing a data member inherited from the Parent class (Car)
    cout << "Number of Doors: " << myEv.numberOfDoors << endl;

    // Calling functions inherited from base classes
    myEv.startEngine(); // Inherited from Vehicle
    myEv.drive();       // Inherited from Car

    cout << "\n--- Demonstrating Locally Defined Members ---" << endl;
    
    // Accessing locally defined members inside ElectricCar
    cout << "Battery Level: " << myEv.batteryCapacity << " kWh" << endl;
    myEv.charge();      // Defined locally in ElectricCar

    return 0;
}
```

---

## Detailed Code Explanation

### 1. The Inheritance Hierarchy
The program models a 3-tier multilevel inheritance structure:
* **`Vehicle` (Grandparent / Base Class):** The top-level class containing fundamental vehicle features like `brand` and `startEngine()`.
* **`Car` (Parent / Intermediate Derived Class):** Inherits publicly from `Vehicle`. This means it automatically gains all public attributes and behaviors of `Vehicle`, while adding its own specific characteristics (`numberOfDoors` and `drive()`).
* **`ElectricCar` (Child / Most Derived Class):** Inherits publicly from `Car`. Consequently, it inherits everything from `Car` as well as everything `Car` inherited from `Vehicle`. It adds specific EV features (`batteryCapacity` and `charge()`).

### 2. Accessing Inherited and Local Members
Inside the `main()` function, an object of the most specific class is created: `ElectricCar myEv;`. Through this single object, we can see multilevel inheritance in action:
* **Grandparent Members:** `myEv.brand` and `myEv.startEngine()` are fully accessible even though they are defined up in `Vehicle`.
* **Parent Members:** `myEv.numberOfDoors` and `myEv.drive()` are accessible because they are defined in `Car`.
* **Local Members:** `myEv.batteryCapacity` and `myEv.charge()` belong directly to `ElectricCar`.

---

## Expected Output

When compiled and run, the program produces the following console output:

```text
--- Demonstrating Inherited Members ---
Vehicle Brand: Tesla
Number of Doors: 4
Engine started... Vroom!
The car is driving on the road.

--- Demonstrating Locally Defined Members ---
Battery Level: 100 kWh
Charging the battery... Currently at 100% capacity.
```
