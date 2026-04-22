#include <iostream>
#include <cmath>
using namespace std;

// -------- CUSTOM EXCEPTION --------
class NegativeNumberException {
    double value;
public:
    NegativeNumberException(double v) : value(v) {}

    void message() {
        cout << "Error: Negative number (" << value
             << ") cannot have real square root!\n";
    }
};

int main() {
    double num;

    cout << "Enter number: ";
    cin >> num;

    try {
        if (num < 0) {
            throw NegativeNumberException(num);
        }

        cout << "Square Root = " << sqrt(num) << endl;
    }
    catch (NegativeNumberException e) {
        e.message();
    }

    return 0;
}
