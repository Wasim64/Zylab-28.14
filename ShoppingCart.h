#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <vector>
#include <string>
#include "ItemToPurchase.h"

class ShoppingCart {
public:
    ShoppingCart();
    ShoppingCart(std::string name, std::string date);

    std::string GetCustomerName() const;
    std::string GetDate() const;

    void AddItem(const ItemToPurchase& item);
    bool RemoveItem(const std::string& name);
    bool ModifyItem(const ItemToPurchase& item);

    int GetNumItemsInCart() const;
    double GetCostOfCart() const;

    void PrintTotal() const;
    void PrintDescriptions() const;

private:
    std::string customerName;
    std::string currentDate;
    std::vector<ItemToPurchase> cartItems;
};

#endif
