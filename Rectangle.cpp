#include <iostream>

class Rectangle {
// Encapsulation_-_Making sure sensitive is hidden from the user. Use private 
private:
    double width;
    double length;

public:
    // Method to set the width
    void setWidth(double w) {
        width = w;
    }
// To access private members, use get(returns the value) and set (sets the value), both declared like functions
    // Method to set the length
    void setLength(double l) {
        length = l;
    }
  
    // Method to calculate and return the perimeter
    double getPerimeter() const {
        return 2 * (length + width);
    }

    // Method to calculate and return the area
    double getArea() const {
        return length * width;
    }
};

int main() {
    Rectangle rect;

    // Setting dimensions
    rect.setWidth(5.0);
    rect.setLength(10.0);

    // Displaying results
    std::cout << "Perimeter: " << rect.getPerimeter() << std::endl;
    std::cout << "Area: " << rect.getArea() << std::endl;

    return 0;
}
