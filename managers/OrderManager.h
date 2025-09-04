#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include <iostream>
#include <vector>
#include "../models/Order.h"

using namespace std;

class OrderManager {
private:
    vector<Order*> orders;
    static OrderManager* instance;

    // Private constructor for singleton
    OrderManager() {
        // Nothing to initialize
    }

public:
    // Get singleton instance
    static OrderManager* getInstance() {
        if (!instance) {
            instance = new OrderManager();
        }
        return instance;
    }

    // Add order
    void addOrder(Order* order) {
        orders.push_back(order);
    }

    // List all orders
    void listOrders() {
        cout << "\n--- All Orders ---" << endl;

        for (const auto& order : orders) {
            cout << "Order ID: " 
                 << order->getOrderId() 
                 << ", Type: " 
                 << order->getType() 
                 << ", Total: " 
                 << order->getTotal() 
                 << endl;
        }
    }

    // --- Getters ---
    const vector<Order*>& getOrders() const {
        return orders;
    }
};

// Initialize static member
OrderManager* OrderManager::instance = nullptr;

#endif
