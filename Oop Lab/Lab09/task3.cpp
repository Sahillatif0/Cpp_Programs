#include <iostream>
#include <string>
using namespace std;
class Book {
protected:
     string title;
     string author;
    int publicationYear;
public:
    Book( string title,  string author, int publicationYear)
        : title(title), author(author), publicationYear(publicationYear) {}
    virtual void display() const {
         cout << "Title: " << title << "\n"<< "Author: " << author << "\n"<< "Publication Year: " << publicationYear <<  endl;
    }
};

class ReferenceBook : public Book {
     string topic;
public:
    ReferenceBook( string title,  string author, int publicationYear,  string topic)
        : Book(title, author, publicationYear), topic(topic) {}

    void display() const{
        Book::display();
         cout << "Topic: " << topic <<  endl;
    }
};
int main(){
    Book *b1;
    ReferenceBook rb1("The C++ Programming Language", "Bjarne Stroustrup", 2013, "Programming");
    rb1.display();
    b1 = &rb1;
    cout << endl;
    b1->display();
    return 0;
}