#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Circle {
protected:
    double radius;
    double x, y;

public: 
    Circle() : x(0), y(0), radius(1) {
        cout << "Default Circle created at (" << x << ", " << y << ") with radius " << radius << endl;
    }
    Circle(double xCoord, double yCoord, double radius) : x(xCoord), y(yCoord), radius(radius) {
        cout << "Circle created at (" << x << ", " << y << ") with radius " << radius << endl;
    }
    Circle(const Circle& c) : x(c.x), y(c.y), radius(c.radius) {
        cout << "Circle copied from (" << c.x << ", " << c.y << ") with radius " << c.radius << endl;
    }
    ~Circle() {
        cout << "Circle at (" << x << ", " << y << ") with radius " << radius << " destroyed." << endl;
    }
    void setCenter(double xCoord, double yCoord) {
        x = xCoord;
        y = yCoord;
    }
    void setRadius(double r) {
        radius = r;
    }
    double area() const {
        return M_PI * radius * radius;
    }
    double length() {
        return 2 * M_PI * radius;
    }
    virtual void display() {
        cout << "Circle at (" << x << ", " << y << ") with radius " << radius << endl;
    }
};

class ColoredCircle : public Circle {
private:
    string color;
public:
    ColoredCircle() : Circle(), color("white") {
        cout << "Default ColoredCircle created with color " << color << endl;
    }
    ColoredCircle(double xCoord, double yCoord, double radius, string c) 
        : Circle(xCoord, yCoord, radius), color(c) {
        cout << "ColoredCircle created at (" << x << ", " << y << ") with radius " << radius << " and color " << color << endl;
    }
    ColoredCircle(const ColoredCircle& cc) 
        : Circle(cc), color(cc.color) {
        cout << "ColoredCircle copied from (" << cc.x << ", " << cc.y << ") with radius " << cc.radius << " and color " << cc.color << endl;
    }
    ~ColoredCircle() {
        cout << "ColoredCircle with color " << color << " destroyed." << endl;
    }
    void display() override {
        Circle::display();
        cout << "Color: " << color << endl;
    }
    void changeColor(string newColor) {
        color = newColor;
        cout << "Color changed to " << color << endl;
    }
    void printColoredSymbol() {
    if (color == "red")
        cout << "#FF0000" << endl;
    else if (color == "green")
        cout << "#00FF00" << endl;
    else if (color == "blue")
        cout << "#0000FF" << endl;
    else
        cout << "#FFFFFF" << color << endl;
    }
};

int main() {
 cout << " ~~~ Test base class ~~~ " << endl;
    Circle a;
    a.display();
    Circle b(2, 3, 5);
    b.display();
    Circle c(b);
    c.display();
    cout << "Area of circle b: " << b.area() << endl;
    cout << "Length of circle b: " << b.length() << endl;
    a.setCenter(10, 10);
    a.setRadius(7);
    cout << "After setters: ";
    a.display();


    cout << "\n=== DERIVED CLASS TEST ===\n\n";

    ColoredCircle f;      
    f.display();

    ColoredCircle f1(3, 3, 4, "green");
    f1.display();

    ColoredCircle f2(f1);
    f2.display();

 
    f1.changeColor("red");
    f1.printColoredSymbol();

    f2.changeColor("blue");
    f2.printColoredSymbol();

    return 0;
} 


