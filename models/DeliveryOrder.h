#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H

#include "Order.h"
using namespace std;

class DeliveryOrder : public Order {
private:
    string userAddress;

public:
    // Constructor
    DeliveryOrder() 
    {
        userAddress = "";
    }

    // Override getType()
    string getType() const override 
    {
        return "Delivery";
    }

    // --- Getters ---
    string getUserAddress() const 
    {
        return userAddress;
    }

    // --- Setters ---
    void setUserAddress(const string& address) 
    {
        userAddress = address;
    }
};

#endif
