#include <iostream>
using namespace std;
class Product {
protected:
    double price;
public:
    virtual double get_price() {
        return price;
    }
};

class TV : public Product {
    double screen_size;
    int resolution;
public:
    double warranty_price() {
        return price * 0.05;
    }
};

class Laptop : public Product {
    double processing_power;
    int memory;
public:
    double tax_amount() {
        return price * 0.10;
    }
};

class Smartphone : public Product {
    double screen_size;
    int camera_resolution;
public:
    Smartphone(double screen_size, int camera_resolution) : screen_size(screen_size), camera_resolution(camera_resolution) {}
    double get_price() {
        price = (screen_size + camera_resolution) * 0.05;
        return price;
    }
};

int main() {
    TV tv;
    Laptop laptop;
    Smartphone smartphone(5.5, 12);
    Product *p = &smartphone;
    cout << "TV Warranty Price: " << tv.warranty_price() << endl;
    cout << "Laptop Tax Amount: " << laptop.tax_amount() << endl;
    cout << "Smartphone Price: " << smartphone.get_price() << endl;
    cout << "Smartphone Price: " << p->get_price() << endl;

    return 0;
}