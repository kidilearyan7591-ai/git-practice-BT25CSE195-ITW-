#include <iostream>
using namespace std;

class Vehicle
{
protected:
    float speed;
    float distance;

public:
    void getVehicleData()
    {
        cout << "Enter speed of vehicle (km/h): ";
        cin >> speed;

        cout << "Enter distance to travel (km): ";
        cin >> distance;
    }

    float calculateTime()
    {
        return distance / speed;
    }
};

class Car : public Vehicle
{
private:
    float fuelConsumption;

public:
    void getCarData()
    {
        cout << "Enter fuel consumption (km/l): ";
        cin >> fuelConsumption;
    }

    float calculateFuel()
    {
        return distance / fuelConsumption;
    }

    void display()
    {
        cout << "\nSingle Inheritance" << endl;
        cout << "Time taken: " << calculateTime() << " hours" << endl;
        cout << "Fuel required: " << calculateFuel() << " litres" << endl;
    }
};

class Engine
{
protected:
    float horsepower;

public:
    void getEngineData()
    {
        cout << "\nEnter horsepower: ";
        cin >> horsepower;
    }
};

class Body
{
protected:
    float weight;

public:
    void getBodyData()
    {
        cout << "Enter weight of car (kg): ";
        cin >> weight;
    }
};

class MultiCar : public Engine, public Body
{
public:
    float calculatePowerToWeight()
    {
        return horsepower / weight;
    }

    void display()
    {
        cout << "\nMultiple Inheritance" << endl;
        cout << "Power-to-weight ratio: " << calculatePowerToWeight() << endl;
    }
};

int main()
{
    Car car;

    car.getVehicleData();
    car.getCarData();
    car.display();

    MultiCar car2;

    car2.getEngineData();
    car2.getBodyData();
    car2.display();

    return 0;
}