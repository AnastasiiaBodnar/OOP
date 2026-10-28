#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

// 1. Користувацький клас згідно з Варіантом 2 (Прокат автомобілів)
class RentalCar {
private:
    std::string brand;
    std::string licensePlate;
    double dailyRate;
    bool isAvailable;
    int mileage;

public:
    // 2. Метод для запису
    void setData(const std::string& carBrand, const std::string& plate,
                 double rate, bool available, int carMileage) {
        brand = carBrand;
        licensePlate = plate;
        dailyRate = (rate >= 0) ? rate : 0.0;
        isAvailable = available;
        mileage = (carMileage >= 0) ? carMileage : 0;
    }

    void setDailyRate(double rate) {
        if (rate >= 0) dailyRate = rate;
    }

    void setAvailability(bool available) {
        isAvailable = available;
    }

    // 2. Метод для перегляду повної інформації
    void displayInfo() const {
        std::cout << "-----------------------------------------\n";
        std::cout << "Автомобіль:        " << brand << "\n";
        std::cout << "Номерний знак:     " << licensePlate << "\n";
        std::cout << "Тариф за добу:     " << std::fixed << std::setprecision(2)
                  << dailyRate << " грн\n";
        std::cout << "Статус:            " << (isAvailable ? "Вільний до прокату" : "В оренді") << "\n";
        std::cout << "Поточний пробіг:   " << mileage << " км\n";
        std::cout << "-----------------------------------------\n";
    }

    std::string getBrand() const { return brand; }
    std::string getLicensePlate() const { return licensePlate; }
    double getDailyRate() const { return dailyRate; }
    bool getAvailability() const { return isAvailable; }
    int getMileage() const { return mileage; }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "=== СИСТЕМА ПРОКАТУ АВТОМОБІЛІВ ===\n\n";

    RentalCar car1;
    RentalCar car2;

    car1.setData("Toyota Camry", "BX 1024 AA", 1500.0, true, 45200);
    car2.setData("Skoda Octavia", "BX 5588 BC", 1100.0, false, 98000);

    std::cout << "Інформація про перше авто:\n";
    car1.displayInfo();

    std::cout << "\nІнформація про друге авто:\n";
    car2.displayInfo();

    std::cout << "\nЗміна статусу для другого авто (повернення з прокату)..." << std::endl;
    car2.setAvailability(true);
    std::cout << "Новий статус автомобіля [" << car2.getBrand() << "]: "
              << (car2.getAvailability() ? "Вільний" : "В оренді") << std::endl;

    return 0;
}