#include <string>
#include <iostream>
using namespace std;
class Animal {
protected:
    string name;
    int age;
public:
    Animal(string name, int age) : name(name), age(age) {
        cout << "Animal constructor called" << endl;
    }
    ~Animal() {
        cout << "Animal destructor called" << endl;
    }

    void eat() {
        cout << "Animal is eating" << endl;
    }
    void sleep() {
        cout << "Animal is sleeping" << endl;
    }

};

class Mammal : public Animal {
protected:
    string furColor;
public:
    Mammal(string name, int age, string furColor) : Animal(name, age), furColor(furColor) {
        cout<<"Mammal constructor called"<<endl;
    }
    ~Mammal() {
        cout<<"Mammal destructor called"<<endl;
    }
    void giveBirth() {
        cout<<"Mammal is giving birth"<<endl;
    }

};

class Bird : public Animal {
protected:
    int wingSpan;
public:
    Bird(string name, int age, int wingSpan) : Animal(name, age), wingSpan(wingSpan) {
        cout<<"Bird constructor called"<<endl;
    }
    ~Bird() {
        cout<<"Bird destructor called"<<endl;
    }

    void layEggs() {
        cout<<"Bird is laying eggs"<<endl;
    }

};

class Bat : public Mammal, public Bird {
private:
    bool echolocationCapability;
public:
    Bat(string name, int age, string furColor, int wingSpan, bool echolocationCapability)
        : Mammal(name, age, furColor), Bird(name, age, wingSpan), echolocationCapability(echolocationCapability) {
        cout<<"Bat constructor called"<<endl;
        }
      ~Bat() {
        cout<<"Bat destructor called"<<endl;
      }

    void fly() {
        cout<<"Bat is flying"<<endl;
    }

};

class Reptile : public Animal {
public:
    Reptile(string name, int age) : Animal(name, age) {
        cout<<"Reptile constructor called"<<endl;
    }
      ~Reptile() {
        cout<<"Reptile destructor called"<<endl;
      }
};

class Snake : public Reptile {
private:
    bool venomous;
public:
    Snake(string name, int age, bool venomous) : Reptile(name, age), venomous(venomous) {
        cout<<"Snake constructor called"<<endl;
    }
      ~Snake() {
        cout<<"Snake destructor called"<<endl;
      }

    void shedSkin() {
        cout<<"Snake is shedding skin"<<endl;
    }

};

class Sparrow : public Bird {
public:
    Sparrow(string name, int age, int wingSpan) : Bird(name, age, wingSpan) {
        cout<<"Sparrow constructor called"<<endl;
    }
      ~Sparrow() {
        cout<<"Sparrow destructor called"<<endl;
      }
};

class Penguin : public Bird {
public:
    Penguin(string name, int age, int wingSpan) : Bird(name, age, wingSpan) {
        cout<<"Penguin constructor called"<<endl;
    }
      ~Penguin() {
        cout<<"Penguin destructor called"<<endl;
      }
};

int main() {
    Animal animal("Generic Animal", 5);
    animal.eat();
    animal.sleep();

    Mammal mammal("Generic Mammal", 3, "Brown");
    mammal.eat();
    mammal.sleep();
    mammal.giveBirth();

    Bird bird("Generic Bird", 2, 10);
    bird.eat();
    bird.sleep();
    bird.layEggs();

    Bat bat("Bat", 1, "Black", 15, true);
    bat.Mammal::eat();
    bat.Mammal::sleep();
    bat.giveBirth();
    bat.layEggs();
    bat.fly();

    Reptile reptile("Generic Reptile", 4);
    reptile.eat();
    reptile.sleep();

    Snake snake("Snake", 2, true);
    snake.eat();
    snake.sleep();
    snake.shedSkin();

    Sparrow sparrow("Sparrow", 1, 5);
    sparrow.eat();
    sparrow.sleep();
    sparrow.layEggs();

    Penguin penguin("Penguin", 3, 8);
    penguin.eat();
    penguin.sleep();
    penguin.layEggs();

    return 0;
}