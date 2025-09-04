#ifndef NOW_ORDER_FACTORY_H
#define NOW_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../Utils/TimeUtils.h"

using namespace std;

class NowOrderFactory : public OrderFactory {
    public:
        Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector <MenuItem>& menuItems, PaymentStrategy* paymentStrategy,
        const string& orderType) override {
            Order* order = nullptr;
            if(orderType == "Delivery") {
                auto deliveryOrder = new DeliveryOrder();
                deliveryOrder->setUserAddress(user->getAddress());
                order = deliveryOrder;
            } else {
                auto pickupOrder = new PickupOrder();
                pickupOrder->setRestaurantAddress(restaurant->getLocation());
                order = pickupOrder;
            }
            order->setUser(user);
            order->setRestaurant(restaurant);
            order->setItems(menuItems);
            order->setPaymentStrategy(paymentStrategy);
            order->setScheduledTime(TimeUtils::getCurrentTime());
            order->setTotal(cart->getTotalCost());
            return order;
        }
};

#endif