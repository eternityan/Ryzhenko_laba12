#include <iostream>
#include <string>
using namespace std;

class Sensor {
protected:
    float value;

public:
    Sensor(float value) : value(value) {}

    virtual float ReadValue() {
        return value;
    }
};

class TemperatureSensor : public Sensor {
private:
    char unit;

public:
    TemperatureSensor(int value, char unit) : Sensor(value), unit(unit) {
    }

    void SetUnit(char newUnit) {
        if (newUnit == 'C' || newUnit == 'F')
            unit = newUnit;
        else
            cout << "Неправильна одиниця виміру, використовуйте 'C' або 'F'!" << endl;
    }

    char GetUnit() {
        return unit;
    }

    float ConvertToFahrenheit() {
        if (unit == 'C')
            return value * 9.0 / 5.0 + 32.0;
        else if (unit == 'F')
            return value;
        cout << "Неправильна одиниця виміру!" << endl;
        return 0;
    }

    float ReadValue() override {
        value = Sensor::ReadValue();
        cout << "Значення температури: " << value << " " << unit << endl;
        return value;
    }
};

int main() {
    TemperatureSensor tempSensor(18.0f, 'C');
    tempSensor.ReadValue();

    cout << "Температура у Фаренгейтах: "
            << tempSensor.ConvertToFahrenheit() << " F" << endl;

    tempSensor.SetUnit('F');
    tempSensor.ReadValue();

    cout << "Температура у Фаренгейтах: "
            << tempSensor.ConvertToFahrenheit() << " F" << endl;

    return 0;
}
