#include<iostream>
using namespace std;
float PI = 3.14;

class shape
{
protected:
    float r;

};

class circle : public shape
{
public :
    circle()
    {
        r=0;
    }

    circle(float x)
    {
        r=x;
    }
    float area(float r)
    {
        return PI * (r * r);
    }
    void disp()
    {

        cout << "\ndisplay the Area of circle : " <<area(r);
    }

};
int main()
{
    int n;

    cout << "How many circles do you want to add : ";
    cin >> n;
    circle *ptr = new circle[n];//Dynamic
    float r;
    //circle c[n];//static

    cout << "\nAdding radius/s...";

    for (int i=0; i<n; i++)
    {
        cout<<endl;
        cout << "\nEnter no." << i+1 << "'s radius :";
        cin >> r;
        ptr[i] = circle(r);
        cout<< "Area [" << i+1 << "] : " << ptr[i].area(r)<<endl;

    }
    for (int i=0; i<n; i++)
    {
        ptr[i].disp();
    }

    return 0;
}
