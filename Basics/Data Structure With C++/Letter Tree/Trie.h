#ifndef TRIE_H
#define TRIE_H
#include <string>
#include <iostream>
#include <cstring>

class Trie {
public:
    Trie();

    void insert(const std::string &word, int idx = 0);

    void insert_iter(const std::string &word);

    bool word_exists(const std::string &word, int idx = 0);

    bool word_exists_iter(const std::string &word);

    bool prefix_exists(const std::string &word, int idx = 0);

    bool prefix_exists_iter(const std::string &word);

    std::string minmal_prefix_iter(const std::string & word);

private:
    static const int MAX_CHAR = 26;
    bool isLeaf;
    Trie *child[MAX_CHAR];
};


#endif //TRIE_H
