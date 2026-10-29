#include "RentalCar.h"

#include <iomanip>
#include <iostream>

RentalCar::RentalCar(const string& carBrand, const string& plate,
                     double rate, bool available, int carMileage) {
    brand = carBrand;
    licensePlate = plate;
    dailyRate = (rate >= 0) ? rate : 0.0;
    isAvailable = available;
    mileage = (carMileage >= 0) ? carMileage : 0;
    cout << "[Конструктор] Створено об'єкт: " << brand
         << " (" << licensePlate << ")\n";
}

RentalCar::~RentalCar() {
    cout << "[Деструктор] Знищено об'єкт: " << brand
         << " (" << licensePlate << ")\n";
}

void RentalCar::setData(const string& carBrand, const string& plate,
                        double rate, bool available, int carMileage) {
    brand = carBrand;
    licensePlate = plate;
    dailyRate = (rate >= 0) ? rate : 0.0;
    isAvailable = available;
    mileage = (carMileage >= 0) ? carMileage : 0;
}

void RentalCar::setDailyRate(double rate) {
    if (rate >= 0) dailyRate = rate;
}

void RentalCar::setAvailability(bool available) {
    isAvailable = available;
}

void RentalCar::displayInfo() const {
    cout << "-----------------------------------------\n";
    cout << "Автомобіль:        " << brand << "\n";
    cout << "Номерний знак:     " << licensePlate << "\n";
    cout << "Тариф за добу:     " << fixed << setprecision(2)
         << dailyRate << " грн\n";
    cout << "Статус:            " << (isAvailable ? "Вільний до прокату" : "В оренді") << "\n";
    cout << "Поточний пробіг:   " << mileage << " км\n";
    cout << "-----------------------------------------\n";
}

string RentalCar::getBrand() const { return brand; }
string RentalCar::getLicensePlate() const { return licensePlate; }
double RentalCar::getDailyRate() const { return dailyRate; }
bool RentalCar::getAvailability() const { return isAvailable; }
int RentalCar::getMileage() const { return mileage; }

// Лр3, п.1: дружня функція (не є методом класу, але має доступ до private-полів).
// Рахує вартість оренди, при оренді від 7 діб знижка 10%.
double calculateRentalCost(const RentalCar& car, int days) {
    if (!car.isAvailable) {
        cout << "Автомобіль " << car.brand << " зараз в оренді.\n";
        return 0.0;
    }
    double total = car.dailyRate * days;
    if (days >= 7) total *= 0.9;
    return total;
}