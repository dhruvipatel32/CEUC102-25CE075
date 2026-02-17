#include<iostream>
using namespace std;

class Student
{
    int roll_no;
    string name;
    int marks[3];
    float avg=0;

public:

    Student():roll_no(1),name("dhruvi")
    {
        cout<<"Calling Deafult constructer.."<<endl;;
        /*roll_no=1;
        name="Dhruvi";*/
        marks[0]=20;
        marks[1]=30;
        marks[2]=40;
        for(int i=0;i<3;i++)
        {
            avg = avg + marks[i];
        }
        avg = avg/3;
    }
    Student(int r,string n,int m[3],float a)
    {
        cout<<"Calling Perameterrise constructer.."<<endl;;
        roll_no=r;
        name=n;
        avg=a;
        for(int i=0;i<3;i++)
        {
            marks[i]=m[i];
        }
    }

    void display();
};

void Student :: display()
{
    cout<<"----------------------"<<endl;
    cout<<"Roll number of student is "<<roll_no<<endl;
    cout<<"Name of the student is "<<name<<endl;
    cout<<"marks of 3 subject.."<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<"marks of "<<i+1<<" Subject is "<<marks[i]<<endl;
    }
    cout<<"Average marks is "<<avg<<endl;
}

int main()
{
    Student s[2];
    cout<<"printing details..."<<endl;
    for(int i=0;i<2;i++)
    {
        s[i].display();
    }

    int roll_no;
    string name;
    int marks[3];
    float avg=0;
     cout<<"----------------------"<<endl;
    cout<<"Enter the Roll number of student : ";
    cin>>roll_no;
    cout<<"Enter the Name of the student : ";
    cin>>name;
    cout<<"Enter the marks of 3 subject.."<<endl;;
    for(int i=0;i<3;i++)
    {
        cout<<"Enter the marks of "<<i+1<<" Subject : ";
        cin>>marks[i];
        avg = avg + marks[i];
    }
    avg = avg/3;
    cout<<endl;
    cout<<"printing details..."<<endl;
    Student s1(roll_no,name,marks,avg);
    s1.display();
    return 0;
}
