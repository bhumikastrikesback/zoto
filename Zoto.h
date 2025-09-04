#ifndef ZOTO_H
#define ZOTO_H

#include <vector>
#include <string>
#include "models/User.h"
#include "models/Restaurant.h"
#include "models/Cart.h"
#include "managers/OrderManager.h"
#include "managers/RestrauntManager.h"
#include "strategies/UpiPaymentStrategy.h"
#include "factories/NowOrderFactory.h"
#include "factories/ScheduledFactory.h"
#include "services/NotificationService.h"
#include "Utils/TimeUtils.h"

using namespace std;

class Zoto {
    public:
        Zoto() {
            initialiseRestaurants();
        }

        void initialiseRestaurants() {
            Restaurant* restaurant1 = new Restaurant("Bikaner", "Delhi");
            restaurant1->addMenuItem(MenuItem("P1", "chole Bhature", 120));
            restaurant1->addMenuItem(MenuItem("p2", "samosa", 15));

            Restaurant* restaurant2 = new Restaurant("Haldiram", "kolkata");
            restaurant2->addMenuItem(MenuItem("P1", "raj kachori", 200));
            restaurant2->addMenuItem(MenuItem("p2", "noodles", 180));
            restaurant2->addMenuItem(MenuItem("p3", "Dhokla", 100));

            Restaurant* restaurant3 = new Restaurant("Dominos", "rajasthan");
            restaurant3->addMenuItem(MenuItem("p1", "garlic bread", 270));
            restaurant3->addMenuItem(MenuItem("p2", "cheese pizza", 290));
            restaurant3->addMenuItem(MenuItem("p3", "cheese dip", 50));

            RestaurantManager* restaurantManager = RestaurantManager::getinstance();
            restaurantManager->addRestraunt(restaurant1);
            restaurantManager->addRestraunt(restaurant2);
            restaurantManager->addRestraunt(restaurant3);

            // Add other sample restaurants.....
        }

        vector<Restaurant*> searchRestaurants(const string& location) {
            return RestaurantManager::getinstance()-> searchByLocation((location));
        }

        void selectRestauarnt(User* user, Restaurant* restaurant) {
            Cart* cart = user->getCart();
            cart->setRestaurant(restaurant);
        }

        void addToCart(User* user, const string& itemCode) {
            Restaurant* restaurant = user->getCart()->getRestaurant();
            if(!restaurant) {
                cout << "pls select a restauarant first" << endl;
                return;
            }
            for(const auto& item: restaurant->getMenu()) {
                if(item.getCode() == itemCode) {
                    user->getCart()->addItem(item);
                    break;
                }
            }
        }

        Order* checkOutNow(User* user, const string& orderType, PaymentStrategy* paymentStrategy) {
            return checkout(user,orderType, paymentStrategy, new NowOrderFactory());
        }

        Order* checkOutScheduled(User* user, const string& orderType, PaymentStrategy* paymentStrategy, const string& scheduleTime) {
            return checkout(user, orderType, paymentStrategy, new ScheduledOrderFactory(scheduleTime));
        }

      Order* checkout(User* user, const string& orderType, PaymentStrategy* paymentStrategy, OrderFactory* orderFactory) {
        if (user->getCart()->isEmpty()) {
            return nullptr;
        }

        Cart* userCart = user->getCart();
        Restaurant* orderedRestaurant = userCart->getRestaurant();
        vector<MenuItem> itemsOrdered = userCart->getItems();

        Order* order = orderFactory->createOrder(user, userCart, orderedRestaurant, itemsOrdered, paymentStrategy,
        orderType);

        OrderManager::getInstance()->addOrder(order);
        return order;
    }

    void payForOrder(User* user, Order* order) {
        bool isPaymentSuccess = order->processPayment();

        //clear cart if payment is successfull
        if(isPaymentSuccess) {
            NotificationService* notification = new NotificationService();
            notification->notify(order);
            user->getCart()->clear();
        }
    }

    void printUserCart(User* user) {
        cout << "items in cart: " << endl;
        cout << "------------------------------------" << endl;
        for(const auto &item: user->getCart()->getItems()) {
            cout << item.getCode() << "." << item.getName() << ": Rupees" << item.getPrice() << endl;
        }
        cout << "------------------------------------" << endl;
        cout << "Grand total: rupees" << user->getCart()->getTotalCost() << endl;
    }   
};
#endif