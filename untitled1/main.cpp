#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Сharacteristic {
public:
    virtual string getName() = 0;
    virtual double getMaxSpeed() = 0;
    virtual int getWheelsCount() = 0;
};

class Factory {
private:
    class Motorcycle : public Сharacteristic {
    public:
        string getName() {
            return "Мотоцикл";
        }
        double getMaxSpeed() {
            return 220.0;
        }
        int getWheelsCount() {
            return 2;
        }
    };

    class Bus : public Сharacteristic {
    public:
        string getName() {
            return "Автобус";
        }
        double getMaxSpeed() {
            return 100.0;
        }
        int getWheelsCount() {
            return 6;
        }
    };

    class Scooter : public Сharacteristic {
    public:
        string getName() {
            return "Самокат";
        }
        double getMaxSpeed() {
            return 15.0;
        }
        int getWheelsCount() {
            return 2;
        }
    };

    class Car : public Сharacteristic {
    public:
        string getName() {
            return "Автомобиль";
        }
        double getMaxSpeed() {
            return 250.0;
        }
        int getWheelsCount() {
            return 4;
        }
    };

public:
    enum VirtualType { V_MOTORCYCLE, V_BUS, V_SCOOTER, V_CAR };

    Сharacteristic* getСharacteristic(VirtualType vtype) {
        switch (vtype) {
        case V_MOTORCYCLE:
            return new Motorcycle();
        case V_BUS:
            return new Bus();
        case V_SCOOTER:
            return new Scooter();
        case V_CAR:
            return new Car();
        default:
            return 0;
        }
    }
};

int main() {
    Factory factory;
    Сharacteristic* motorcycle = factory.getСharacteristic(Factory::V_MOTORCYCLE);
    Сharacteristic* bus = factory.getСharacteristic(Factory::V_BUS);
    Сharacteristic* scooter = factory.getСharacteristic(Factory::V_SCOOTER);
    Сharacteristic* car = factory.getСharacteristic(Factory::V_CAR);

    setlocale(LC_CTYPE, "Russian");

    int menu, submenu;
    
    do {       
        cout << "Выберите тип транспорта:" << endl;
        cout << "1. Самокат" << endl;
        cout << "2. Мотоцикл" << endl;
        cout << "3. Автобус" << endl;
        cout << "4. Автомобиль" << endl;
        cout << "5. Показать все доступные типы транспорта" << endl;
        cout << "0. Выход" << endl << endl;
        cout << "Введите номер с выбранным типом транспорта: ";
        cin >> menu;
        switch (menu) {
        case 1: {
            system("CLS");
            do {             
                cout << "Наименование транспорта: " << scooter->getName() << endl;
                cout << "Кол-во колес: " << scooter->getWheelsCount() << endl;
                cout << "Максимальная скорость: " << scooter->getMaxSpeed() << " км/ч" << endl;
                cout << "Введите цифру 0 чтобы выйти в главное меню: ";
                cin >> submenu;               
            } while (submenu != 0);
        }
              break;
        case 2: {
            system("CLS");
            do {
                cout << "Наименование транспорта: " << motorcycle->getName() << endl;
                cout << "Кол-во колес: " << motorcycle->getWheelsCount() << endl;
                cout << "Максимальная скорость: " << motorcycle->getMaxSpeed() << " км/ч" << endl;
                cout << "Введите цифру 0 чтобы выйти в главное меню: ";
                cin >> submenu;
            } while (submenu != 0);
        }
        break;
        case 3: {
            system("CLS");
            do {
                cout << "Наименование транспорта: " << bus->getName() << endl;
                cout << "Кол-во колес: " << bus->getWheelsCount() << endl;
                cout << "Максимальная скорость: " << bus->getMaxSpeed() << " км/ч" << endl;
                cout << "Введите цифру 0 чтобы выйти в главное меню: ";
                cin >> submenu;
            } while (submenu != 0);
        }
              break;
        case 4: {
            system("CLS");
            do {
                cout << "Наименование транспорта: " << car->getName() << endl;
                cout << "Кол-во колес: " << car->getWheelsCount() << endl;
                cout << "Максимальная скорость: " << car->getMaxSpeed() << " км/ч" << endl;
                cout << "Введите цифру 0 чтобы выйти в главное меню: ";
                cin >> submenu;
            } while (submenu != 0);
        }
              break;
        case 5: {
            system("CLS");
            do {
                cout << "Наименование транспорта: " << scooter->getName() << endl;
                cout << "Кол-во колес: " << scooter->getWheelsCount() << endl;
                cout << "Максимальная скорость: " << scooter->getMaxSpeed() << " км/ч" << endl;

                cout << endl;

                cout << "Наименование транспорта: " << motorcycle->getName() << endl;
                cout << "Кол-во колес: " << motorcycle->getWheelsCount() << endl;
                cout << "Максимальная скорость: " << motorcycle->getMaxSpeed() << " км/ч" << endl;

                cout << endl;

                cout << "Наименование транспорта: " << bus->getName() << endl;
                cout << "Кол-во колес: " << bus->getWheelsCount() << endl;
                cout << "Максимальная скорость: " << bus->getMaxSpeed() << " км/ч" << endl;

                cout << endl;

                cout << "Наименование транспорта: " << car->getName() << endl;
                cout << "Кол-во колес: " << car->getWheelsCount() << endl;
                cout << "Максимальная скорость: " << car->getMaxSpeed() << " км/ч" << endl;

                cout << endl;

                cout << "Введите цифру 0 чтобы выйти в главное меню: ";
                cin >> submenu;
            } while (submenu != 0);
        }
              break;
        default: {
            system("CLS");
            do {
                cout << "НЕИЗВЕСТНЫЙ ТИП ТРАНСПОРТА" << endl;
                cout << "Введите цифру 0 чтобы выйти в главное меню: ";
                cin >> submenu;
            } while (submenu != 0);
        }
               break;
        }
        system("CLS");

    } while (menu != 0);

    delete bus;
    delete scooter;
    delete car;
    delete motorcycle;

    system("pause");
    return 0;
}

