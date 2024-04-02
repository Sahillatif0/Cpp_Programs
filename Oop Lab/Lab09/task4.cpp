#include <iostream>
using namespace std;
class Enemy {
public:
    virtual void attack() {
        cout << "The enemy attacks!" << endl;
    }
};

class Dragon : public Enemy {
public:
    void attack()  {
        cout << "The dragon breathes fire!" << endl;
    }
};

class Goblin : public Enemy {
public:
    void attack()  {
        cout << "The goblin swings a club!" << endl;
    }
};

class Troll : public Enemy {
public:
    void attack()  {
        cout << "The troll throws a rock!" << endl;
    }
};

int main() {
    Enemy* enemies[3];
    enemies[0] = new Dragon();
    enemies[1] = new Goblin();
    enemies[2] = new Troll();

    for (int i = 0; i < 3; i++) {
        enemies[i]->attack();
    }
    for (int i = 0; i < 3; i++) {
        delete enemies[i];
    }

    return 0;
}