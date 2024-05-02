#include <iostream>
#include "ShoppingCart.h"
#include <limits>

using namespace std;

void PrintMenu() {
    cout << "MENU\n"
         << "a - Add item to cart\n"
         << "d - Remove item from cart\n"
         << "c - Change item quantity\n"
         << "i - Output items' descriptions\n"
         << "o - Output shopping cart\n"
         << "q - Quit\n\n";
}

void ExecuteMenu(char choice, ShoppingCart& cart) {
    string name, description;
    int price, quantity;

    switch (choice) {
        case 'a':
            cout << "ADD ITEM TO CART\n";
            cout << "Enter the item name:" << endl;
            getline(cin >> ws, name);
            cout << "Enter the item description:" << endl;
            getline(cin, description);
            cout << "Enter the item price:" << endl;
            while (!(cin >> price) || price < 0) {
                cout << "Invalid input. Please enter a non-negative integer for price: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter the item quantity:" << endl;
            while (!(cin >> quantity) || quantity < 0) {
                cout << "Invalid input. Please enter a non-negative integer for quantity: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cart.AddItem(ItemToPurchase(name, description, price, quantity));
            cout << endl;
            break;

        case 'd':
            cout << "REMOVE ITEM FROM CART\n";
            cout << "Enter name of item to remove:\n";
            getline(cin >> ws, name);
            if (cart.RemoveItem(name)) {
              
            } else {
                
            }
            break;

        case 'c':
            cout << "CHANGE ITEM QUANTITY\n";
            cout << "Enter the item name:\n";
            getline(cin >> ws, name);
            cout << "Enter the new quantity:\n";
            while (!(cin >> quantity) || quantity < 0) {
                cout << "Invalid input. Please enter a non-negative integer for quantity: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (cart.ModifyItem(ItemToPurchase(name, "", 0, quantity))) {
                cout << "Item quantity updated successfully.\n";
            } else {
                
            }
            break;

        case 'i':
            cout << "OUTPUT ITEMS' DESCRIPTIONS\n";
            cart.PrintDescriptions();
            break;

        case 'o':
            cout << "OUTPUT SHOPPING CART\n";
            cart.PrintTotal();
            break;

        case 'q':
            cout << "Exiting the program...\n";
            return;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
    }
}
int main() {
    string customerName, currentDate;
    cout << "Enter customer's name:\n";
    getline(cin, customerName);
    cout << "Enter today's date:\n";
    getline(cin, currentDate);

    cout << "\nCustomer name: " << customerName << endl;
    cout << "Today's date: " << currentDate << endl << endl; 

    ShoppingCart cart(customerName, currentDate);

    char choice;
    do {
        PrintMenu();
        cout << "Choose an option:\n";
        cin >> choice;
        if (choice == 'q') {
     
            break;
        }
        if (choice != 'a' && choice != 'd' && choice != 'c' && choice != 'i' && choice != 'o') {
         
            continue; 
        }
        ExecuteMenu(choice, cart);
        cout << endl; 
    } while (true);

    return 0;
}
