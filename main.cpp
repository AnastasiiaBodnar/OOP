#include <iostream>
#include <windows.h>
#include "RentalCar.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "=== СИСТЕМА ПРОКАТУ АВТОМОБІЛІВ ===\n\n";

    // Лр3: конструктор викликається при створенні об'єктів
    RentalCar car1("Toyota Camry", "BX 1024 AA", 1500.0, true, 45200);
    RentalCar car2("Skoda Octavia", "BX 5588 BC", 1100.0, false, 98000);

    int choice;
    do {
        cout << "\n============== МЕНЮ ==============\n";
        cout << "1. Перегляд даних (Лр2)\n";
        cout << "2. Запис нових даних (Лр2)\n";
        cout << "3. Дружня функція: вартість оренди (Лр3)\n";
        cout << "4. Деструктор: блок { } (Лр3)\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:  // Лр2: метод для перегляду полів
                car1.displayInfo();
                car2.displayInfo();
                break;
            case 2:  // Лр2: метод для запису полів
                car1.setData("Honda Civic", "BX 3030 CC", 1300.0, true, 20500);
                car1.displayInfo();
                break;
            case 3: {  // Лр3: дружня функція
                int num, days;
                cout << "Яке авто?\n";
                cout << "1 - " << car1.getBrand() << " (" << car1.getDailyRate() << " грн/доба)\n";
                cout << "2 - " << car2.getBrand() << " (" << car2.getDailyRate() << " грн/доба)\n";
                cout << "Ваш вибір: ";
                cin >> num;
                cout << "Кількість діб: ";
                cin >> days;
                RentalCar& car = (num == 1) ? car1 : car2;
                double cost = calculateRentalCost(car, days);
                if (car.getAvailability()) {
                    cout << "Вартість оренди " << car.getBrand() << ": " << cost << " грн\n";
                }
                break;
            }
            case 4: {  // Лр3: деструктор, об'єкт живе тільки всередині блоку
                cout << "--- Вхід у блок ---\n";
                RentalCar temp("Renault Logan", "BX 7777 KK", 900.0, true, 12000);
                cout << "--- Вихід з блоку ---\n";
                break;
            }
            case 0:
                cout << "Кінець програми.\n";
                break;
            default:
                cout << "Невірний пункт меню!\n";
        }
    } while (choice != 0);

    return 0;
}