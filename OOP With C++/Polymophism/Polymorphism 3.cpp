//Given one of them shapes -> square , rectangle , circle - > shapes -> common : name , area

class Shape {
    string name;
public:
    string get_name() {
        return name;
    }
    void set_name( string name) {
        string s = name;
    }
    virtual double Area(){return -1 ;} // or throw} statment handeled in case of i actual call Area function in shape class ,, throw because i'm don't know shape to determine its area
    virtual double Perimeter(){return -1 ;}
    virtual ~Shape(){};
};

class Square : public Shape {
    int length;
public:
    Square(int _length) : length(_length) {
        set_name("Square");
    }
    double Area() {
        return length * length;
    }
};

class Rectangle : public Shape {
    int width , height;
public:
    Rectangle(int _width , int _height) : width(_width), height(_height) {
        set_name("Rectangle");
    }
    double Area() {
        return width * height;
    }
};

class Circle : public Shape {
    int radius;
public:
    Circle(int _radius) : radius(_radius) {
        set_name("Circle");
    }

    double Area() {
        return PI * radius * radius;
    }
};

void calcArea(Shape *shape) {
    cout << shape->get_name() << ' ' << shape->Area() << endl;
}

int main(){
    Rectangle rect(10 , 20);
    Circle circle(5);
    Square square(4);

    calcArea(&rect);
    calcArea(&square);
    calcArea(&circle);
}