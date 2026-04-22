#include <iostream>
#include <vector>
using namespace std;

// -------- BASE CLASS --------
class Shape {
public:
    virtual double Area() = 0; // pure virtual
    virtual ~Shape() {}
};

// -------- RECTANGLE --------
class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double Area() {
        return length * width;
    }
};

// -------- CIRCLE --------
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}

    double Area() {
        return 3.14159 * radius * radius;
    }
};

// -------- MAIN --------
int main() {

    // -------- STATIC ARRAY --------
    Shape* shapes[2];
    shapes[0] = new Rectangle(5, 4);
    shapes[1] = new Circle(3);

    cout << "Static Storage:\n";
    for (int i = 0; i < 2; i++) {
        cout << "Area = " << shapes[i]->Area() << endl;
    }

    // -------- DYNAMIC STORAGE --------
    vector<Shape*> dynShapes;
    dynShapes.push_back(new Rectangle(6, 2));
    dynShapes.push_back(new Circle(4));

    cout << "\nDynamic Storage:\n";
    for (auto s : dynShapes) {
        cout << "Area = " << s->Area() << endl;
    }

    // Cleanup
    for (int i = 0; i < 2; i++) delete shapes[i];
    for (auto s : dynShapes) delete s;

    return 0;
}
