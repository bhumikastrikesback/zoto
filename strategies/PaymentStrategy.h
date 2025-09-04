#ifndef PAYMENT_STRATEGY_H
#define PAYMENT_STRATEGY_H

#include <iostream>
#include <string>

using namespace std;

class PaymentStrategy {
    public:
        virtual void pay(double ammount) = 0;
        virtual ~PaymentStrategy() {}
};

#endif