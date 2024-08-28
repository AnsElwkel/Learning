
class Person {
public:
    void print(){cout << "Person" << endl;}
    void print2(){cout << "Perrrrrrrrrrrr" <<endl;}

    ~Person(){cout << "~person" << endl;}
};

class Student : public Person {
public:
    void print(){cout << "Student" << endl;}
    void print1(){cout << "Srrrrrr" <<endl;}
    ~Student(){cout << "~Student" << endl;}
};

int main(){
    Person p;
    Student s;
    s.print(); //student
    s.print1();
    p.print2(); //person
    /**
     *We can make point type of base class and refer to derived class
     *  but onle call member functions of Pointer Type
     *  when there are override functions also call in pointer type
     */
    Person* ptr1 = new Student(); //Person pointer to create student object in memory
    Person* ptr2 = &s; //Person pointer to point to s
    ptr1->print(); //Member function called based on pointer type not object type
    ptr1->print();
    // Student* ptr3 = new Person(); //CE vise versa is not valid .. in real every student is a person but every person shouldn't a student


    delete ptr1; // Memory leak -> delete pointer only
}








/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Virtual function call based on derived class
class Person {
public:
    virtual void print(){cout << "Person" << endl;}
    virtual  void print2(){cout << "Perrrrrrrrrrrr"<< endl;}
    virtual ~Person(){cout << "~person" << endl;} //now below call the destructor of derived class not this destructor
};

class Student : public Person {
public:
    void print(){cout << "Student" << endl;}
    void print1(){cout << "Srrrrrr" <<endl;}
    ~Student(){cout << "~Student" << endl;}
};

int main(){
    Student s;
    Person* ptr1 = new Student();
    Person* ptr2 = &s;
    ptr1->print();
    ptr1->print();
    ptr1->print2();
    ptr1->Person::print(); //Exciplict

    delete ptr1; // not memory leak and now destructor is Student
}

