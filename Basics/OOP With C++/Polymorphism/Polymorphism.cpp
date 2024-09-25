//Rule : if there is a virtual function , every child class is also virtual in this function even if it didn't put the virtual function
class A {
    public :
    virtual void f1(){cout << "A::f1" << endl;}
    void f2(){cout << "A::f2" << endl;}
    void f3(){cout << "A::f3" << endl;}
};

class B : public A {
    public :
    void f1(){cout << "B::f1" << endl;}
    virtual void f2(){cout << "B::f2" << endl;}
    void f3(){cout << "B::f3" << endl;}
};

class C : public B {
    public :
    void f1(){cout << "C::f1" << endl;}
    void f2(){cout << "C::f2" << endl;}
    virtual void f3(){cout << "C::f3" << endl;}
};

class D : public C {
    public :
    void f1(){cout << "D::f1" << endl;}
    void f2(){cout << "D::f2" << endl;}
    void f3(){cout << "D::f3" << endl;}
};

int main(){
    A* a = new B();
    a->f1(); //B::f1
    a->f2(); //A::f2
    a->f3(); //A::f3
    cout << el;
    B* b = new C();
    b->f1(); //C::f1
    b->f2(); //C::f2
    b->f3(); //B::f3
    cout << el;
    C* c = new D();
    c->f1(); //D::f1
    c->f2(); //D::f2
    c->f3(); //D::f3
    cout << el;

    delete A;
    delete B;
    delete C;
}