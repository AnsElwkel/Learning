#include <bits/stdc++.h>
//small upper digits
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

//folding idea for hashing
//for every 4 consecutive element compute their hash value and sum all them
int hash_string_folding(std::string str , int _n = 65407){
    long long sum = 0;
    long long n = _n;
    for(int i = 0; i < str.size(); i+=4)
        sum = (sum + hash_string(str.substr(i , 4))) % n;

    return sum;
}

int hash_num(int value, int n_ = 65407) {
	long long n = n_; // to avoid overflow
	return (value % n + n) % n;
}


// key based on multiple variables
struct someObj{
    std::string str1 ,str2 ;
    int number;

    int hash(){
        const int MOD = INT_MAX;
        long long hashCode = hash_string_folding(str1 + str2 , MOD) + hash_num(number , MOD);
        return hashCode % MOD ;
    }
};


//Re-Hashing
struct Phone{
    std::string name , phoneNumber;
    int hash(){
        return (hash_string_folding(name ,INT_MAX) + hash_string_folding(phoneNumber , INT_MAX)) % INT_MAX;
    }
    int operator==(const Phone& another){
        return name == another.name;
    }
};

struct PhoneHashTable{
    std::vector<std::vector<Phone>> table;
    int size , load_factor , total_elements;
    PhoneHashTable(int size= 10 , double load_factor = 0.75)
    : size(size) , load_factor(load_factor) , total_elements(0),
    table(std::vector<std::vector<Phone>>(size , std::vector<Phone>())) {}

    void rehashing(){
        if((double)total_elements / size <= load_factor) return ;

        //Do rehashing
        PhoneHashTable newHashTable = (2*size , load_factor);
        for(int i = 0; i < size ; i++){
            if(!table[i].size()) continue;
            for(int j = 0; j < table[i].size(); j++)
                newHashTable.insert(table[i][j]);
        }

        size *= 2 , table = newHashTable.table;
    }

    void insert(Phone entry){
        int idx = entry.hash() % size;
        for(auto& cur : table[idx]){
            if(cur == entry){
                cur = entry;
                return;
            }
        }

        table[idx].push_back(entry);
        ++total_elements;
        rehashing();
    }
};



//HashTable Linked list based

struct singleLinkedList{
    struct Node{
        Phone data;
        Node* next;
        Node(Phone data) : data(data) , next(nullptr){}
        ~Node(){}
    }*head , *tail;
    int len;
    singleLinkedList():len(0) , head(nullptr) , tail(nullptr){}

    void print(){
        std::cout << "[";
        for(Node* cur = head ; cur ; cur = cur->next){
            std::cout << "(" << cur->data.name << "-" << cur->data.phoneNumber << ") ";
            if(cur->next) std::cout << ',';
        }
        std::cout << "]\n";
    }

    int insert(Phone entry){
        if(!head){
            head = tail = new Node(entry);
        }else{
            tail->next = new Node(entry);
            tail = tail->next;
        }
        ++len;
    }

    int size(){
        return len;
    }

    bool update(Phone entry){
        for(Node* cur = head ; cur ; cur = cur->next){
            if(cur->data.name == entry.name){
                cur->data = entry;
                return true; // exist
            }
        }
        return false;
    }


    ~singleLinkedList(){
        delete head;
        delete tail;
    }
};


struct PhoneHashTableLinkedListBased{
    int size ;
    std::vector<singleLinkedList*> table;
    PhoneHashTableLinkedListBased(int size):size(size), table(std::vector<singleLinkedList*>(size)){}

    void insert(Phone entry){
        int idx = entry.hash() % size;
        if(!table[idx]) table[idx] = new singleLinkedList();
        if(!table[idx]->update(entry))
            table[idx]->insert(entry);
    }

    void print_all(){
        for(int i = 0; i < size; i++){
            if(table[i] && table[i]->size()){
                std::cout << "Hash " << i << " : ";
                table[i]->print();
            }
        }
    }

};

