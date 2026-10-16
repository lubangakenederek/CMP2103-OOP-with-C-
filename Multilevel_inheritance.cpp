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
