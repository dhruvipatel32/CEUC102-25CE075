#include<iostream>
using namespace std;

class employee
{
private:
    string name;
    float b_salary;
    float bonus;
public:
    employee(string n, float salary, float b = 2000)
    {
        name = n;
        b_salary = salary;
        bonus = b;
    }
    inline float calucatesalary()
    {
        return b_salary + bonus ;
    }
    void display()
    {
        cout<<"name : "<<name<<endl;
        cout<<"basic salary : "<<b_salary<<endl;
        cout<<"bonus : "<<bonus<<endl;
        cout<<"total salary : "<<calucatesalary()<<endl;

    }
};
int main()
{
    int n;


    cout<<"Enter the number of employee : ";
    cin>>n;

    employee* e[200];


    for(int i = 0 ; i < n ; i++ )
    {
        string name;
        float b_salary,bonus;
        int choice;

        cout<<"enter the name: ";
        cin.ignore();
        getline(cin, name);
        cout<<"enter the salary: ";
        cin>>b_salary;
        cout<<" 1.default bonus \n 2.customized bonus"<<endl;
        cout<<"Enter the choice : ";
        cin>>choice;

        if(choice == 1)
        {
            e[i] = new employee(name , b_salary);
        }
        else
        {
            cout<<"Enter the bonus: ";
            cin>>bonus;
            e[i] = new employee(name , b_salary , bonus);
        }
    }
    for(int i ; i < n ; i++)
    {
        e[i]->display();
    }

}
