#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream file;
    string filename;

    // -------- FILE OPEN WITH RETRY --------
    while (true) {
        cout << "Enter file name: ";
        cin >> filename;

        file.open(filename);

        if (file.is_open()) {
            break;
        }
        else {
            cout << "Error: File not found! Try again.\n";
        }
    }

    string line;
    int lineNo = 0;
    double sum = 0;
    int count = 0;

    cout << "\nProcessing file...\n";

    // -------- READ LINE BY LINE --------
    while (getline(file, line)) {
        lineNo++;
        stringstream ss(line);
        double num;

        if (!(ss >> num)) {
            cout << "Invalid data at line " << lineNo
                 << ": " << line << endl;
            continue;
        }

        sum += num;
        count++;
    }

    file.close();

    // -------- RESULT --------
    if (count > 0) {
        cout << "\nSum = " << sum << endl;
        cout << "Average = " << sum / count << endl;
    } else {
        cout << "No valid data found.\n";
    }

    return 0;
}
