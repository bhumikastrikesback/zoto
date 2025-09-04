#include <iostream>
#include "Zoto.h"

using namespace std;

int main() {
    //create zoto app facade
    Zoto* zoto = new Zoto();

    //simulate a user comming in (happy flow)
    User*user = new User(101, "Aditya", "Delhi");
    cout << "User: " << user->getName() << " is active." << endl;

    //user searches for restaurant by location
    vector<Restaurant*> restaurantList = zoto->searchRestaurants("Delhi");

    if(restaurantList.empty()) {
        cout << "No restaurant found!!" << endl;
        return 0;
    }

    cout << "Found Restauarnts: " << endl;
    for(auto restauarnt : restaurantList) {
        cout << "-" << restauarnt->getName() << endl;
    }

    // user selects a restaurant
    zoto->selectRestauarnt(user, restaurantList[0]);
    cout << "selected restauarnt: " << restaurantList[0]->getName() << endl;

    //user adds item to cart
    zoto->addToCart(user, "p1");
    zoto->addToCart(user, "p2");

    zoto->printUserCart(user);

    //user checkout the cart
    Order* order = zoto->checkOutNow(user, "Delivery", new UpiPaymentStrategy("1234567890"));

    //user pay for cart.if payment is success, notification is sent
    zoto->payForOrder(user, order);

    //clenup code
    delete zoto;
    delete user;

    return 0;
}