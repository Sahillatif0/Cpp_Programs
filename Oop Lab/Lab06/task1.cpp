#include<iostream>
using namespace std;

class BankAccount{
    int accountId;
    double balance;
    int* transactionHistory;
    int numTransactions;
    public:
        BankAccount(int id, double bal, int* trx, int numTrx): accountId(id), balance(bal), numTransactions(numTrx) {
            transactionHistory = new int[numTrx];
            for(int i=0; i<numTrx; i++)
                transactionHistory[i] = trx[i];
        }
        BankAccount(const BankAccount& b): accountId(b.accountId), balance(b.balance), numTransactions(b.numTransactions){
            transactionHistory = new int[numTransactions];
            for(int i=0; i<numTransactions; i++)
                transactionHistory[i] = b.transactionHistory[i];
        }
        ~BankAccount(){
            delete[] transactionHistory;
        }
        void display(){
            cout<<"Account ID: "<<accountId<<endl;
            cout<<"Balance: "<<balance<<endl;
            cout<<"Transaction History (Size="<<numTransactions<<"): ";
            for(int i=0; i<numTransactions; i++)
                cout<<transactionHistory[i]<<" ";
            cout<<endl;
        }
        void updateTransactionHistory(int *trx, int numTrx){
            delete[] transactionHistory;
            numTransactions = numTrx;
            transactionHistory = new int[numTransactions];
            for(int i=0; i<numTransactions; i++)
                transactionHistory[i] = trx[i];
        }


};

int main() {
    int trx[] = {12,15,20,130};
    BankAccount b1(1, 1000, trx, 4);
    BankAccount b2(b1);
    cout<<"Original Account"<<endl;
    b1.display();
    cout<<"Copied Account"<<endl;
    b2.display();
    int trx2[] = {124,21,23,63,21};
    b1.updateTransactionHistory(trx2,5);
    cout<<"Original Account after update"<<endl;
    b1.display();
    cout<<"After updating original account, details of copied account\n";
    b2.display();

}