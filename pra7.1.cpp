#include<iostream>
using namespace std;

class cal
{
    int counter = 0;
    float arr[10];

public:
    int add(int a, int b)
    {
        float res = a + b;

        arr[counter++] = res;
        return res;
    }

    float add(float a, float b)
    {
        float res = a + b;
        arr[counter++] = res;
        return res;
    }

    float add(int a, float b)
    {
        float res = a + b;
        arr[counter++] = res;
        return res;
    }

    float add(float a, int b)
    {
        float res = a + b;
        arr[counter++] = res;
        return res;
    }

    void disp()
    {
        for(int i = 0; i < counter; i++)
        {
            cout << "\n\nResult is : " << i + 1 << " = " << arr[i];
        }
        cout << endl;
    }
};

int main()
{
    int a, b;
    float c, d;
    cal c1;

    int choice;

    do
    {
        cout << "\n\nTasks:";
        cout << "\n1. Add 2 Integers";
        cout << "\n2. Add 2 Floats";
        cout << "\n3. Add Int and Float";
        cout << "\n4. Add Float and Int";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nEnter 2 integers: ";
                cin >> a >> b;
                cout << "Result = " << c1.add(a, b);
                break;

            case 2:
                cout << "\nEnter 2 floats: ";
                cin >> c >> d;
                cout << "Result = " << c1.add(c, d);
                break;

            case 3:
                cout << "\nEnter int: ";
                cin >> a;
                cout << "Enter float: ";
                cin >> d;
                cout << "Result = " << c1.add(a, d);
                break;

            case 4:
                cout << "\nEnter float: ";
                cin >> d;
                cout << "Enter int: ";
                cin >> a;
                cout << "Result = " << c1.add(d, a);
                break;

            case 5:
                cout << "\nExiting...";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while(choice != 5);



    return 0;
}
