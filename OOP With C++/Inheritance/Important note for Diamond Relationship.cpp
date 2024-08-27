/**
* Important notes for Diamond Relationship


In general if class can be visible from more than direction, use virtual public CLASS not just public CLASS
 */
class Person {
protected:
    string name , email;
    int age , national_id;
public:
    void print() {
        cout << "Name: " << name << endl;
    }
    Person() {
        cout << "Person" << endl;
    }
};

class Student :  virtual public  Person {
    double GPA;
public:
    void printGrade() {
        cout << GPA << endl;
    }
    Student() {
        cout << "Student" << endl;
    }
};
class Employee : virtual public Person {
private:
    double salary;
public:
    void printSalary(){
        cout << salary << endl;
    }
};


class Graduate :  public Student , Employee{ //multilevel inheritance
    //now graduate inherit from two classes that inheritef from person class -> two call constructor of person
    // to solve this problem we put virtual keyword before public CLASS when inherit -> to call constructor of ancestor once in child of parent
    // Diamond relationship
private:
    string facultyName = "AinShams", statuOfGrade;
public:
    void print() {
        cout << facultyName << endl;
    }
    Graduate() {
        cout << "Graduate" << endl;
    }
};


class TeachingAssistant : public Person , Employee {//multiple inheritance
    //
};


int main(){

    Graduate s;
    s.print();
    cout << endl;
    Student s1;
    cout << '\n';
    Employee s2;
}