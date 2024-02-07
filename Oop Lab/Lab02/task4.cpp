#include<iostream>
using namespace std;

struct Register{
    int courseId;
    string courseName;
};
struct Student{
    int studentId;
    string firstName,lastName,cellNo,email;
    struct Register courses;
};
int main(){
    struct Student std[5];
    for(int i=0;i<5;i++){
        cout<<"Enter Student "<<i+1<<" Details: "<<endl;
        cout<<"StudentId: ";
        cin>>std[i].studentId;
        cout<<"FirstName: ";
        cin>>std[i].firstName;
        cout<<"LastName: ";
        cin>>std[i].lastName;
        cout<<"CellNo: ";
        cin>>std[i].cellNo;
        cout<<"Email: ";
        cin>>std[i].email;
        cout<<"CourseId: ";
        cin>>std[i].courses.courseId;
        cout<<"Course Name: ";
        cin>>std[i].courses.courseName;
        cout<<endl<<endl;
    }
    for(int i=0;i<5;i++){
        cout<<"Student "<<i+1<<" Details: "<<endl;
        cout<<"StudentId: "<<std[i].studentId<<endl;
        cout<<"FirstName: "<<std[i].firstName<<endl;
        cout<<"LastName: "<<std[i].lastName<<endl;
        cout<<"CellNo: "<<std[i].cellNo<<endl;
        cout<<"Email: "<<std[i].email<<endl;
        cout<<"CourseId: "<<std[i].courses.courseId<<endl;
        cout<<"Course Name: "<<std[i].courses.courseName<<endl;
        cout<<endl<<endl;
    }

}