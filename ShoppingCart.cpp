#include "ShoppingCart.h"
#include <iostream>
#include <algorithm>

ShoppingCart::ShoppingCart() : customerName("none"), currentDate("January 1, 2016") {}

ShoppingCart::ShoppingCart(std::string name, std::string date) : customerName(name), currentDate(date) {}

std::string ShoppingCart::GetCustomerName() const {
    return customerName;
}

std::string ShoppingCart::GetDate() const {
    return currentDate;
}

void ShoppingCart::AddItem(const ItemToPurchase& item) {
    cartItems.push_back(item);
}

bool ShoppingCart::RemoveItem(const std::string& name) {
    auto it = find_if(cartItems.begin(), cartItems.end(), [&name](const ItemToPurchase& item) {
        return item.GetName() == name;
    });
    if (it != cartItems.end()) {
        cartItems.erase(it);
        return true; 
    } else {
        std::cout << "Item not found in cart. Nothing removed.\n" ;
        return false; 
    }
}

bool ShoppingCart::ModifyItem(const ItemToPurchase& item) {
    auto it = find_if(cartItems.begin(), cartItems.end(), [&item](const ItemToPurchase& currItem) {
        return currItem.GetName() == item.GetName();
    });

    if (it != cartItems.end()) {
        if (!item.GetDescription().empty() && item.GetDescription() != "none") {
            it->SetDescription(item.GetDescription());
        }
        if (item.GetPrice() != 0) {
            it->SetPrice(item.GetPrice());
        }
        if (item.GetQuantity() != 0) {
            it->SetQuantity(item.GetQuantity());
        }
        return true;
    } else {
        std::cout << "Item not found in cart. Nothing modified." << std::endl;
        return false; 
    }
}

int ShoppingCart::GetNumItemsInCart() const {
    int totalQuantity = 0;
    for (const auto& item : cartItems) {
        totalQuantity += item.GetQuantity();
    }
    return totalQuantity;
}

double ShoppingCart::GetCostOfCart() const {
    double totalCost = 0;
    for (const auto& item : cartItems) {
        totalCost += item.GetPrice() * item.GetQuantity();
    }
    return totalCost;
}

void ShoppingCart::PrintTotal() const {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    int numItems = GetNumItemsInCart();
    cout << "Number of Items: " << numItems << endl << endl;

    if (numItems == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl << endl; 
    } else {
        for (const auto& item : cartItems) {
            item.PrintItemCost();
        }
    }
   
    cout << "Total: $" << GetCostOfCart() << endl;
}

void ShoppingCart::PrintDescriptions() const {
    std::cout << customerName << "'s Shopping Cart - " << currentDate << std::endl << "Item Descriptions" << std::endl;
    for (const auto& item : cartItems) {
        item.PrintItemDescription();
    }
}
