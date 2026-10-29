#ifndef RENTALCAR_H
#define RENTALCAR_H

#include <string>

using namespace std;

// Користувацький клас згідно з Варіантом 2 (Прокат автомобілів)
class RentalCar {
private:
    string brand;
    string licensePlate;
    double dailyRate;
    bool isAvailable;
    int mileage;

public:
    // Лр3, п.1: конструктор
    RentalCar(const string& carBrand, const string& plate,
              double rate, bool available, int carMileage);

    // Лр3, п.1: деструктор
    ~RentalCar();

    // Лр2, п.2: методи для запису полів
    void setData(const string& carBrand, const string& plate,
                 double rate, bool available, int carMileage);
    void setDailyRate(double rate);
    void setAvailability(bool available);

    // Лр2, п.2: метод для перегляду повної інформації
    void displayInfo() const;

    string getBrand() const;
    string getLicensePlate() const;
    double getDailyRate() const;
    bool getAvailability() const;
    int getMileage() const;

    // Лр3, п.1: оголошення дружньої функції
    friend double calculateRentalCost(const RentalCar& car, int days);
};

// Прототип дружньої функції (щоб її бачив main.cpp)
double calculateRentalCost(const RentalCar& car, int days);

#endif  // RENTALCAR_H