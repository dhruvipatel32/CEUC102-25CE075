#include<iostream>
using namespace std;


class Student
{
     public:

    int roll_number;
    string name;
    int marks[3];
    int avrg=0;

    Student()
    {

        cout<<"calling default con."<<endl;
        roll_number=1;
        name="dhruvi";
        for(int i=0;i<3;i++)
        {
            marks[i]=200;
            avrg = avrg + marks[i];
        }
        avrg=avrg/3;
    }
    void output()
    {
        cout<<"The Roll Number of the student is :  "<<roll_number<<endl;
        cout<<"The Name Of the Student is: "<<name<<endl;
        cout<<"Marks of three subject: "<<endl;
        for(int i=0;i<3;i++)
        {
           cout<<"marks of "<<i+1<<"subject is "<<marks[i]<<endl;

        }
        cout<<"average marks of student : "<<avrg;

    }
} ;
int main()
{
    Student a[3];
    cout<<"Details of the marks "<<endl<<endl;
    for(int i=0 ;i<3 ;i++)
    {
        a[i].output();

    }

}
/*#include<iostream>
using namespace std;


class Student
{
     public:

    int roll_number;
    string name;
    int marks[3];
    int avrg=0;

    Student()
    {

        cout<<"calling default con."<<endl;
        roll_number=1;
        name="dhruvi";
        marks[0]=20;
        marks[1]=30;
        marks[2]=40;
        for(int i=0;i<3;i++)
        {

            avrg = avrg + marks[i];
        }
        avrg=avrg/3;
    }
    void output()
    {
        cout<<"The Roll Number of the student is :  "<<roll_number<<endl;
        cout<<"The Name Of the Student is: "<<name<<endl;
        cout<<"Marks of three subject: "<<endl;
        for(int i=0;i<3;i++)
        {
           cout<<"marks of "<<i+1<<"subject is "<<marks[i]<<endl;

        }
        cout<<"average marks of student : "<<avrg<<endl<<endl;

    }
} ;
int main()
{
    Student a[3];
    cout<<"Details of the marks "<<endl<<endl;
    for(int i=0 ;i<3 ;i++)
    {
        a[i].output();

    }

}
*/
