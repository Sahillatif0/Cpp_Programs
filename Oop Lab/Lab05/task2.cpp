#include<iostream>

using namespace std;

class LoanHelper{
    const float interestRate;
    float loan;
    int months;
    public:
    LoanHelper(float IR, float l,int m) :interestRate(IR),loan(l),months(m){}
    void loanRepay(){
        float MonthlyRepay = loan/months + (loan*interestRate)/(12*100);
        cout<<"You have to pay "<<MonthlyRepay<<" every month for "<< months<<endl;
    }
    void setLoan(float l) {loan=l;}
    void setMonths(int m){months = m;}
    float getIR(){return interestRate;}
    float getLoan(){return loan;}
    int getMonths(){return months;}

};
int main(){
    float IR,loan;
    int months;
    do{
    cout << "Enter the Interest Rate: ";
    cin>>IR;
    }while(IR<0.0 || IR>0.5);
    cout<<"Loan Amount: ";
    cin>>loan;
    cout<<"Months: ";
    cin>>months;
    LoanHelper lh(IR,loan,months);
    lh.loanRepay();
}