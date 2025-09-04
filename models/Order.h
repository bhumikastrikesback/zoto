#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "MenuItem.h"
#include "Restaurant.h"
#include "../strategies/PaymentStrategy.h"
#include "../Utils/TimeUtils.h"

using namespace std;
class Order {
protected:
    inline static int nextOrderId = 0;
    int orderId;
    User* user;
    Restaurant* restaurant;
    vector<MenuItem> items;
    PaymentStrategy* paymentStrategy;  
    double total;
    string scheduled;

public:
    // Constructor
    Order() {
        user = nullptr;
        restaurant = nullptr;
        paymentStrategy = nullptr;
        total = 0.0;
        scheduled = "";
        orderId = ++nextOrderId;
    }

    // Destructor
    virtual ~Order() {
        delete paymentStrategy;
    }

    // Process Payment
    bool processPayment() {
        if (paymentStrategy) {
            paymentStrategy->pay(total);
            return true;
        } 
        else {
            cout << "Please choose a payment mode first" << endl;
            return false;
        }
    }

    virtual string getType() const = 0;

    // --- Getters ---
    int getOrderId() const 
    {
        return orderId;
    }

    User* getUser() const 
    {
        return user;
    }

    Restaurant* getRestaurant() const 
    {
        return restaurant;
    }

    const vector<MenuItem>& getItems() const 
    {
        return items;
    }

    PaymentStrategy* getPaymentStrategy() const 
    {
        return paymentStrategy;
    }

    double getTotal() const 
    {
        return total;
    }

    string getScheduledTime() const 
    {
        return scheduled;
    }

    // --- Setters ---
    void setUser(User* u) 
    {
        user = u;
    }

    void setRestaurant(Restaurant* r) 
    {
        restaurant = r;
    }

    void setItems(const vector<MenuItem>& newItems) 
    {
        items = newItems;
    }

    void setPaymentStrategy(PaymentStrategy* ps) 
    {
        if (paymentStrategy) 
            delete paymentStrategy;  // avoid leaks

        paymentStrategy = ps;
    }

    void setTotal(double t) 
    {
        total = t;
    }

    void setScheduledTime(const string& time) 
    {
        scheduled = time;
    }
};

#endif
