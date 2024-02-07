#include <iostream>
#include<time.h>
using namespace std;

struct Product{
    int Id;
    string name;
    float price;
    int quantity;

};

int genUniqId(struct Product *products, int size){
    int found = 0;
    while(1){
    int id = rand()%100000 + 100000;
    for(int i=0 ;i<size;i++)
        if(id==products[i].Id){
            found=1;
            break;
        }
    if(!found)
        return id;
    }
}

void addProduct(string name, float price, int quantity, struct Product*& products,int &n){
    struct Product* newProducts = new struct Product[n + 1];
    for (int i = 0; i < n; i++) {
        newProducts[i] = products[i];
    }
    delete[] products;
    products = newProducts;
    products[n].Id = genUniqId(products,n);
    products[n].name = name;
    products[n].price = price;
    products[n].quantity = quantity;
    n++;
    cout<<endl<<"Product Added"<<endl;
}
int displayProduct(struct Product *products, int id, int n){
    int found = 0;
    for(int i=0;i<n;i++){
        if(products[i].Id == id){
            found = 1;
            cout << "ID: " << products[i].Id << endl;
            cout << "Name: " << products[i].name << endl;
            cout << "Price: " << products[i].price << "$\tQuantity:" << products[i].quantity << endl;
        }
    }
    if(!found)
        cout<<endl<<"No product found with id: "<<id<<endl;
    return found;
}
void displayAllProduct(struct Product *products,int n){
    if(n==0){
        cout<<endl<<"No products available to show!"<<endl;
        return;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout << "ID: " << products[i].Id << endl;
        cout << "Name: " << products[i].name << endl;
        cout << "Price: " << products[i].price << "$\tQuantity:" << products[i].quantity << endl<<endl;
    }
}
void modifyProduct(string name, float price, int quantity, struct Product*& products,int &n, int id){
    int found = 0;
    for(int i=0;i<n;i++){
        if(products[i].Id == id){
            found = 1;
            products[i].name = name;
            products[i].price = price;
            products[i].quantity = quantity;
            cout<<endl<<"Product Modified"<<endl;
        }
    }
    if(!found)
        cout<<"Product not found with id = "<<id<<endl;
}
void deleteProduct(struct Product*& products, int id, int &n){
    int found = 0;
    for(int i=0;i<n;i++){
        if(products[i].Id == id){
            found = 1;
            for(int j = i;j<n-1;j++)
                products[j] = products[j+1];
            n--;
            cout<<endl<<"Product Deleted"<<endl;
        }
    }
    if(!found)
        cout<<"Product not found with id = "<<id<<endl;
}
int main(){
    srand(time(0));
    struct Product *products = new Product[1];
    int n = 0; 
    string name;
    float price;
    int quantity,Id;
    while (true) {
        char choice;
	    cout << "\nMenu:\n";
	    cout << "A. Add a product.\nB. Display all products.\nC. Search for a product by ID.\nD. Modify a product.\nE. Delete\nEnter Your Choice: ";
        cin>>choice;
        cin.ignore();
        switch (choice)
        {
        case 'A':
            cout<<"Enter product name: ";
            getline(cin,name);
            cout<<"Enter product price: ";
            cin>>price;
            cout<<"Enter product quantity: ";
            cin>>quantity;
            addProduct(name,price,quantity,products,n);
            break;
        case 'B':
            displayAllProduct(products,n);
            break;
        case 'C':
            cout<<"Enter the ID of the product you want to search: ";
            int Id;
            cin>>Id;
            displayProduct(products,Id,n);
            break;
        case 'D':
            cout<<"Enter the ID of the product you want to modify: ";
            cin>>Id;
            cin.ignore();
            cout<<endl<<"Previous data: "<<endl;
            if(displayProduct(products,Id,n)){
                cout<<"Enter new product name: ";
                getline(cin,name);
                cout<<"Enter new product price: ";
                cin>>price;
                cout<<"Enter new product quantity: ";
                cin>>quantity;
                modifyProduct(name,price,quantity,products,n,Id);
            }
            break;
        case 'E':
            cout<<"Enter the ID of the product you want to delete: ";
            cin>>Id;
            deleteProduct(products,Id,n);
            break;
        default:
            break;
        }
    }
}