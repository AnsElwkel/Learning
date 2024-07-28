#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

/*
 * Initializer list -> Higher Priority to initialize data when declaration the object
                    -> Light weight and memory efficient
 */

class A{
public:
    int x , y;
};
class B{
public:
    int x, y;
    B(int x , int y) : x{x} , y{y}{}
};

class C{
public:
    int x , y;
    C(int x , int y) : x{x} , y{y}{}
    C(const std::initializer_list<int> &list){
        x = *list.begin() , y = *(list.begin());
    }
};

class adder{
private:
    int totSum{};
public:
    adder(){}
    void add(int n = 0 , int m = 0) {
        totSum = n + m;
    }
    void add(const initializer_list<int> &list){
        totSum = 0;
        for(auto &i : list)
            totSum += i;
    }
    int getSum() const{
        return totSum;
    }
};

template<typename T>
void print(T list){
    for(auto &item :list) cout << item << ' ';
    cout << '\n';
}

int main(){
    A a{1 , 2};// Aggregate initialization
    B b{3 , 7};// Regular constructor
    C c1{1 , 2};// initailizer_list
    C c2(1 , 2);// Regular constructor

    //Priority -> intializier_list , Regular , Aggregate
    //Note : when use () not {} -> Regular constructor (constructor initialization)
//-----------------------------------------------------------------------------------------
    adder addition;
    addition.add(1 , 2);// add(n , m)
    cout << addition.getSum() << '\n';
    addition.add({1 , 2 , 3 ,4 , 5});// initializer_list
    cout << addition.getSum() << '\n';
    addition.add({1 , 2});// initializer_list
    cout << addition.getSum() << '\n';

    cout << "\n\n";
//-----------------------------------------------------------------------------------------
//    print({1 , 2 , 4}); CE
    print(initializer_list<int>({1, 2, 4,5}));
    print(vector<int>({1, 2, 4,5}));
//-----------------------------------------------------------------------------------------
// Notes with STL:
    cout << "Notes with STL: " << '\n';
    vector<int> v{5 , 10}; // initializer_list
    cout << v.size() << '\n';
    for(auto &i : v) cout << i << ' ';
    cout << '\n';
    vector<int> v2(5 , 10);// call another constructor (5 elements , their values are 10)
    cout << v2.size() << '\n';
    for(auto &i : v2) cout << i << ' ';
    cout << '\n';
//--------------------------------------------------------------------------------------------
//With auto
    auto x1{1}; // not initializer_list , int
//auto x4{2, 3 ,5};// CE->int

    auto x2={2};// initialzier_list
    auto x3={2 , 3, 4 , 5};// initialzier_list
//auto x5 = {1 , 3.5}; CE -> cannot deduce element type
}
