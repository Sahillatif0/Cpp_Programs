#include <iostream>
using namespace std;

class Person{
    protected:
        string name;
        int age;
    public: 
        Person(string n, int a): name(n), age(a){}
};
class Student: public Person{
    protected: 
        string studentID, gradeLvl;
    public: 
        Student(string n, int a, string Id, string gL):Person(n,a),studentID(Id),gradeLvl(gL){}
};
class Teacher: public Person{
    protected:
        string subject;
        int room;
    public:
        Teacher(string n, int a, string s, int r):Person(n,a),subject(s),room(r){}

};
class GraduateStudent: public Student, public Teacher{
    public:
        GraduateStudent(string n, int a, string s, int r,  string Id, string gL): Student(n,a,Id,gL), Teacher(n,a,s,r){}
        void display(){
            cout<<"Details: "<<endl;
            cout<<"Name: "<<Student::name<<endl;
            cout<<"Age: "<<Student::age<<endl;
            cout<<"Subject: "<<subject<<endl;
            cout<<"Room: "<<room<<endl;
            cout<<"Student Id: "<<studentID<<endl;
            cout<<"Grade Lvl: "<<gradeLvl<<endl; 
        }
};

int main(){
    Person p("person1", 24);
    Student s("Sahil", 18,"23I-0763", "A");
    Teacher t("Basit", 36, "OOP", 6);
    GraduateStudent ga("Kashif", 25,"PF", 2, "18k-8373", "A");
    ga.display();
}