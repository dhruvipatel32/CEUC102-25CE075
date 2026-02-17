#include <iostream>
using namespace std;

class DigitalSavingsAccount
{
private:
    string customerName;
    string accountID;
    double balance;

public:
    DigitalSavingsAccount()
    {
        customerName = "";
        accountID = "";
        balance = 0;
    }

    void createAccount(string name, string id, double initialBalance)
    {
        customerName = name;
        accountID = id;

        if (initialBalance >= 0)
            balance = initialBalance;
        else {
            balance = 0;
            cout << "Invalid initial balance. "<<endl;
        }
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit Successful"<<endl;
        } else
        {
            cout << "Invalid deposit amount!"<<endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid withdrawal amount!"<<endl;
        }
        else if (amount > balance)
        {
            cout << "Withdrawal Failed! Insufficient Balance."<<endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal Successful!"<<endl;
        }
    }


    void displaySummary()
    {
        cout << "\n----- Account Summary -----\n";
        cout << "Customer Name : " << customerName << endl;
        cout << "Account ID : " << accountID << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {

    int n;
    cout << "Enter number of accounts: ";
    cin >> n;

    DigitalSavingsAccount accounts[100];

    for (int i = 0; i < n; i++)
        {
        string name, id;
        double initialBalance;

        cout << "Enter details for Account " << i + 1 << endl;

        cout << "Customer Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Account ID: ";
        getline(cin, id);

        cout << "Initial Balance: ";
        cin >> initialBalance;

        accounts[i].createAccount(name, id, initialBalance);

        int choice;
        do {
            cout << "\n1. Deposit\n2. Withdraw\n3. Display Summary\n4. Next Account\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 1)
            {
                double amount;
                cout << "Enter deposit amount: ";
                cin >> amount;
                accounts[i].deposit(amount);
            }
            else if (choice == 2)
            {
                double amount;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                accounts[i].withdraw(amount);
            }
            else if (choice == 3)
            {
                accounts[i].displaySummary();
            }

        } while (choice != 4);
    }

    cout << "All Account Summaries:  "<<endl;
    for (int i = 0; i < n; i++)
    {
        accounts[i].displaySummary();
    }

    return 0;
}
