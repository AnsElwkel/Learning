/**
 * Order of constructor and destructor calling in inheritance
 * tricky error when assign protected member in child class using initialzer list
 * Member function override -> same name and return type and parameters
 * Inheriting Constructor
 * Prevent class inheritance -> final keyword
 *
 * Overloading :
 *      -same name , different parameter and cause in same class
 * Overriding :
 *      -same name , same parameter and cause between superclass and derived class
 *      (priority for do in derived class)
 *
 * Difference between public and protected and private inheritance
 * note : if forgot type -> private is default
 *
 * in UML : + -> private
 *          - -> public
 *          # -> protected
 */
class Person {
protected:
    string name  = "__________-", email;
    int age , national_id;
public:
    void print() {
        cout << "Name: " << name << endl;
    }
    Person() {
        cout << "Default Constructor Person" << name << endl;
    }
    Person(string name) : name(name) {
        cout << "2nd Constructor Person" << name << endl;
    }
    ~Person() {
        cout << "Destructor Person" << name << endl;
    }

    int getVal() {//Override function
        return 10;
    }
};

class Student :  public  Person {
    double GPA;
    public:
    void printGrade() {
        cout << GPA << endl;
    }
    Student() // : name(name) CE
    {
        cout << "Default Constructor Student" << endl;
        name = "Anas"; // normal
    }
    Student(double gpa) : Person("Anas") , GPA(gpa)
    {
        cout << "2nd Constructor Student" << endl;

    }
    ~Student() {
        cout << "Destructor Student" << endl;
    }
    int getVal() { //Override function
        return 200;
    }
};
///////////////////////////////////////////////////////////////
class A { // Inheriting consturctor
public:
    int a , b;
    A(int a, int b = 20) : a(a) , b(b) {}
};
class B : public A{
public:
    using A::A;
};
///////////////////////////////////////////////////////////////
// class D final { // disable inheritance
//
// };
// class C : public D {
//
// }

///////////////////////////////////////////////////////////////////
class E {
    protected:
    int a;
    public:
    int b;
private:
    int c; // invisable for outsider
};

class F:public E {
    // now a is protected and b is public
};

class G:protected E {
    // both a and b are protected -> use inside and inherit
};
class H: private E /*or only  E */{
    // both a and b are private -> use inside only
    int print() {
        cout << a;
    }
};

class H2:public H {
    //doesn't inheriting anything
}
int main(){
    Student s1;
    Student s2(4.0);
    cout << s2.getVal();
cout << "0000000000000000000000000000000000000000000000000000]\n";
    B b(3); // now assigning a = 3

    H h1;
    h1.b;

    H2 h2;
    // h2.b; CE b is not found

    G g;
    // g.b; b here is protected not public
}