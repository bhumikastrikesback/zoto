#ifndef USER_H
#define USER_H

#include <string>
#include "Cart.h"
using namespace std;

class User {
private:
    int userId;
    string name;
    string address;
    Cart* cart;

public:
    // Constructor
    User(int userId, const string& name, const string& address) {
        this->userId = userId;
        this->name = name;
        this->address = address;
        cart = new Cart();
    }

    // Destructor
    ~User() {
        delete cart;
    }

    // Getters
    int getUserId() const {
        return userId;
    }

    string getName() const {
        return name;
    }

    string getAddress() const {
        return address;
    }

    Cart* getCart() const {
        return cart;
    }

    // Setters
    void setUserId(int id) {
        userId = id;
    }

    void setName(const string& newName) {
        name = newName;
    }

    void setAddress(const string& newAddress) {
        address = newAddress;
    }

    void setCart(Cart* newCart) {
        if(cart) delete cart;   // Avoid memory leak
        cart = newCart;
    }
};

#endif
