#include <iostream>
/* Hashing
Hash function : A function that converts a given input to a fixed-size values.
                return a positive integer for the input
                Same input ⇒ Same output

Hash code => The value returned by the hash function.
          => It is used to index the hash table (never be a negative number !).
- Two avoid the negative hash codes, we use the modulo operator (and their properties)
  with the size of the hash table.

Collision : Two different inputs have the same hash code. (Many to one mapping)

- In general problems we can't avoid collisions, but we can reduce them !

- Hash function normally without %.
- We call using % a compression
- Bitwise operators can be used in hashing or combining several hash values
- Using a prime number with % => may generate better distribution of values
  according to number theory, but still collisions occurs

For more information about hash function:
https://en.wikipedia.org/wiki/List_of_hash_functions
*/

//Some examples of hash functions

int hash_string1(std::string s , long long mod = 1e7){
    long long sum = 0; // long long to avoid overflow
    for(int i = 0 ; i < s.length() ; i++)
        sum = (sum * 26 + s[i] - 'a') % mod; // 26 is the number of characters
    //sum in the 26-base to reduce the collisions :)

    return ( sum % mod + mod ) % mod; // to avoid negative hash codes
}


int hash_num(int value, int n_ = 65407) {
    long long n = n_; // to avoid overflow
    return (value % n + n) % n;
}


// Another hash function with unsigned int to avoid negative hash codes (overflow will be positive also)
unsigned int hash_num2(int value, unsigned int n = 65407) {
    return (unsigned int)value % n;
}

