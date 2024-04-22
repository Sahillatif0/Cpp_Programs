#include <iostream>
#include <string>
using namespace std;
class Movie {
    string title, genre, director;
public:
    void setMovieInfo(const string& title, const string& genre, const string& director) {
        this->title = title;
        this->genre = genre;
        this->director = director;
    }

    friend ostream& operator<<(ostream& os, const Movie& movie) {
        os << "Title: " << movie.title << ", Genre: " << movie.genre << ", Director: " << movie.director;
        return os;
    }

    friend class Rental;
};

class Customer {
    int customerID;
    string customerName;

public:
    void setCustomerInfo(int customerID, const string& customerName) {
        this->customerID = customerID;
        this->customerName = customerName;
    }
    friend ostream& operator<<(ostream& os, const Customer& customer) {
        os << "Customer ID: " << customer.customerID << ", Name: " << customer.customerName;
        return os;
    }

    friend class Rental;
};

class Rental {
    Movie movie;
    Customer customer;
public:
    void setRentalInfo(const Movie& movie, const Customer& customer) {
        this->movie = movie;
        this->customer = customer;
    }

    friend ostream& operator<<(ostream& os, const Rental& rental) {
        os << "Rental Info:\n" << rental.movie << "\n" << rental.customer;
        return os;
    }
};
int main(){
    Movie movie1;
    Movie movie2;
    movie2.setMovieInfo("The Dark Knight", "Action", "Christopher Nolan");
    Customer customer2;
    customer2.setCustomerInfo(2, "Jane Doe");
    Rental rental2;
    rental2.setRentalInfo(movie2, customer2);
    cout << rental2 << endl;
    movie1.setMovieInfo("Inception", "Sci-Fi", "Christopher Nolan");
    Customer customer1;
    customer1.setCustomerInfo(1, "John Doe");
    Rental rental1;
    rental1.setRentalInfo(movie1, customer1);
    cout << rental1 << endl;
}