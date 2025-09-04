#ifndef CREDIT_CARD_PAYMENT_STRATEGY_H
#define CREDIT_CARD_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class CreditCardPaymentStrategy : public PaymentStrategy {
    private:
        string cardNumber;
    public:
        CreditCardPaymentStrategy(const string& card) {
            cardNumber = card;
        }

        void pay(double ammount) override {
            cout << "paid " << ammount << " using credit card ("<< cardNumber <<")" << endl;
        }
};

#endif