#ifndef ORDERFACTORY_H
#define ORDERFACTORY_H

#include "../models/Order.h"
#include "../models/Cart.h"
#include "../models/Restaurant.h"
#include "../strategies/PaymentStrategy.h"
#include <vector>
#include <string>

using namespace std;

class OrderFactory {
public:
    virtual ~OrderFactory() {
        // Virtual destructor for proper cleanup
    }

    virtual Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem>& menuItems,
        PaymentStrategy* paymentStrategy, const string& orderType) = 0;
};

#endif
