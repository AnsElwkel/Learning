/**
* Private   -> no one see it
 * Public    -> anyone see it
 * Protected -> Child only see it
 *
 * multiple   inheritance
 * multilevel inheritance
 *
 */
class Person {
protected:
    string name , email;
    int age , national_id;
public:
    void print() {
        cout << "Name: " << name << endl;
    }
};

class Student : public  Person {
    double GPA;
public:
    void printGrade() {
        cout << GPA << endl;
    }
};

class Graduate : public Student { //multilevel inheritance
private:
    string facultyName , statuOfGrade;
public:
    void print() {}
};

class Employee : public Person {
private:
    double salary;
public:
    void printSalary(){
        cout << salary << endl;
    }
};
class TeachingAssistant : public Person , Employee {//multiple inheritance
    //
};


int main(){
    Student s;
    // s.name = "John"; CE
    s.print();
}