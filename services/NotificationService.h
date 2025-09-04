#ifndef NOTIFICATION_SERVICE_H
#define NOTIFICATION_SERVICE_H

#include <iostream>
#include "../models/Order.h"

using namespace std;

class NotificationService {
    public:
        static void notify(Order* order) {
            cout << "\nNotification: new " << order->getType() << "order placed" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "Order Id: " << order->getOrderId() << endl;
            cout << "customer: " << order->getUser()->getName() << endl;
            cout << "Restaurant: " << order->getRestaurant()->getName() << endl;
            cout << "items order:\n" << endl;

            const vector<MenuItem>& items = order->getItems();
            for(const auto& item : items) {
                cout << " -" << item.getName() << "(rupees" << item.getPrice() << endl;
            }

            cout << "Total: rupees" << order->getTotal() << endl;
            cout << "Scheduled for: " << order->getScheduledTime() << endl;
            cout << "Payment: Done" << endl;
            cout << "----------------------------------" << endl;
        }
};
#endif