#include "/home/anaselwkel/VSCode/P1/Hashing/Probing/HashTable.h"
int hash_string(std::string s , int _n = 65407 /*Prime number*/){
    long long n = _n;
    long long sum = 0;
    int base = 62;/// [0-25]->lowers , [26-51]->uppers , [52-61]->digits
    for(auto c : s){
        int subtract = ('A' <= c && c <= 'A' ? 'A' : ('a' <= c && c <= 'z' ? 'a' : '0'));
        int ch = (subtract == 'a'? 0:(subtract=='A'?26:52)) + c - subtract;
        sum = (sum * base  + ch) % n; // 62 -> 26 for lower + 26 for upper + 10 for digits
    }
    return sum;
}

struct Phone{
    string name , number;
    Phone() = default;
    Phone(string name , string number):name(name) , number(number){}
    bool operator==(const Phone& other) const{
        return name == other.name;
    }
    int hash() const{
        return hash_string(name);
    }
    string toString() const{
        return "[ " + name + " " + number + " ]";
    }
};
void test(){
    // HashTable<long long> table(13);
    // table.insert(18 , 5);
    // table.insert(41 , 2);
    // table.insert(22 , 9);
    // table.insert(44 , 5);
    // table.insert(59 , 7);
    // table.insert(32 , 6);
    // table.insert(31 , 5);
    // table.insert(73 , 8);
    // table.printTable();
    // table.remove(59, 7);
    // table.remove(32, 6);
    // table.insert(200 , 6);
    // table.insert(211 , 12);
    // table.insert(315 , 12);

    // table.printTable();    

    HashTable<Phone> phoneTable(11);
    phoneTable.insert(Phone("Anas" , "0123442543"));
    phoneTable.insert(Phone("zeyad" , "013453534"));
    phoneTable.insert(Phone("mohamed" , "1987243"));
    phoneTable.insert(Phone("mostafa" , "013425443645646"));

    phoneTable.insert(Phone("mostafa" , "5555555555"));
    phoneTable.printTable();
}