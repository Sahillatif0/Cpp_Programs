#include<iostream>
using namespace std;

class Shop{
    string *items;
    float *prices;
    int totalItems;
    public:
        Shop(){
            totalItems = 0;
            items = new string[totalItems+1];
            prices = new float[totalItems+1];
        }
        void addItem(string itemName, float itemPrice){
            totalItems++;
            string* newItems = new string[totalItems];
            float* newPrices = new float[totalItems];
            for (int i = 0; i < totalItems-1; i++) {
                newItems[i] = items[i];
                newPrices[i] = prices[i];
            }
            delete[] items;
            delete[] prices;
            items = newItems;
            prices = newPrices;
            items[totalItems-1] = itemName;
            prices[totalItems-1] = itemPrice;
            cout<<"Item Added"<<endl;
        }

        string* fetchItems(int &n){
            n = totalItems;
            return items;
        }

        void editPrice(string itemName, float newPrice){
            bool found = false;
            for(int i=0;i<totalItems;i++)
                if(itemName==items[i]){
                    prices[i] = newPrice;
                    found = true;
                }
            if(!found)
                cout<<"No item found with this name"<<endl;
            else
                cout<<"Edited Price"<<endl;
        }

        void viewItems(){
            if(totalItems<1)
                cout<<"No item available!"<<endl;
            for(int i=0;i<totalItems;i++)
                cout<<"Item #"<<i+1<<endl<<"Name: "<<items[i]<<endl<<"Price: Rs. "<<prices[i]<<endl<<endl<<endl;
            cout<<"Total Items: "<<totalItems<<endl<<endl;
        }
        void showReceipt(){
            int boughtItems;
            cout<<"Enter bought Items Number: ";
            cin>>boughtItems;
            string bItems[boughtItems], itm;
            int quantity[boughtItems], quant=0;
            float totalBill = 0;
            for(int i=0;i<boughtItems;i++){
                cout<<"Enter item#"<<i+1<< " name: ";
                cin.ignore();
                getline(cin,bItems[i]);
                cout<<"Enter quantity: ";
                cin>>quantity[i];
            }
            cout<<"\tCUSTOMER RECEIPT"<<endl;
            cout<<"Item#\tItem Name\tQuantity\tPrice(item)\tTotal\n";
            for(int i=0;i<boughtItems;i++){
                int ind=-1;
                for(int j=0;j<totalItems;j++)
                    if(items[j]==bItems[i]){
                        ind = j;
                        break;
                    }
                if(ind!=-1){
                    float total = (quantity[i]*prices[ind]);
                    totalBill+=total;
                    quant+=quantity[i];
                    cout<<i+1<<"\t"<<items[ind]<<"\t\t"<<quantity[i]<<"\t\tRs. "<<prices[ind]<<"\tRs. "<<total<<endl;
                }

            }
            cout<<"\n\t\tTotal: "<<quant<<"\t\tTotal Bill: Rs. "<<totalBill<<endl;
        }

};

int main(){
    Shop s;
    int opt;
    float price;
    string item;
    string *items;
    int totalItems;
    while (1)
    {
    cout<<"1. View Items\n2. Add Item\n3. Edit Item Price\n4. Fetch Items\n5. Make Receipt\n6. Exit\nEnter Option: ";
    cin>>opt;
    cin.ignore();
    switch (opt)
    {
    case 1:
        s.viewItems();
        break;
    case 2:
        cout<<"Enter the name of the item: ";
        getline(cin,item);
        cout<<"Enter the price of item: ";
        cin>>price;
        s.addItem(item,price);
        break;
    
    case 3:
        cout<<"Enter the name of the item: ";
        getline(cin,item);
        cout<<"Enter the new price for item: ";
        cin>>price;
        s.editPrice(item,price);
        break;
    case 4:
        items = s.fetchItems(totalItems);
        break;
    case 5:
        s.showReceipt();
        break;
    case 6:
        return 1;
        break;
    default:
        cout<<"Invalid input"<<endl;
        break;
    }
    }
}