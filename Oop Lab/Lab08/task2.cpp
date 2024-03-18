#include <iostream>
#include <string>
using namespace std;
class Marks {
protected:
    static int students;
    int rollNo;
    string name;
    int marks;

public:
    Marks(){};
    Marks(string name, int marks) : name(name), marks(marks),rollNo(students++) {}

    int getMarks() const {
        return marks;
    }
    string getName() const {
        return name;
    }
};

int Marks::students = 1;

class Physics : public Marks {
public:
    Physics(){}
    Physics(string name, int marks) : Marks(name, marks) {}
};

class Chemistry : public Marks {
public:
    Chemistry(){}
    Chemistry(string name, int marks) : Marks(name, marks) {}
};

class Mathematics : public Marks {
public:
    Mathematics(){}
    Mathematics(string name, int marks) : Marks(name, marks) {}
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    Physics physicsStds[n];
    Chemistry chemistryStds[n];
    Mathematics mathStds[n];

    int StdtotMarks[n], totalStdMarks = 0;
    for(int i=0;i<n;i++){
        string name;
        int marks;
        cout << "Enter name of student " << i+1 << ": ";
        cin >> name;
        cout << "Enter marks in Physics: ";
        cin >> marks;
        physicsStds[i] = Physics(name, marks);
        cout << "Enter marks in Chemistry: ";
        cin >> marks;
        chemistryStds[i] = Chemistry(name, marks);
        cout << "Enter marks in Mathematics: ";
        cin >> marks;
        mathStds[i] = Mathematics(name, marks);
        StdtotMarks[i] = physicsStds[i].getMarks() + chemistryStds[i].getMarks() + mathStds[i].getMarks();
        totalStdMarks += StdtotMarks[i];
    }
    for(int i=0;i<n;i++){
        cout << "Total marks of " << physicsStds[i].getName() << ": " << StdtotMarks[i] << endl;
    }
    cout<<"Average marks of all students: "<<double(totalStdMarks)/n<<endl;
    return 0;
}