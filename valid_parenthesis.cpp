#include<iostream>
#include<string>
#include<stack>
/**
*    Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
*    determine if the input string is valid.
*    The brackets must close in the correct order, 
*    "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*
**/
class Solution {
public:
    bool isValid(std::string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        std::stack<char> * char_stack = new std::stack<char>();
        char char_op;
        for(int i = 0 ;i < len ;i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                char_stack->push(s[i]);
            }
            else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if(0 == char_stack->size()) {
                    return false;
                }
                char_op = char_stack->top();
                char_stack->pop();

            if( ('(' == char_op && ')' != s[i]) || 
                ('{' == char_op && '}' != s[i]) ||
                ('[' == char_op && ']' != s[i])) {
                return false;
            }

           }
        }
         if(0 == char_stack->size()) {
             return true;
         }
        return false;
    }
};
