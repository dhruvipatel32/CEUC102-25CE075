#include <iostream>
#include <queue>
using namespace std;

class Fahrenheit; // Forward declaration

class Celsius {
    float temp;

public:
    Celsius(float t = 0) {
        temp = t;
    }

    float getTemp() const {
        return temp;
    }

    operator Fahrenheit();

    bool operator==(Celsius c) {
        return temp == c.temp;
    }

    bool operator>(Celsius c) {
        return temp > c.temp;
    }

    bool operator<(Celsius c) {
        return temp < c.temp;
    }
};

class Fahrenheit {
    float temp;

public:
    Fahrenheit(float t = 0) {
        temp = t;
    }

    float getTemp() const {
        return temp;
    }

    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }

    bool operator==(Fahrenheit f) {
        return temp == f.temp;
    }

    bool operator>(Fahrenheit f) {
        return temp > f.temp;
    }

    bool operator<(Fahrenheit f) {
        return temp < f.temp;
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9 / 5) + 32);
}

int main() {

    Celsius cArr[3] = {25, 30, 35};
    Fahrenheit fArr[3];

    cout << "Celsius to Fahrenheit (Array):\n";
    for (int i = 0; i < 3; i++) {
        fArr[i] = cArr[i]; // implicit conversion
        cout << cArr[i].getTemp() << " C = "
             << fArr[i].getTemp() << " F\n";
    }

    queue<Celsius> cQueue;
    cQueue.push(10);
    cQueue.push(20);
    cQueue.push(40);

    cout << "\nQueue Conversion (FIFO Order):\n";
    while (!cQueue.empty()) {
        Celsius c = cQueue.front();
        cQueue.pop();

        Fahrenheit f = c; // conversion
        cout << c.getTemp() << " C = "
             << f.getTemp() << " F\n";
    }

    Celsius c1(30), c2(30), c3(40);

    cout << "\nComparison Results:\n";

    if (c1 == c2)
        cout << "c1 == c2\n";

    if (c3 > c1)
        cout << "c3 > c1\n";

    if (c1 < c3)
        cout << "c1 < c3\n";

    return 0;
}
