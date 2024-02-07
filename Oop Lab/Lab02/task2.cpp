#include<iostream>
#include<istream>
using namespace std;

struct Book{
    string title,author,genre;
    int pubYear;
};

void displayBooks(struct Book *books, int n){
    cout<<endl;
    if(n==0)
        cout<<"no books available to show!"<<endl<<endl;
    for(int i=0;i<n;i++)
        cout<<"Title: "<<books[i].title<<endl<<"Author: "<<books[i].author<<endl<<"Publication Year: "<<books[i].pubYear<<endl<<"Genre: "<<books[i].genre<<endl<<endl;
}
void addNew(struct Book*& books, int& n) {
    Book* newBooks = new Book[n + 1];
    for (int i = 0; i < n; i++) {
        newBooks[i] = books[i];
    }
    delete[] books;
    books = newBooks;
    cin.ignore();
    cout << "Enter title: ";
    getline(cin,books[n].title);
    cout << "Enter author: ";
    getline(cin,books[n].author);
    cout << "Enter publication Year: ";
    pyear:
    cin >> books[n].pubYear;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"invalid! Enter publication year again: ";
        goto pyear;
    }
    cin.ignore();
    cout << "Enter genre: ";
    getline(cin,books[n].genre);
    n++;
    displayBooks(books, n);
}
void search(struct Book *books , int n){
    string author;
    int opt,found=0;
    searchOpt:
    cout<<"By \n1. Title\n2. Author\n0. Back\nEnter: ";
    cin>>opt;
    if(cin.fail() || opt<0 || opt>2){
        cin.clear();
        cin.ignore();
        cout<<"Invalid!\n";
        goto searchOpt;
    }
    if(opt==0)
        return;
    cout<<"Enter string to search: ";
    cin>>author;
    for(int i=0;i<n;i++){
        if((opt==1 && books[i].title == author) || (opt==2 && books[i].author == author)){
            cout<<"Title: "<<books[i].title<<endl<<"Author: "<<books[i].author<<endl<<"Publication Year: "<<books[i].pubYear<<endl<<"Genre: "<<books[i].genre<<endl<<endl;
            found = 1;
        }
    }
    if(!found)
        cout<<endl<<"Not found"<<endl<<endl;
}
void modify(struct Book*& books, int n){
    cout<<endl;
    if(n==0){
        cout<<"no books available to show!"<<endl<<endl;
        return;
    }
    for(int i=0;i<n;i++)
        cout<<i+1<<": "<<books[i].title<<endl<<"Author: "<<books[i].author<<endl<<"Publication Year: "<<books[i].pubYear<<endl<<"Genre: "<<books[i].genre<<endl<<endl;
    cout<<"0: Back"<<endl<<endl<<"Enter number: ";
    int num;
    enterNum: 
    cin>>num;
    if(num>n || num<0 || cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"Invalid! Enter number again: ";
        goto enterNum;
    }
    if(num==0)
        return ;
    cout<<endl<<"1. Title\n2. Author\n3. Publication year\n4. Genre\nEnter the field you want to modify: ";
    int op;
    enterOp:
    cin>>op;
    if(cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"Invalid";
        goto enterOp; 
    }
    cin.ignore();
    string modified;
    cout<<"Enter new data: ";
    getline(cin,modified);
    switch(op){
        case 1 :
        books[num-1].title = modified;
        break;
        case 2: 
        books[num-1].author = modified;
        break;
        case 3:
        books[num-1].pubYear = stoi(modified);
        break;
        case 4: 
        books[num-1].genre = modified;
        break;
        default:
        break;
    }
    cout<<"\nModified\n";
    displayBooks(books,n);
}
int main(){
Book *books = new Book[1];
bool cont = true;
int nBooks = 0;
while(cont){
cout<<"1. Display All Books\n2. Search\n3. Add new book\n4. Modify\nEnter your choice: ";
int opt;
mainOp:
cin>>opt;
if(cin.fail()){
    cin.clear();
    cin.ignore();
    cout<<"Invalid! Enter your choice again: ";
    goto mainOp;
}
switch(opt){
    case 1:
        displayBooks(books, nBooks);
        break;
    case 2:
        search(books,nBooks);
        break;
    case 3:
        addNew(books,nBooks);
        break;
    case 4:
        modify(books,nBooks);
        break;
    default:
        cout<<endl<<"Wrong Input!"<<endl<<endl;
        break;
}
}
}