//Static with class
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
#include <string>
#include <utility>
using namespace std;
/*Recall static variables
 * Declared once in memory till program ends
 */
void hello(){
    int i = 0;
    static int val = 0;
    cout << i++ << ' ' << val++ << '\n';
}

/* Static Data member
 * What if we need a shared variable among all classes?
 * So defined once and used by all? static member
 * Once created :
 *      Could be no objects yet
 *      Available till program ends
 */

class test {
public:
    static int i /*= 1 CE */; // Declare: shared among all objects
};

int test::i = 1; // Define outside

void f(){
    test::i +=20; // same variable
}
//------------------------------------------
/*Static member function
 * in similar way ,we may want a static function shared among all objects
 * This means it can`t access data member
 * But can access static data member as it shared
 * */

class test2{
public:
    int i;
    static int x;//Declare
    static int factorial(int n){
//        i = 10; // CE : can`t access member data because it isn`t static variables
        x+=1;
        int ret = 1;
        for(int i = 1; i <= n ; i++)
            ret *= i;
        return ret;
    }
};
int test2::x = 1; //Define

//-------------------------------------------------
// A practical example
class Employee{
    string name;
    static int EmployeeCount; //Define
public:
//    Employee(){}
    Employee(string _name):name(_name){++Employee::EmployeeCount;}
    static int getEmployeeCount(){
        return Employee::EmployeeCount;
    }
};

int Employee::EmployeeCount = 0; //Declare

int main(){
    hello();
    hello();
    hello();
    hello();
//---------------------------
    test::i += 1; // Access
    f();
    cout << test::i << '\n';
//---------------------------
    cout << test2::factorial(5) << '\n';
    cout << test2::factorial(5) << '\n';
    cout << test2::x << '\n';
//---------------------------
//I`m not understand why output is 1 !!
    Employee e("Ahmed");
    Employee("Anas");
    static Employee belal("belal");
    cout << Employee::getEmployeeCount << '\n';
}