//ponter thi banela object ne call karava mate -> no use karvo
#include<iostream>
using namespace std;

class Account{
    private:
        int accountNumber;
        string holderName;
        double balance;

    public:
        static int totalAccounts;

        //constructor
        Account(int accNo, string name, double bal){
            accountNumber = accNo;
            holderName = name;
            balance = bal;
            totalAccounts++;
        }

        int getAccountNumber()
        {
            return accountNumber;
        }

        void updateName(string name)
        {
            holderName = name;
        }

        double getBalance()
        {
            return balance;
        }

        void deposite(double amount)
        {
            balance += amount;
        }

        bool withdraw(double amount)
        {
            if(amount > balance)
            {
                cout<<"Insufficient Balance!"<<endl;
                return false;
            }
            balance -= amount;
            return true;
        }

        void display(){
            cout<<"==========================================="<<endl;
            cout<<"Account Number : "<<accountNumber<<endl;
            cout<<"Acoount Holder : "<<holderName<<endl;
            cout<<"Current Balance : "<<balance<<endl;
        }
};

int Account::totalAccounts = 0;

Account* findAccount(Account* accounts[],int count, int accNo){ // dynamic
    for(int i = 0 ; i < count ; i++){
        if(accounts[i]->getAccountNumber() == accNo)
            return accounts[i];
    }
    return NULL;
}

//transfer function

void transferMoney(Account* accounts[], int count){
    int fromAcc,toAcc;
    double amount;

    cout<<"Enter sender account number ";
    cin>>fromAcc;
    cout<<"Enter reciever account number ";
    cin>>toAcc;
    cout<<"Enter Amount ";
    cin>>amount;

    Account* sender = findAccount(accounts,count,fromAcc);
    Account* reciever = findAccount(accounts,count,toAcc);

    if(sender == NULL || reciever == NULL){
        cout<<"Invalid Account Number!"<<endl;
        return;
    }

    if(sender->withdraw(amount)){
        reciever->deposite(amount);
        cout<<"Transfer Successfully!";
    }
}

int main(){

    const int MAX = 100;
    Account* accounts[MAX]; // dynamic array of pointer

    int count = 0;
    int choice;

    do{
        cout<<"\n==========Bank Management System======="<<endl;
        cout<<"1. Add Account "<<endl;
        cout<<"2. Update Account "<<endl;
        cout<<"3. Transfer Money "<<endl;
        cout<<"4. Display Account "<<endl;
        cout<<"5. Display Total Account "<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter Choice : ";
        cin>>choice;


        if(choice == 1){

            int accNo;
            string name;
            double bal;

            cout<<"Enetr account number: ";
            cin>>accNo;
            cin.ignore();

            cout<<"Enter Holder Name: ";
            getline(cin,name);

            cout<<"Enter Initial Balance: ";
            cin>>bal;

            accounts[count] = new Account(accNo,name,bal);
            count++;
        }

        else if(choice == 2){
            int accNo;
            cout<<"Enter Account Number ";
            cin>>accNo;

            Account* acc = findAccount(accounts,count,accNo);

            if (acc!=NULL){
                string name;
                cin.ignore();
                getline(cin,name);
                acc->updateName(name);
            }
        }

        else if(choice == 3){
            transferMoney(accounts,count);
        }

        else if(choice == 4){
            int accNo;

            cout<<"Enter account number: ";
            cin>>accNo;

            Account* acc = findAccount(accounts,count,accNo);
            if(acc!=NULL){
                acc->display();
            }
        }

        else if(choice == 5){
            cout<<count<<endl;
        }

    }while(choice != 0);
         for(int i=0;i<count;i++){
            delete accounts[i];
    }

}
