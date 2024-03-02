#include<iostream>
using namespace std;
class BankAccount{
    string accountHolderName;
    const int accountNumber;
    double balance;
    public:
        BankAccount(string ahn, int an, double bal):accountHolderName(ahn),accountNumber(an), balance(bal){}
        void setBalance(double bal){balance =  bal;}
        void setName(string n){accountHolderName = n;}
        int getAccNum(){return accountNumber;}
        string getAccHoldName(){return accountHolderName;}
        double getBalance(){return balance;}
        void deposit(double amnt){balance+=amnt;}
        void withdraw(double amnt){if(balance>amnt)balance-=amnt;else cout<<"Unefficient Balance"<<endl;}
        void display(){
            cout<<"Account Holder Name: "<<accountHolderName<<endl;
            cout<<"Account Number: "<<accountNumber<<endl;
            cout<<"Balance: "<<balance<<endl;
        }
};
int main(){
    BankAccount b[3] = {BankAccount("Sahil Latif", 2173873, 129.62), BankAccount("Latif", 2173423, 19.26), BankAccount("Ali", 2023873, 139.21)};
    for(int i=0;i<3;i++){
        b[i].display();
        b[i].deposit(500.00);
        b[i].display();
        b[i].withdraw(200.00);
        b[i].display();
    }
}