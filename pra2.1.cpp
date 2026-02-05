#include <iostream>
using namespace std;

class Rectangle
{
private:
    double length;
    double width;

public:
    Rectangle(double l = 0, double w = 0)
    {
        length = l;
        width = w;
    }

    void setDimensions(double l, double w)
    {
        length = l;
        width = w;
    }

    double area()
    {
        return length * width;
    }

    double perimeter()
    {
        return 2 * (length + width);
    }
    void display()
    {
        cout<<endl<<"Length: "<<length<<endl;
        cout<<"Width: "<<width<<endl;
        cout<<"Area: "<<area()<<endl;
        cout<<"Perimeter: "<<perimeter()<<endl;
    }
};

int main()
{
    int n;
    cout<<"Enter the number of rectangles: ";
    cin>>n;

    Rectangle rectangles[n];
    for (int i=0;i<n;i++)
    {
        double l, w;
        cout<<"Enter length and width for rectangle " <<i+1<<": ";
        cin>>l>>w;
        rectangles[i].setDimensions(l, w);
    }

    cout << "Rectangle  Details: "<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<"Rectangle "<<i+1<< ": ";
        rectangles[i].display();
    }

    return 0;
}
