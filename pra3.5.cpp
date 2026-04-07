#include <iostream>
#include <string>
using namespace std;

int superDigit(long long n)
{
    if (n < 10)
        return n;

    long long sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return superDigit(sum);
}

int main() {
    string n;
    long long k;

    cout << "Enter n (string representation): ";
    cin >> n;

    cout << "Enter k (number of repetitions): ";
    cin >> k;

    long long initialSum = 0;


    for (char c : n)
    {
        initialSum += (c - '0');
    }

    long long finalValue = initialSum * k;


    int result = superDigit(finalValue);

    cout << "Super Digit = " << result << endl;

    return 0;
}
