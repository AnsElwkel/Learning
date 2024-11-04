#include "Trie.h"

Trie::Trie() {
    isLeaf = false;
    memset(child, 0, sizeof child);
}

void Trie::insert(const std::string &word, int idx) {
    if (idx == (int) word.size()) // base case
        return isLeaf = true, void();
    int cur = word[idx] - 'a';
    if (!child[cur])
        child[cur] = new Trie();
    child[cur]->insert(word, idx + 1);
}

void Trie::insert_iter(const std::string &word) {
    Trie *cur = this;
    for (const char &c: word) {
        int ch = c - 'a';
        if (!cur->child[ch]) cur->child[ch] = new Trie();
        cur = cur->child[ch];
    }
    cur->isLeaf = true;
}

bool Trie::word_exists(const std::string &word, int idx) {
    if (idx == (int) word.size()) // base case
        return isLeaf;
    int cur = word[idx] - 'a';
    if (!child[cur]) return false;
    return child[cur]->word_exists(word, idx + 1);
}

bool Trie::word_exists_iter(const std::string &word) {
    Trie *cur = this;
    for (const char &i: word) {
        int ch = i - 'a';
        if (!cur->child[ch]) return false;
        cur = cur->child[ch];
    }
    return cur->isLeaf;
}

bool Trie::prefix_exists(const std::string &word, int idx) {
    if (idx == (int) word.size()) // base case
        return true;
    int cur = word[idx] - 'a';
    if (!child[cur]) return false;
    return child[cur]->prefix_exists(word, idx + 1);
}

bool Trie::prefix_exists_iter(const std::string &word) {
    Trie *cur = this;
    for (const char &i: word) {
        int ch = i - 'a';
        if (!cur->child[ch]) return false;
        cur = cur->child[ch];
    }
    return true;
}

std::string Trie::minmal_prefix_iter(const std::string &word) {
    Trie *cur = this;
    std::string ret="";
    for (const char &i: word) {
        if (!cur->child[i - 'a'])
            break;

        ret += i;
        if(cur->isLeaf)
            return ret;
        cur = cur->child[i - 'a'];
    }
    return ret;
}
