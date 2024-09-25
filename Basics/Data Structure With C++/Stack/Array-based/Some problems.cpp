#include "Stack.h"
#include <vector>
#include <map>
#include <sstream>
std::string reverse_subwords(std::string line) {
    std::stringstream ss(line);
    std::string ret = " " ;
    std::vector<std::string> words;
    int i = 0 ;
    while(!ss.eof()) {
        std::string word;
        ss>>word;
        words.push_back(word);
    }
    for(int i =0 ; i < words.size(); i++) {
        Stack<char> stk(words[i].size());
        for(char& c : words[i])
            stk.push(c);
        while(!stk.is_empty()) {
            char c = stk.pop();
            ret += c;
        }
        ret += ' ';
    }

    return ret;
}
/*sample :
    std::string line = "abc d  efg xy";
    std::cout << reverse_subwords(line) << std::endl;
 */



bool valid_paranetheses(std::string s) {
    std::map<char, int> mp;
    mp['('] = ')' , mp['['] = ']' , mp['{'] = '}';
    Stack<char> stk(s.size());
    for(const char& c : s) {
        if(mp.find(c) == mp.end()) {
            if(stk.is_empty()) {
                return false;
            }
            if(c == ')' and stk.get_top() == '(') stk.pop();
            else if(c == ']' and stk.get_top() == '[') stk.pop();
            else if(c == '}' and stk.get_top() == '{') stk.pop();
            else return false;

        }else stk.push(c);
    }

    return stk.is_empty();
}
/*samples:
    std::string s = "([])";
    std::cout << (valid_paranetheses(s) ? "true" : "false") << std::endl;
 */