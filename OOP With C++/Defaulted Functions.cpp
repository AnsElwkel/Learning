#include <iostream>
using namespace std;
/*
 * We have 4 cases for default constructor that has empty body
 *  1- Explicitly declare/define with empty body A(){}
 *  2- write nothing and no parameterized constructor
 *  3- Declare/Define in class with default A()=default;
 *  4- Declare in class and in separate definition use default A();        A::A()=default;
 * */
class Employee{
private:
    int *salary { nullptr };
    string name;
public:
//    Employee() = default; // or Employee(){}; default constructor to avoid CE when write Employee e;
    Employee(int salary = 0 , string name = ""): salary{new int(salary)} , name{name} {} // if we make default parameters alse way to avoid CE
    Employee(const Employee & another){ // Copy constructor to avoid shallow copy with pointers
        salary = new int;
        *salary = *another.salary;
        name = another.name;
    }

};

class A{
public:
    A(){} // user-provided constructor
    int i;
    string s;
};

class B{
public:
    // Not user-provided constructor
    // implicit generated default constructor
    int i;
    string s;
};

class C{
public:
    //Not user-provided constructor
    C()=default; // assign default values
    int i;
    string s;
};

class D{
public:
    // user-provided constructor
    D();
    int i;
    string s;
};
D::D()=default;
// 1 , 4 are different from 2,3 (4 Because you declare without intentions (and later you decide that definition is going to be this or different way))
//Now see different in main
int main(){
//    for(int i =0;i < 10 ;i++)
    {
//    Default initialization
        A a1;
        B b1;
        C c1;
        D d1;
        cout << a1.i << '\n'; // garbage
        cout << b1.i << '\n'; // garbage
        cout << c1.i << '\n'; // garbage
        cout << d1.i << '\n'; // garbage

//    value-initialization triggered by () or {}
        A a2{};
        B b2{};
        C c2{};
        D d2{};
        cout << a2.i << '\n'; // garbage
        cout << b2.i << '\n'; // 0
        cout << c2.i << '\n'; // 0
        cout << d2.i << '\n'; // garbage
        //s always "" because the string is class with handled constructor

        // Tip : 1- Always initialize variables , 2- Better using {} style
    }

}