#include <iostream>
using namespace std;

string logs[50];
int logIndex = 0;

void logMsg(string msg) {
    logs[logIndex++] = msg;
}

// -------- CUSTOM EXCEPTION --------
class InsufficientFundsException {
public:
    void message() {
        cout << "Error: Insufficient balance!\n";
    }
};

// -------- BANK CLASS --------
class BankAccount {
    double balance;

public:
    BankAccount(double b) : balance(b) {}

    void deposit(double amt) {
        logMsg("Entered deposit()");
        balance += amt;
        logMsg("Exit deposit()");
    }

    void withdraw(double amt) {
        logMsg("Entered withdraw()");
        if (amt > balance) {
            throw InsufficientFundsException();
        }
        balance -= amt;
        logMsg("Exit withdraw()");
    }

    double getBalance() {
        return balance;
    }
};

// -------- FUNCTION CHAIN (for stack unwinding) --------
void processWithdraw(BankAccount &acc, double amt) {
    logMsg("Entered processWithdraw()");
    acc.withdraw(amt);
    logMsg("Exit processWithdraw()");
}

// -------- MAIN --------
int main() {
    BankAccount acc(1000);

    try {
        acc.deposit(500);
        processWithdraw(acc, 200);   // success
        processWithdraw(acc, 2000);  // failure
    }
    catch (InsufficientFundsException e) {
        e.message();
        logMsg("Exception caught in main()");
    }

    cout << "\nFinal Balance: " << acc.getBalance() << endl;

    cout << "\n--- Transaction Logs ---\n";
    for (int i = 0; i < logIndex; i++) {
        cout << logs[i] << endl;
    }

    return 0;
}
