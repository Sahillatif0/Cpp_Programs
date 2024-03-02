#include<iostream>
using namespace std;

class Square{
    float sideLength, area;
    static float allareas;
    public:
        Square(){
            sideLength = 0.0;
            area = 0.0;
        }
        Square(const float sl){
            sideLength = sl;
            area = 0.0;
        }
        static void setAllareas(const float a){allareas=a;}
        void setSideLength(const float s) {sideLength=s;}
        float getSideLength() const {return sideLength;}
        void calculateArea(){
            area = sideLength*sideLength;
            Square::addArea(area);
        }
        static void addArea(float a){allareas+=a;}
        float getArea(){ return area; }
        static float getAllAreas(){ return allareas; }

};
float  Square::allareas = 0.0;
int main(){
Square  sq1(5),sq2(7),sq3(9);
sq1.calculateArea();
cout << "The square with side length "<<sq1.getSideLength()<<" has an area of "<<sq1.getArea()<<" and total area = "<<Square::getAllAreas()<<endl;
sq2.calculateArea();
cout << "The square with side length "<<sq2.getSideLength()<<" has an area of "<<sq2.getArea()<<" and total area = "<<Square::getAllAreas()<<endl;
sq3.calculateArea();
cout << "The square with side length "<<sq3.getSideLength()<<" has an area of "<<sq3.getArea()<<" and total area = "<<Square::getAllAreas()<<endl;
}