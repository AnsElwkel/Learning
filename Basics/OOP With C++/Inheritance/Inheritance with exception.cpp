/**
* #include <stdexcept>
 * C++ STL Exception Hierarchy
 * Exception:
 *      bad alloc
 *      logic_error : out_of_range
 *                    length_error
 *                    domain_error
 *                    invalid_argument
 *
 *      runtime_error : range_error
 *                      overflow_error
 *                      underflow_error
 *
 *      bad cast
 *
 * To important ways to handling RTE problems : throw exceptions , error code
 *
 * in exception handling take care for catching order
 * if(you try to catch parent class (eg. logic_error , runtime_error) and then catch child class
 *      the child class never called
 *
 * So the right order to catch exceptions -> child class then parent class
 */
#include <stdexcept>
void div(int x) {
    10000/x;
}
void vec(int x) {
    vector<int> v(5);
    v.at(x) = 1; // at own out_of_range = logic_error exception
}

double sqrtt(int x) {
    if(x < 0) throw domain_error("sqrt of neg number");
    else return sqrt(x);
}
void test(int x) {
    //true way
    try {
        div(x);
        sqrtt(x);
        vec(x);
    }catch( domain_error& e) {
        cout << "Domain Error " <<  e.what() << endl;
    }catch( logic_error& e) {
        cout << "Logic Error " <<  e.what() << endl;
    }catch(...) {
        cout << "Unknown Error" << endl;
    }
}

int main(){
    // try {
    //     div(1);
    //     vec(5);
    //     sqrtt(-1);
    // }catch(const logic_error& e) {
    //     cout << "Logic Error " <<  e.what() << endl;
    // }catch(const domain_error& e) { // doesn't catch the error while x < 0
    //     cout << "Domain Error " <<  e.what() << endl;
    // }catch(...) {
    //     cout << "Unknown Error" << endl;
    //
    //     //
    // }
    test(6);
    test(-1);
    test(0); // program crash .. must handle exception for divide by zero by yourself
}