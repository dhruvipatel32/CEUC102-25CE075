#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
    int itemID;
    string itemName;
    float price;
    int quantity;

public:
    Item()
    {
        itemID = 0;
        itemName = "Unknown";
        price = 0;
        quantity = 0;
    }

    Item(int id, string name, float p, int q)
    {
        itemID = id;
        itemName = name;
        price = p;
        quantity = q;
    }

    void addStock(int qty)
    {
        quantity = quantity + qty;
        cout << "Stock added successfully.\n";
    }

    void sellItem(int qty)
    {
        if (qty <= quantity)
        {
            quantity = quantity - qty;
            cout << "Item sold successfully.\n";
        } else {
            cout << "Insufficient stock!\n";
        }
    }

    void displayItem()
    {
        cout << "\nItem ID: " << itemID;
        cout << "\nItem Name: " << itemName;
        cout << "\nPrice: " << price;
        cout << "\nQuantity in Stock: " << quantity << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[100];
    for (int i = 0; i < n; i++)
    {
        int id, qty;
        float price;
        string name;

        cout << "\nEnter details for item " << i + 1 << endl;
        cout << "Item ID: ";
        cin >> id;
        cout << "Item Name: ";
        cin >> name;
        cout << "Price: ";
        cin >> price;
        cout << "Quantity: ";
        cin >> qty;

        items[i] = Item(id, name, price, qty);
    }

    int choice, index, qty;

    do {
        cout << "\n\n--- Inventory Menu ---";
        cout << "\n1. Add Stock";
        cout << "\n2. Sell Item";
        cout << "\n3. Display Item";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;


        switch (choice)
        {
            case 1:
                cout << "Enter quantity to add: ";
                cin >> qty;
                items[index].addStock(qty);
                break;

            case 2:
                cout << "Enter quantity to sell: ";
                cin >> qty;
                items[index].sellItem(qty);
                break;

            case 3:
                items[index].displayItem();
                break;

            case 4:
                cout << "Exiting program...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}
