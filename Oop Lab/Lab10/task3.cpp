#include<iostream>
using namespace std;
class Customer{
    int id;
    string name;
    public:
        Customer(){}
        Customer(int i, string n):id(i), name(n){}
        void print(){
            cout<<"ID: "<<id<<endl;
            cout<<"Name: "<<name<<endl;
        }
        friend class Account;
};
class Account{
    int accountNumber;
    double balance;
    Customer owner;
    public:
        Account(){}
        Account(int a, double b, Customer c):accountNumber(a), balance(b), owner(c){}
        void deposit(double amount){
            balance += amount;
        }
        void withdraw(double amount){
            balance -= amount;
        }
        void checkBalance(){
            cout<<"Balance: "<<balance<<endl;
        }
        void print(){
            cout<<"Account Number: "<<accountNumber<<endl;
            cout<<"Balance: "<<balance<<endl;
        }
        friend Account operator+(Account& a1, Account& a2);
        friend class Bank;
};
Account operator+(Account& a1, Account& a2) {
    double transferAmount = a1.balance;
    if (a1.balance >= transferAmount) {
        a1.balance -= transferAmount;
        a2.balance += transferAmount;
    }
    return a1;
}
class Bank{
    Account *accounts;
    int size;
    public:
        Bank():size(0){}
        void openAccount(Customer c){
            Account *newAccounts = new Account[size+1];
            for(int i=0;i<size;i++)
                newAccounts[i] = accounts[i];
            newAccounts[size++] = Account(rand()%1000,0,c);
            accounts = newAccounts;
        }

};
int main() {
    Bank b;
    Customer c1(1, "Sahil"),c2(2, "Latif");
    b.openAccount(c1);
    b.openAccount(c2);
    Account a1(202, 100, c1), a2(203, 200, c2);
    a1 = a1 + a2;
    a1.print();

}