#include<iostream>
#include<string.h>
#include<string>
int main() {
	
	const char *neo = "vikram";
	std::string* jenNeo = new std::string("neo-gen");
	std::cout << "you are "<<neo<<" with speed "<<strlen(neo)
	<<std::endl;
	std::cout << "neo just "<< *jenNeo<<" show power of strings " << jenNeo->length()
	<<std::endl;
}
