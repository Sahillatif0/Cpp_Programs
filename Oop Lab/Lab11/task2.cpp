#include <iostream>
using namespace std;
class Vehicle{
protected:
    virtual void details() = 0;
    virtual double cost_NET(float a) = 0;
};
class Car : public Vehicle{
public:
    int numDoors;
    float tax_rate;
    double cost;
    void details()
    {
        cout << "Car Has " << numDoors << " no of doors" << endl;
    }
    double cost_NET(float t)
    {
        return (cost * (1 + (t / 100)));
    }
};
int main()
{
    Car c;
    c.cost = 50000;
    c.numDoors = 7;
    cout << "Total cost + tax " << c.cost_NET(10) << endl;
    c.details();
}