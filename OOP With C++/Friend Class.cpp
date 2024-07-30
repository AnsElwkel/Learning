#include <iostream>
using namespace std;

/*
 *Friend Class : Another class that Access my private class section
 *1- friend class , friend function member in class or global function
*/
class A {
    int prv1=10 , prv2=20;
    void fun () {
        cout << "Ans Elwkel\n";
    }

public:
    friend class B; //Now class B can access on private section A , and we decale it here
};

class B { // definition
public:
    void show1(A& c) {
        cout << c.prv1 << '\n';
    }
    void show2(A& c) {
        cout << c.prv2 << '\n';
        c.fun();
    }
};
//---------------------------------------------------------------------------
class C; // Declare early to break cycle

class D {
public:
    void access1(C& c);
    void access2(C& c);
};

class C {
private:
    int a=10;
     int b{20};
    void fun() {
        cout << "Anas Elwkel\n";
    }
public:
    friend void D::access1(C& c);  // Friend function that member in D only access on C class private data
    friend void printA(C& c); // Friend global function
};
void D::access1(C &c) {
    cout << c.a << '\n';
    c.fun();
}
void D::access2(C &c) {
    // cout << c.a << '\n'; //CE becuase it is not friend to class C
    // c.fun();
}
void printA(C &c) {
    cout << c.a << '\n';
}

int main() {
    A a;
    B b;
    b.show1(a);
    b.show2(a);
    //------------------------------------------------------------------------------
    C c;
    D d;
    d.access1(c);
    printA(c);
}