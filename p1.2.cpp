#include <iostream>
using namespace std;

class Book {
private:
    int id;
    char title[50];
    char author[50];
    int copies;

public:
    void addBook()
    {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title: ";
        cin.getline(title, 50);

        cout << "Enter Author: ";
        cin.getline(author, 50);

        cout << "Enter Number of Copies: ";
        cin >> copies;
    }

    int getId()
     {
        return id;
    }

    void issueBook()
    {
        if (copies > 0)
        {
            copies--;
            cout << "Book issued successfully!\n";
        } else {
            cout << "No copies available!\n";
        }
    }

    void returnBook()
    {
        copies++;
        cout << "Book returned successfully!\n";
    }

    void displayBook() {
        cout << id << "\t" << title << "\t" << author << "\t" << copies << endl;
    }
};

int main() {
    Book library[50];
    int count = 0;
    int choice, id;

    do {
        cout << "\n--- Library Management System (C++) ---\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library[count].addBook();
                count++;
                cout << "Book added successfully!\n";
                break;

            case 2:
                cout << "Enter Book ID to issue: ";
                cin >> id;
                for (int i = 0; i < count; i++) {
                    if (library[i].getId() == id) {
                        library[i].issueBook();
                        break;
                    }
                }
                break;

            case 3:
                cout << "Enter Book ID to return: ";
                cin >> id;
                for (int i = 0; i < count; i++) {
                    if (library[i].getId() == id) {
                        library[i].returnBook();
                        break;
                    }
                }
                break;

            case 4:
                cout << "\nID\tTitle\tAuthor\tCopies\n";
                for (int i = 0; i < count; i++) {
                    library[i].displayBook();
                }
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
