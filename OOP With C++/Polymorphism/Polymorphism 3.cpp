//Given one of them shapes -> square , rectangle , circle - > shapes -> common : name , area
#include <iostream>
using namespace std;
const int PI = 3.14159265358979323846;
class Shape {
    std::string name;
public:
    Shape(std::string name) :
            name(name) {}

    std::string getName() {
        return name;
    }
    virtual double Area(){return -1 ;} // or throw} statment handeled in case of i actual call Area function in shape class ,, throw because i'm don't know shape to determine its area
    virtual double Perimeter(){return -1 ;}
    virtual ~Shape(){};
};

class Square : public Shape {
    int length;
public:
    Square(int _length) :Shape("Square"), length(_length) {}
    double Area() {
        return length * length;
    }
};

class Rectangle : public Shape {
    int width , height;
public:
    Rectangle(int _width , int _height) : Shape("Rectangle"), width(_width), height(_height) {}
    double Area() {
        return width * height;
    }
};

class Circle : public Shape {
    int radius;
public:
    Circle(int _radius) : Shape("Circle"), radius(_radius) {

    }

    double Area() {
        return PI * radius * radius;
    }
};

void calcArea(Shape *shape) {
    cout << shape->getName() << ' ' << shape->Area() << endl;
}

int main(){
    Rectangle rect(10 , 20);
    Circle circle(5);
    Square square(4);

    calcArea(new Rectangle(10 , 20));
    calcArea(&square);
    calcArea(&circle);
}