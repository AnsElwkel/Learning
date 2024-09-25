#include <iostream>
#include <vector>
#include <sstream>

class Point {
public:
    Point(double X , double Y) : X(X), Y(Y) {}
    double get_X() const { return X; }
    double get_Y() const { return Y; }
    void set_X(double X) { this->X = X; }
    void set_Y(double Y) { this->Y = Y; }
    std::string to_string() const {
        std::ostringstream oss;
        oss << "Point(" << X << ", " << Y << ")";
        return oss.str();
    }
private:
    double X , Y;
};

class Shape {
public:
    Shape(int color) : color(color) {}

    virtual double compute_area() const {
        throw std::runtime_error("Shape computation not implemented");
        return 0.0;
    }
    virtual Shape* clone() const {
        throw std::runtime_error("Shape clone not implemented");
        return nullptr;
    }

    virtual void draw() const {
        std::cout << "drawing shape of area : " << compute_area() /*call child function*/<< std::endl;
    }

    virtual ~Shape() {}

protected:
    int color;
};


class Rectangle : public Shape {
public :

    Rectangle(int color ,const Point& p1 ,const Point& p2)
        : Shape(color) , top_left(p1) , bottom_right(p2) {}

    virtual double compute_area() const override{
        return 10;
    }
    virtual void draw() const override{
        Shape::draw();
        std::cout << "Top left : " << top_left.to_string() <<std::endl << "BT: " << top_left.to_string() << std::endl;
    }
    virtual Rectangle* clone() const{ // like a copy constructor
        return new Rectangle(*this);
    }

    ~Rectangle(){}
private:
    Point top_left , bottom_right;
};

class Circle : public Shape {
    public :
    Circle(int color ,const Point& p1)
        : Shape(color) , center(p1)  {}

    virtual double compute_area() const override{
        return 20;
    }
    virtual void draw() const override{
        Shape::draw();
        std::cout << "Top left : " <<center.to_string() <<std::endl;
    }

    //this function to avoid the temp pointer possible deleted and make errors just make a copy object
    virtual Circle* clone() const{ // like a copy constructor
        return new Circle(*this);
    }

    ~Circle(){}

private:
    Point center;
};

class ImageEditor {
protected:
    std::vector<Shape*> shapes_;

public:
    void addShape(Shape* shape) {
        shapes_.push_back(shape->clone());//copy object that safe
    }

    void draw() {
        for(auto &shape : shapes_) {
            shape->draw();
        }
    }

    ~ImageEditor() {
        for(auto &shape : shapes_) {
            delete shape;
        }
        shapes_.clear();
    }
};

int main() {
    ImageEditor img_editor;
    Circle* c1 = new Circle(5, Point(5, 5));
    Rectangle* r1 = new Rectangle(5, Point(5, 5) , Point(5, 5));
    img_editor.addShape(c1->clone()); ;
    img_editor.addShape(r1->clone()); ;

    img_editor.draw();

};


/**
●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●
●●●●●●●●●●●●●●●●●●●●●●●● Potential polymorphism ●●●●●●●●●●●●●●●●●●●●●●●●●●●
●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●
● In a site: User could be Customer or Admin
● In parking: Vehicle could be car, truck or motor, each with needed spots
● In parking: Parking permit is for student or faculty staff or visitor
● In payment: card can be credit, debit or prepaid
● Modeling Customers: Individual vs Corporate customer
● Expieda.com: Reservation could flight, car, hotel or itinerary
● In a game: Monster could be FireMonster, WaterMonster or StoneMonster
● In a game: a Player can be escaper or catcher
● Modelling some stadium: Soccer Player. Baseball Player
●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●
 */