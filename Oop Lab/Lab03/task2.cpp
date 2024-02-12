#include <iostream>
using namespace std;

class WaterBottle
{
    string company, color;
    float capacityInml, capacityInl;

public:
    void setBrand(string cp, string c)
    {
        company = cp;
        color = c;
    }
    void setcapacityinl() { capacityInl = capacityInml / 1000; }
    void setcapacityiml(float ml)
    {
        capacityInml = ml;
        setcapacityinl();
    }
    float getcapacityiml() { return capacityInml; }
    void show()
    {
        cout << "The brand of the water bottle is " << company << endl;
        cout << "The color of the water bottle is " << color << endl;
        cout << "The capacity of the water bottle in liters is " << capacityInl << "l" << endl;
        cout << "The capacity of the water bottle in milliliters is " << capacityInml << "ml" << endl;
    }

    void addWater(int ml)
    {
        capacityInml += ml;
        setcapacityinl();
    }
};

int main()
{
    WaterBottle b1;
    float waterDrank;
    b1.setBrand("Nestle", "Blue");
    b1.setcapacityiml(1500);
    b1.show();

    if (b1.getcapacityiml() < 2000)
    {
        cout << "how much water a person has drank: ";
        cin >> waterDrank;
        b1.addWater(waterDrank);
        cout << "Water added" << endl;
        b1.show();
    }
}