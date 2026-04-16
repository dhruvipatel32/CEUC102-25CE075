#include<iostream>
#include<string>
using namespace std;

class vehicle
{
protected :
    string colour;
    string typeof_car;
public :
    vehicle():colour("White"), typeof_car("City car"){}
    vehicle(string c, string car_type)
    {
        colour = c;
        typeof_car = car_type;
    }

};
class fuel : public virtual vehicle
{
protected :
    string typeof_fuel;
public :
    fuel(){}
    fuel(string c, string car_type, string t):vehicle(c, car_type)
    {
        typeof_fuel = t;
    }

};

class brand : public vehicle
{
protected :
    string brand_name;
public :
    brand(){}
    brand(string c, string car_type, string b) : vehicle(c, car_type)
    {
        brand_name = b;
    }

};

class car : public fuel , public brand
{
public :
    car(){}
    car(string c, string car_type, string t, string b) : vehicle( c, car_type), fuel(c, car_type, t), brand (c, car_type, b) {}
    void disp()
    {
        cout << "Color of car : " << colour<<endl;
        cout << "\nType of car : " << typeof_car<<endl;
        cout << "\nType of fuel : " << typeof_fuel<<endl;
        cout << "\nBrand name of car : " << brand_name<<endl;
    }
};

int main()
{
    int n;
    cout << "Enter no of car : ";
    cin >> n;
    car cars[n];
    string c, car_type, t, b;
    for(int i=0; i<n; i++)
    {
        cout << "\nEnter [" << i+1 << "]'s details ....";
        cout << "\nEnter color of car :";
        cin >> c;
        cout << "Enter type of car : ";
        cin >> car_type;
        cout << "Enter type of fuel : ";
        cin >> t;
        cout << "Enter brand name of car : ";
        cin >> b;
        cars[i] = car(c, car_type, t, b);

    }
    for(int i=0; i<n; i++)
    {
    cars[i].disp();
    }
    return 0;
}
























