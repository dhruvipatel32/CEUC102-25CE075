#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<string, vector<string>> directory;
    int choice;
    string folder, file;

    do {
        cout << "\n1. Add Folder\n";
        cout << "2. Add File to Folder\n";
        cout << "3. Display Directory\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter folder name: ";
            cin >> folder;

            if (directory.find(folder) == directory.end()) {
                directory[folder] = {};
                cout << "Folder added.\n";
            } else {
                cout << "Folder already exists!\n";
            }
            break;

        case 2:
            cout << "Enter folder name: ";
            cin >> folder;

            if (directory.find(folder) != directory.end()) {
                cout << "Enter file name: ";
                cin >> file;

                directory[folder].push_back(file);
                cout << "File added.\n";
            } else {
                cout << "Folder does not exist!\n";
            }
            break;

        case 3:
            cout << "\nDirectory Structure:\n";
            for (auto it = directory.begin(); it != directory.end(); it++) {
                cout << it->first << ":\n";
                for (string f : it->second) {
                    cout << "  - " << f << endl;
                }
            }
            break;
        }

    } while (choice != 4);

    return 0;
}
