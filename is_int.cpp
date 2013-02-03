#include<iostream>
#include<string>
/*
* Determine wheather given number is integer or not
  1.solution based on ASCII code
  2.solution with REGEX expression
**/
class Solution {
  public:
    bool is_int(std::string s) {
       int len = s.length();
       for(int i=0;i<len;i++) {
	   	if(s[0] == '-'){
		continue;
		}
	   int result = s[i] - '0';
	   //std::cout << "debug result = " << s[i] << result;
           if(result < 0 || result > 9) {
	  	std::cout<< "string " <<s << " is not integer" << std::endl;
               return false;
           }         
       }
       return true;
    }	
};

int main() {
	Solution sol;
	std::string s("123");
	std::cout << "string s = " << sol.is_int(s) << std::endl;
	std::string s1(":::");
	std::cout << "string s = "<<sol.is_int(s1) << std::endl;
	
}
