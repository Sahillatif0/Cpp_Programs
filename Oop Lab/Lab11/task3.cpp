#include <iostream>
using namespace std;
class Weapon
{
protected:
    string name;
    int damage;
    float weight;

public:
    Weapon() {}
    Weapon(string n, int d, float w)
    {
        name = n;
        damage = d;
        weight = w;
    }
    virtual void attack() = 0;
    virtual void reload() = 0;
};
class Gun : public Weapon
{
public:
    Gun() {}
    void attack()
    {
        cout << "Attack from Gun" << endl;
        damage -= 10;
    }
    void reload()
    {
        cout << "GUN IS BEING RELOADED: " << endl;
    }
    void shoot()
    {
        cout << "Gun is Shooted" << endl;
    }
};
class Sword : public Weapon
{
public:
    Sword() {}
    void slash()
    {
        cout << "Sword is splashed" << endl;
    }
    void reload()
    {
        cout << "Sword reloaded/changed" << endl;
    }
    void attack()
    {
        cout << "Attack from Sword" << endl;
        damage -= 10;
    }
    void parry()
    {
    }
};
class Bow : public Weapon
{
public:
    void attack()
    {
        cout << "Attack from Bow" << endl;
    }
    void reload()
    {
        cout << "Bow Reloaded" << endl;
    }
};
int main()
{
    Weapon *e = new Gun();
    Weapon *e1 = new Sword();
    e->attack();
    e1->attack();
    e->reload();
    e1->reload();
}