#include <iostream>
using namespace std;
class Employee{
public:
    string ID, name, address;
    bool status;
    virtual void add_new_emplyee(Employee *e) = 0;
    void virtual display_all_emplyees() = 0;
    bool status_return() const { return status; }
};
class Manager{
protected:
    string username, password;

public:
    virtual bool login_successful() = 0;
};
class Inventory{
protected:
    int product_ID;
    string product_name;
    double product_price;
    int quantity;
    static int i;

public:
    virtual double totalcost() = 0;
};
class MIS : public Employee, public Manager, public Inventory{
protected:
    Employee **emp;
    static int i;

public:
    double totalcost(){
        return product_price * quantity;
    }
    bool login_successful(){
        username = "sahil";
        password = "123";
        string temp_user, temp_password;
        cout << "ENTER THE USER NAME :" << endl;
        cin >> temp_user;
        cout << "ENTER THE PASSWORD " << endl;
        cin >> temp_password;

        if (username == temp_user && password == temp_password)
        {
            return true;
        }
        else
        {
            cout << "INCORRECT PASSWORD !" << endl;
            return false;
        }
    }
    void add_new_emplyee(Employee *e){
        emp[i] = e;
        i++;
    }
    void display_all_emplyees(){
        for (int i = 0; i < 10; i++)
        {
            if (emp[i] != nullptr)
            {
                cout << "Employee " << i + 1 << " Name: " << emp[i]->name << endl;
                cout << "Employee " << i + 1 << " address: " << emp[i]->address << endl;
                cout << "Employee " << i + 1 << " Stauts: " << (emp[i]->status ? "active" : "Inactive") << endl;
                cout << "Employee  " << i + 1 << " ID: " << emp[i]->ID << endl;
            }
        }
    }
    MIS()
    {
        emp = new Employee *[10];
        for (int i = 0; i < 10; i++)
        {
            emp[i] = nullptr;
        }
    }
};
int MIS::i = 0;

int main()
{
    Employee *e1 = new MIS();
    e1->name = "Sahil Latif";
    e1->address = "FAST";
    e1->ID = "123";
    e1->status = true;

    Employee *e2 = new MIS();
    e2->name = "Latif";
    e2->address = " Karachi";
    e2->ID = "124";
    e2->status = false;
    MIS mis;
    mis.login_successful();
    mis.add_new_emplyee(e1);
    mis.add_new_emplyee(e2);
    mis.totalcost();
    mis.display_all_emplyees();
}