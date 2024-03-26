#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Order {
    vector< string> items;
    vector<double> prices;
    int num_items = 0;
public:
    Order() {}

    void add_item( string item_name, double item_price) {
        items.push_back(item_name);
        prices.push_back(item_price);
        num_items++;
    }

    void add_item(string item_name, string size, bool milk, double item_price) {
        items.push_back(item_name);
        if (size == "small") item_price = 2.00;
        else if (size == "medium") item_price = 3.00;
        else if (size == "large") item_price = 4.00;
        if (milk) item_price += 0.50;
        prices.push_back(item_price);
        num_items++;
    }

    void add_item(string item_name, double item_price, int quantity) {
        items.push_back(item_name);
        prices.push_back(item_price * quantity);
        num_items += quantity;
    }
    void display() {
        for (int i = 0; i < num_items; i++) {
            cout << items[i] << " " << prices[i] << endl;
        }
    }
};
int main() {
    Order order;
    order.add_item("Tea", 1.00);
    order.display();
    cout<<endl;
    order.add_item("Coffee", "small", true, 2.00);
    order.display();
    cout<<endl;
    order.add_item("Pastries", 2.00, 2);
    order.display();
    cout<<endl;
    return 0;
}