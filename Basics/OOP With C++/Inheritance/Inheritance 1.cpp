/**
*Common Vs Unique
 * Inheritance
 * we called person class is Parent, base , super or general class
 * we called Student class is Child, derived , sub or specific class
 *
 * Code Reusability methods in OO -> Inheritance , composition
 * Inheritance -> Is-a relationship eg. student , teacher are persons
 *                                      Manager , Software engineer are employee
 *                                      circle , rectangle are shapes
 *
 * Composition -> Has-a relationship eg. building has a floor , floor has a apartemants
 *
 */
class Person {
public:
    string name , email;
    int age , national_id;
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
