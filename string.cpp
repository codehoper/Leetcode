#include<string>
#include<iostream>
using namespace std;
int main() {
	string t = "jello";
	string t1 = "bello";
	
	string *s = &t;
	string *s1 = &t1;

	s1 = s;
	s1->at(0)='H';

	cout << "s ="<<s<<" and s1=" <<s1<< endl;
	cout << "forgot to use dereference " << endl;
	cout << "After dereferencing s="<< *s<<" s1=" << *s1 << endl; 
	
	string *tx = new string("Google");
	string *ty = new string("Link\0edIn");
	
	tx = ty;
	tx->at(0) = 'G';

	cout << "tx ="<<tx <<" and ty=" <<ty << endl;
	cout << "forgot to use dereference " << endl;
	cout << "After dereferencing tx="<< *tx <<" ty=" << *ty << endl;
	
	
}
