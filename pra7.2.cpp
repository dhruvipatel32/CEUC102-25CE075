#include<iostream>
using namespace std;
class comp
{
    float R, I;
public :
    comp():R(0),I(0){}
    comp(float r, float i):R(r),I(i){}
    comp operator+(comp o)
    {
        comp t;
        t.R = R + o.R;
        t.I = I + o.I;
        return t;
    }
    friend comp operator-(comp o1, comp o2)
    {
        comp t;
        t.R = o1.R - o2.R;
        t.I = o1.I - o2.I;
        return t;
    }
    void disp()
    {
        cout << "\nComplex no : " << R << " + " << I << "i";
    }
};

int main()
{
    comp c1(2.2 , 4), c2(4.5 , 3), c3, c4;
    c1.disp();
    c2.disp();
    c3 = c1 + c2; // c3 = c1.operator +(c2);
    c4 = operator-(c1, c2);
    cout << "\nAfter overload operators + and -...\n";
    c3.disp();
    c4.disp();
}
