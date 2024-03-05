#include <iostream>
using namespace std;

class Book{
    protected:
    string title, author,publisher;
    public:
        Book(string t="", string a="", string p=""):title(t),author(a),publisher(p){}
        void display(){
            cout<<"Book Details: "<<endl;
            cout<<"Title: "<<title<<endl;
            cout<<"Author: "<<author<<endl;
            cout<<"Publisher: "<<publisher<<endl;
        }
};
class FictionBook:public Book{
    string genre, protagonist;
    public:
        FictionBook(string t="", string a="", string p="", string g="", string prot=""):Book(t,a,p), genre(g),protagonist(prot){}
        void display(){
            cout<<"Book Details: "<<endl;
            cout<<"Title: "<<title<<endl;
            cout<<"Author: "<<author<<endl;
            cout<<"Publisher: "<<publisher<<endl;
            cout<<"Genre: "<<genre<<endl;
            cout<<"Protagonist: "<<protagonist<<endl;
        }
};
int main(){
    FictionBook fb("Unknown Book", "Newton", "Einstein", "Destruction", "Apple");
    fb.display();

}