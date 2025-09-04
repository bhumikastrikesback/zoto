#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>
#include <string>
#include "../models/MenuItem.h"
#include "../models/Restaurant.h"

using namespace std;

class Cart {
private:
    Restaurant* restaurant;
    vector<MenuItem> items;

public:
    // Constructor
    Cart() {
        restaurant = nullptr;
    }

    // Add item to cart
    void addItem(const MenuItem& item) {
        if (!restaurant) {
            cerr << "Cart: set a restaurant before adding items" << endl;
            return;
        }
        items.push_back(item);
    }

    // Get total cost of all items
    double getTotalCost() const {
        double sum = 0;
        for (const auto& it : items) {
            sum += it.getPrice();
        }
        return sum;
    }

    // Check if cart is empty
    bool isEmpty() const {
        return (!restaurant || items.empty());
    }

    // Clear cart
    void clear() {
        items.clear();
        restaurant = nullptr;
    }

    // --- Getters ---
    Restaurant* getRestaurant() const {
        return restaurant;
    }

    vector<MenuItem> getItems() const {
        return items;
    }

    // --- Setters ---
    void setRestaurant(Restaurant* r) {
        restaurant = r;
    }

    void setItems(const vector<MenuItem>& newItems) {
        items = newItems;
    }
};

#endif
