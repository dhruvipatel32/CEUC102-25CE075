#include <iostream>
using namespace std;

// TEMPLATE: Display Array
template <typename T>
void display(T arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// TEMPLATE: Find Maximum
template <typename T>
T findMax(T arr[], int n)
{
    T maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

// TEMPLATE: Reverse Array
template <typename T>
void reverseArray(T arr[], int n)
{
    int start = 0, end = n - 1;
    while (start < end)
    {
        T temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// TEMPLATE: Print Leader Elements
template <typename T>
void printLeaders(T arr[], int n)
{
    T maxFromRight = arr[n - 1];
    cout << "Leaders: " << maxFromRight << " ";

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > maxFromRight)
        {
            cout << arr[i] << " ";
            maxFromRight = arr[i];
        }
    }
    cout << endl;
}

int main()
{
    int choice, n;

    do
    {
        cout <<endl << "----- Template Array Operations -----"<<endl;
        cout << "1. Integer Array"<<endl;
        cout << "2. Float Array"<<endl;
        cout << "3. Character Array"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) break;

        cout << "Enter number of elements: ";
        cin >> n;

        switch (choice)
        {

        case 1:
        {
            int arr[100];
            cout << "Enter " << n << " integer values:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            cout << "\nArray: ";
            display(arr, n);

            cout << "Max: " << findMax(arr, n) << endl;

            printLeaders(arr, n);

            reverseArray(arr, n);
            cout << "Reversed: ";
            display(arr, n);

            break;
        }

        case 2:
        {
            float arr[100];
            cout << "Enter " << n << " float values:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            cout << "\nArray: ";
            display(arr, n);

            cout << "Max: " << findMax(arr, n) << endl;

            printLeaders(arr, n);

            reverseArray(arr, n);
            cout << "Reversed: ";
            display(arr, n);

            break;
        }

        case 3:
        {
            char arr[100];
            cout << "Enter " << n << " characters:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            cout << "\nArray: ";
            display(arr, n);

            cout << "Max (ASCII): " << findMax(arr, n) << endl;

            printLeaders(arr, n);

            reverseArray(arr, n);
            cout << "Reversed: ";
            display(arr, n);

            break;
        }

        default:
            cout << "Invalid Choice!\n";
        }

    }
    while (choice != 4);

    return 0;
}
