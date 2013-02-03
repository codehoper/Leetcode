#include<iostream>
#include<map>
#include<string>
using namespace std;

int add (int a,int b) {
	return a + b;
}
int sub (int a,int b) {
	return a - b;
}
int mult (int a,int b) {
	return a * b;
}
int div (int a,int b) {
	return a /  b;
}
  

int main(){
	typedef int (*cmd_handler_t)(int,int);
	map<string,cmd_handler_t> function_map;
	map<string,int(*)(int,int)> function_map1; //very difficult way to use the function pointer
	function_map["do_add"] = &add;
	function_map["do_sub"] = &sub;
	function_map["do_mult"] = &mult;
	function_map["do_div"] = &div;

	function_map1["do_add"] = &add;

	//use of function pointer
	int t = function_map["do_add"](12,23);
	cout <<"function pointer map add result = "<< t << endl;
	
	t = function_map1["do_add"](12,34);
	cout <<"function pointer map1 add result = "<< t << endl;
}
