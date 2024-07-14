#include <iostream>
using namespace std;
//When we use pointers in Classes -> Handle Copy Constructor
/*
 * Copy Constructor -> Deep Copy
 * and to avoid shallow copy problems
 * use When initialize object (2 ways) , pass by value or return from function
 * if not handled -> the compiler will be handled
 * */

//Temporary Objects
/*
 * An object does not have a name
 * Main rule : cannot be bound to a non-const REFERENCE
 * object that returned from function is temporary
 * */
class student{
private:
    int *id;
    string name;
public:
    student(int _id = 1 , string _name = "Anas"){
        cout<<"Normal Constructor\n";
        id = new int ;
        *id = _id;
        name = _name;
    }

//    //const may be removed but & CE!
    student(const student & _student){//Copy Constructor
        cout<<"Copy Constructor\n";
        id = new int;
        *id = *_student.id;
        name = _student.name;
    }

    ~student(){
        cout<<"Deleted\n";
//        delete id;
    }
    void print(){
        cout<< *id<<'\t'<< id<<'\n'
            << name << '\t'<<&name<<'\n';
    }
    void changeId(int newId){
        *id=newId;
    }
};
void set1(student st){} // valid for temporary object
void set1(student &st){} //CE
void set1(const student &st){}//valid for temporary object

int main(){
    student st1;
    student st2(st1);
//    st1=st2;
    st1.print();
    st2.print();
    st1.changeId(4);
    st1.print();
    st2.print();
}