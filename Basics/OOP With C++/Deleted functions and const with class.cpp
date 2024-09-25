//Deleted functions and const with class
/*
 * Delete function:
 * We can easily delete a specific functions:
 * Copy constructork
 * Assignment operator
 * Normal member functions (e.g. to prevent conversion)
 * Explicit constructor to prevent conversion
 *
 * Const:
 * By makeing more const as function , you reduce the error that might be done
 * */
#include <iostream>
using namespace std;

class Rectangle{
private:
    double width , height;
    const int area = 10 ; // initialized
    const int cur; // initialize this with initilizer list in constructor
public:
    //note use one method only for default constructor
    Rectangle() : cur(6) {};
    Rectangle(double _width , double _height): width(_width) , height(_height) , cur(6) { /*cur = 6  CE , must use initializer list*/} // if we assign parameters with default values -> CE (remove above default constructor)
    Rectangle(const Rectangle & another) = delete;
    int computeArea() const {
        //width = 1 ; CE , function is const , can`t change member variable
        return width * height;
    }
    double computeArea(double n) = delete;

    //Getters
    double getHeight()const{
        return height;
    }
    void set(int n , int m){
        width = n , height = m;
    }
};

int main(){
    Rectangle r(2, 4);
//    Rectangle r1 (r); //CE because the copy constructor is deleted
//    r.computeArea(1.2); //CE
    r.set(4 , 5);
    cout << r.getHeight() << '\n';

    const Rectangle r2;
//    r2.set(4 , 5); // CE because this non-const function
    cout << r2.getHeight() << '\n';
//------------------------------------------------------------------------
// Const and Pointers:-
    Rectangle r3(2 , 3); // normal object
    const Rectangle* r4 = new Rectangle(3, 4); // const object but pointer is non-const
    //r4.set(4 ,5); // CE
    r4 = & r;

    Rectangle* const r5 = new Rectangle(4 , 5); // non-const object but const pointer
    r5->set(4 ,5);
//    r5 = & r; // CE

    const Rectangle* const r6 = new Rectangle(4 , 3); // const object and const pointer
//    r6->set(4 ,5); // CE
//    r6 = & r; // CE
}