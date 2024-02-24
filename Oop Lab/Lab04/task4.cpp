#include<iostream>
using namespace std;

class Stock{
    string tickerSymbol, Company;
    float openingPrice, closingPrice, currentPrice;
    public:
        Stock():tickerSymbol("XRP"),Company("Binance"), openingPrice(2.5), closingPrice(3.1), currentPrice(2.75){

        }
        void calculate_loss_profit(){
            float loss_profit = currentPrice - openingPrice;
            if(loss_profit<0)
                cout<<"Loss: "<<loss_profit<<endl;
            else
                cout<<"Profit: "<<loss_profit<<endl;
        }
        void reset_prices(){
            currentPrice = 0;
            openingPrice = 0;
            closingPrice = 0;
            cout<<"Successfully Reseted"<<endl;
        }
        Stock(Stock &o){
            tickerSymbol = o.tickerSymbol;
            Company = o.Company;
            openingPrice = o.openingPrice;
            closingPrice = o.closingPrice;
            currentPrice = o.currentPrice;
        }
};

int main(){
    Stock a,b;
    a.calculate_loss_profit();
    a.reset_prices();
    a.calculate_loss_profit();
    Stock c(b);
    c.calculate_loss_profit();

}