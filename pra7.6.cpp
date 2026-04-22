#include <iostream>
using namespace std;

class Base {
public:
    ~Base() {
        cout << "Base Destructor\n";
    }
};

class Derived : public Base {
    int* data;
public:
    Derived() {
        data = new int[5];
        cout << "Derived Constructor\n";
    }

    ~Derived() {
        delete[] data;
        cout << "Derived Destructor\n";
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;  // ❌ Derived destructor NOT called
    return 0;
}
