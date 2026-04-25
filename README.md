# Zoto 🍽️

Zoto is a Zomato-inspired food ordering system built in C++. It simulates a real-world ordering experience with support for both pickup and delivery orders, multiple payment methods, and a clean modular codebase designed around well-known software design patterns.

---

## About the Project

Zoto was built to demonstrate how large C++ applications can be structured cleanly using design patterns like Strategy and Factory. Rather than writing tangled, monolithic code, the project separates every concern into its own layer — models, factories, managers, services, and strategies — making it easy to read, extend, and maintain.

---

## Features

**Modular Architecture** — The codebase is organized into distinct layers, each with a single responsibility. Models define data, factories create objects, managers handle business logic, and services handle side effects like notifications.

**Strategy Pattern for Payments** — Payment handling is fully abstracted. The app currently supports UPI and Credit Card payments, and adding a new payment method requires no changes to existing code — just a new strategy class.

**Factory Pattern for Orders** — Orders are created through factory classes, keeping object construction logic centralized and decoupled from the rest of the application.

**Pickup and Delivery Support** — The system supports two order types. Pickup orders and delivery orders each have their own model with type-specific behavior, both inheriting from a shared base class.

**Extensible by Design** — The open/closed principle is followed throughout. New order types, payment methods, or services can be added without touching existing, working code.

---

## Getting Started

To build and run Zoto, you need a C++ compiler that supports C++17 or later (such as `g++` or `clang++`).

Clone the repository and compile with:

```bash
g++ -std=c++17 -o zoto main.cpp
./zoto
```

---

## Design Patterns Used

Zoto is built around three core design patterns. The **Strategy Pattern** powers the payment system, allowing payment methods to be swapped at runtime without changing the order logic. The **Factory Pattern** is used to instantiate different order types cleanly without exposing construction details. The **Manager Pattern** centralizes the lifecycle of orders, keeping business logic out of models and main entry points.

---

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

---

## License

[MIT](LICENSE)
