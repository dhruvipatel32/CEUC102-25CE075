#include <iostream>
using namespace std;

class Wallet
{
private:
    int walletID;
    string userName;
    double balance;


public:
    Wallet(int id,string name,double bal)
    {
        walletID=id;
        userName=name;
        balance=bal;
    }

    void loadMoney(double amount)
    {
        if (amount>0)
        {
            balance+=amount;
            cout<<"Money loaded successfully."<<endl;
        } else
        {
            cout<<"Invalid amount."<<endl;
        }
    }

    void transferMoney(Wallet &receiver, double amount)
     {
        if (amount<=balance)
        {
            balance-=amount;
            receiver.balance+=amount;
            cout<<"Transfer successful."<<endl;
        } else
        {
            cout<<"Error: Insufficient balance."<<endl;
        }
    }

    void displayDetails()
    {
        cout<<"Wallet ID: " << walletID<<endl;
        cout<<"User Name: " << userName<<endl;
        cout<<"Current Balance: " << balance << endl;
    }
};

int main()
{
    int id1, id2;
    string name1, name2;
    double bal1, bal2;
    double amount;
    int choice;
    cout<<"Enter Wallet ID for User 1: ";
    cin>>id1;
    cout<<"Enter User Name for User 1: ";
    cin>>name1;
    cout<<"Enter Initial Balance for User 1: ";
    cin>>bal1;
    cout<<"Enter Wallet ID for User 2: ";
    cin>>id2;
    cout<<"Enter User Name for User 2: ";
    cin>>name2;
    cout<<"Enter Initial Balance for User 2: ";
    cin>>bal2;

    Wallet w1(id1,name1,bal1);
    Wallet w2(id2,name2,bal2);
        cout<<"--- Digital Wallet Menu ---"<<endl;
        cout<<"1.Load Money to User 1"<<endl;
        cout<<"2.Transfer Money (User 1to User 2)"<<endl;
        cout<<"3.Display Wallet Details"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;

        switch(choice)
        {

    do {
            case 1:
                cout<<"Enter amount to load: ";
                cin>>amount;
                w1.loadMoney(amount);
                break;

            case 2:
                cout<<"Enter amount to transfer: ";
                cin>>amount;
                w1.transferMoney(w2,amount);
                break;

            case 3:
                cout<<"User 1 Details:";
                w1.displayDetails();
                cout<<"User 2 Details:";
                w2.displayDetails();
                break;

            case 4:
                cout<<"Thank you! Exiting..."<<endl;
                break;

            default:
                cout<<"Invalid choice."<<endl;


    }while(choice!=4);
        }

    return 0;
}
