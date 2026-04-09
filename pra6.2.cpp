#include<iostream>
using namespace std;
class person
{
protected :
    string name;
    int age;
/*public :
    person(string a, int b)
    {
        name=a;
        age=b;
    }
    void disp1()
    {
        cout << "\nName : " << name;
        cout << "\nAge : " << age;
    }*/
};

class employee : public person
{
protected :
    int emp_id;
/*public :
    employee(string a, int b, int c) : person(a,b)
    {
        emp_id=c;
    }
    void disp2()
    {
        cout << "\nEmployee ID : " << emp_id;
    }*/
};

class manager : public employee
{
    string dept;
public :
    manager()
    {
        dept="CE";
    }
    manager(string a, int b, int c, string d) //: employee(a,b,c)
    {
        name=a;
        age=b;
        emp_id=c;
        dept=d;
    }
    void disp3()
    {
        cout << "\nName : " << name;
        cout << "\nAge : " << age;
        cout << "\nEmployee ID : " << emp_id;
        cout << "\nDepartment : " << dept;
    }
};
int main()
{
    int n;
    string a;
    int b;
    int c;
    string d;
    cout << "Enter no of employee/s : ";
    cin >> n;
    manager *ptr = new manager[n];

    cout << "\nEntering emp details....";
    for(int i=0; i<n; i++)
    {
        cout << "\nEmployee [" << i+1 << "] : ";
        cout << "\nName : ";
        cin >> a;
        cout << "Age : ";
        cin >> b;
        cout << "Employee ID : ";
        cin >> c;
        cout << "Department Name : ";
        cin >> d;
        ptr[i] = manager(a,b,c,d);
    }
    return 0;
}


















