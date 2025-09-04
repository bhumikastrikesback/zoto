Zoto

A clone of Zomato built in C++.
This project features a menu ordering system with modular strategy-based payment handling, structured following good clean-code principles.

## Project Structure

├── Utils/                    # Utility classes (e.g., time-related functions)
├── factories/                # Factory classes to create Order objects
├── managers/                 # Manager classes (e.g., OrderManager)
├── models/
│   ├── Order.h               # Base abstract class for orders
│   ├── PickupOrder.h         # Pickup-specific order
│   └── DeliveryOrder.h       # Delivery-specific order
├── services/                 # Service classes (e.g., notifications)
├── strategies/
│   ├── PaymentStrategy.h     # Abstract strategy interface
│   ├── UpiPaymentStrategy.h  # UPI payment implementation
│   └── CreditCardPaymentStrategy.h  # Credit card payment implementation
├── Zoto.h                    # High-level orchestrator for the application
├── main.cpp                  # Entry point of the application
└── rum                       # ?? (Please clarify its purpose!)

Features

Modular Design
Clean separation of concerns using factories, models, managers, services, and strategies.

Strategy Pattern for Payments
Abstracts payment handling allowing easy swapping (UPI, Credit Card).

Factory Pattern for Orders
Creates different Order types (e.g., Pickup or Delivery) via factories.

Extensible Foundations
Easily add new payment methods, order types, or services without touching existing code.

