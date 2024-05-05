#include <iostream>
using namespace std;

class Instrument
{
public:
    virtual void play() = 0;
    virtual char *what() = 0;
    virtual void adjust() = 0;
};
class Wind : public Instrument
{
public:
    void play()
    {
        cout << "PLAYING UNDER WIND CLASS : " << endl;
    }

    char *what()
    {
        return "This is the message returned by the what() function.";
    }

    void adjust()
    {
        cout<<"Adjusting under Wind class : "<<endl;
    }
};

class Percussion : public Instrument
{
    
public:
    void play()
    {
        cout << "PLAYING UNDER Percussion CLASS : " << endl;
    }

    char *what()
    {
        return "This is the message returned by the what() function.";
    }

    void adjust()
    {
        cout<<"Adjusting under Percussion class : "<<endl;
    }
};


class Stringed : public Instrument
{
  
public:
    void play()
    {
        cout << "PLAYING UNDER Stringed CLASS : " << endl;
    }

    char *what()
    {
        return "This is the message returned by the what() function.";
    }

    void adjust()
    {
        cout<<"Adjusting under Stringed class : "<<endl;
    }
};

int main()
{
    Instrument *i=new Wind();
    i->play();
    i->adjust();
    cout<<i->what()<<endl;
    delete i;
    Instrument *j=new Percussion();
    j->play();
    j->adjust();
    cout<<j->what()<<endl;
     delete j;

    Instrument *k=new Stringed();
    k->play();
    k->adjust();
    cout<<k->what()<<endl;
    delete k;
}