#include<iostream>
using namespace std;
class Employee{
    int ID;
    string name;
    double salary;
    public:
        friend class Payroll;
        Employee(int id, string n, double s):ID(id), name(n), salary(s){}
        friend void printEmployeeSalary(Employee &emp);
};
class Payroll{
    double taxRate, benefitsCost;
    public:
        Payroll(double tR, double bC):taxRate(tR), benefitsCost(bC){}
        double calculateNetSalary(Employee &emp){
            return emp.salary - (emp.salary*taxRate) - benefitsCost + 1000;          
        }

};
void printEmployeeSalary(Employee &emp){
    cout<<"Name: "<<emp.name<<endl;
    cout<<"Salary: "<<emp.salary<<endl;
}
int main() {
    Payroll p(0.1, 500);
    Employee e(101, "Sahil", 7000);
    cout<<"Net Salary: "<<p.calculateNetSalary(e)<<endl;
    printEmployeeSalary(e);   
}