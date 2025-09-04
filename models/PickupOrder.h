#ifndef PICKUPORDER_H
#define PICKUPORDER_H

#include "Order.h"
using namespace std;

class PickupOrder : public Order {
private:
    string restaurantAddress;

public:
    // Constructor
    PickupOrder() {
        restaurantAddress = "";
    }

    // Override getType()
    string getType() const override {
        return "Pickup";
    }

    // --- Getters ---
    string getRestaurantAddress() const {
        return restaurantAddress;
    }

    // --- Setters ---
    void setRestaurantAddress(const string& address) {
        restaurantAddress = address;
    }
};

#endif
