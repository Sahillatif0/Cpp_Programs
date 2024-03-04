#include<iostream>
using namespace std;

class Course{
    string code;
    int creditHours;
    public:
        string name;
        Course(){};
        Course(string c, string n, int ch): code(c), name(n), creditHours(ch){}
        string getCode() const {return code;}
        int getCreditHours() const {return creditHours;}
        void setCode(string c) {code = c;}
        void setCreditHours(int ch) {creditHours = ch;}
        void display() const {
            cout<<"Course Code: "<<code<<endl;
            cout<<"Course Name: "<<name<<endl;
            cout<<"Credit Hours: "<<creditHours<<endl;
        }
};

class Student{
    const string id;
    Course *courses;
    int numOfCourses;
    public:
        string name;
        Student(string i, string n): id(i), name(n), numOfCourses(0){}
        ~Student(){
            delete[] courses;
        }
        void printEnrolledCourses() const {
            cout<<"Student ID: "<<id<<endl;
            cout<<"Student Name: "<<name<<endl;
            cout<<"Number of Courses: "<<numOfCourses<<endl;
            cout<<"Courses: "<<endl;
            for(int i=0; i<numOfCourses; i++)
                courses[i].display();
        }
        void enroll(Course c){
            Course *temp = new Course[numOfCourses+1];
            for(int i=0; i<numOfCourses; i++)
                temp[i] = courses[i];
            temp[numOfCourses++] = c;
            courses = temp;
        }
        void drop(Course c){
            Course *temp = new Course[numOfCourses-1];
            int j=0;
            for(int i=0; i<numOfCourses; i++)
                if(courses[i].getCode()!=c.getCode())
                    temp[j++] = courses[i];
            numOfCourses--;
            courses = temp;
        }
        int getTotalCreditHours(){
            int total = 0;
            for(int i=0; i<numOfCourses; i++)
                total+=courses[i].getCreditHours();
            return total;
        }

        void updateCourses(Course *c, int noc){
            delete[] courses;
            numOfCourses = noc;
            courses = new Course[numOfCourses];
            for(int i=0; i<numOfCourses; i++)
                courses[i] = c[i];
        }
        string getStudentId() const {return id;}
        int getNumOfCourses() const {return numOfCourses;}
        Course* getCourses() const {return courses;}
};

int main() {
    Student s1("23i-0763", "Sahil Latif");
    Course c1("CS101", "Programming Fundamentals", 3);
    s1.enroll(c1);
    Course c2("CS102", "Object Oriented Programming", 3);
    s1.enroll(c2);
    Course c3("CS103", "Functional English", 2);
    s1.enroll(c3);
    s1.printEnrolledCourses();
    cout<<"Total Credit Hours: "<<s1.getTotalCreditHours();
    s1.drop(c1);
    cout<<"\n\nAfter dropping CS101\n";
    s1.printEnrolledCourses();
    cout<<"Total Credit Hours: "<<s1.getTotalCreditHours();
}