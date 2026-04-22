#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

ostream& rupee(ostream& output) {
    output << "₹ ";
    return output;
}

struct Student {
    string name;
    int marks;
    double fees;
};

int main() {
    vector<Student> students = {
        {"Amit", 85, 15000.5},
        {"Neha", 92, 16250.75},
        {"Raj", 78, 14000.0},
        {"Priya", 88, 15500.25},
        {"Kiran", 95, 17000.9}
    };

    // -------- TABLE HEADER --------
    cout << setfill('=') << setw(65) << "=" << endl;
    cout << setfill(' ');

    cout << left << setw(15) << "Name"
         << right << setw(10) << "Marks"
         << setw(15) << "Percentage"
         << setw(20) << "Fees" << endl;

    cout << setfill('-') << setw(65) << "-" << endl;
    cout << setfill(' ');

    for (auto s : students) {
        double percentage = s.marks; // assuming marks out of 100

        cout << left << setw(15) << s.name
             << right << setw(10) << s.marks
             << setw(15) << fixed << setprecision(2) << percentage << "%"
             << setw(10) << rupee << fixed << setprecision(2) << s.fees
             << endl;
    }

    cout << setfill('=') << setw(65) << "=" << endl;

    cout << "\n\nFEE RECEIPT\n";
    cout << setfill('*') << setw(40) << "*" << endl;
    cout << setfill(' ');

    cout << left << setw(20) << "Student:"
         << "Amit" << endl;

    cout << left << setw(20) << "Marks:"
         << "85" << endl;

    cout << left << setw(20) << "Fees Paid:"
         << rupee << fixed << setprecision(2) << 15000.5 << endl;

    cout << setfill('*') << setw(40) << "*" << endl;

    return 0;
}
