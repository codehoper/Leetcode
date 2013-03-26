#include<iostream>
using namespace std;

int swap(int *a,int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int swap1(int &a,int &b) {
	int t;
	t = a;
	a = b;
	b = t;
}

int main() {

	int a = 10;
	int b = 44;
	cout << "original value\n";
	cout << "a = "<< a << " b = "<< b << endl;
	swap(a,b);
	cout << "after swap\n";
	cout << "a = "<< a << " b = "<< b << endl;
	swap(&a,&b);
	cout << "after swap\n";
	cout << "a = "<< a << " b = "<< b << endl;
	swap1(a,b);
	cout << "after swap 1\n";
	cout << "a = "<< a << " b = "<< b << endl;
	

}
