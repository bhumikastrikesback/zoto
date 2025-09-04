#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class UpiPaymentStrategy : public PaymentStrategy {
    private:
        string mobile;
    public:
        UpiPaymentStrategy(const string& mob) {
            mobile = mob;
        }

        void pay(double ammount) override {
            cout << "paid " << ammount << " using UPI" << endl;
        }
};

#endif
