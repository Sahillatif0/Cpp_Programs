#include <iostream>
using namespace std;
template<class T>
class Pet{
    T name;
    T age;
    public:
        Pet(T name,T age): name(name), age(age){}
        virtual void makeSound()=0;
        void printinfo(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
};
template<class T>
class Cat:public Pet<T>{
    public:
    Cat(T name,T age):Pet<T>(name,age){}
    void makeSound(){
        cout<<"Meow"<<endl;
    }
};
template<typename T>
class Dog:public Pet<T>{
    public:
    Dog(T name,T age):Pet<T>(name,age){}
    void makeSound(){
        cout<<"Woof"<<endl;
    }
};
template<typename T>
class Bird:public Pet<T>{
    public:
    Bird(T name,T age):Pet<T>(name,age){}
    void makeSound(){
        cout<<"Chirp"<<endl;
    }
};
int main(){
    cout<<"=============================="<<endl
        <<"|   Sahil Latif <23I0763>     |"<<endl
        <<"=============================="<<endl<<endl;
    Cat<string> cat("Tom","3");
    Dog<string> dog("Brainy","5");
    Bird<string> bird("Sky","2");
    cat.printinfo();
    cat.makeSound();
    dog.printinfo();
    dog.makeSound();
    bird.printinfo();
    bird.makeSound();
}