#include "HashTable.h"
void test(){
    HashTable<int> table(11);
    table.insert(10 , 1);
    table.insert(30 , 1);
    table.insert(40 , 1);
    table.insert(20 , 2);
    table.insert(50 , 2);
    table.insert(507 , 2);

    table.insert(550 , 4);
    
    table.insert(510 , 7);
    table.insert(580 , 7);

    table.insert(50 , 9);
    table.insert(50 , 10);


    table.printTablePrimitive();
}