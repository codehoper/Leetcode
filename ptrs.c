//
#include<stdio.h>



//NOTE : as in C we do not have concept of references like c++ 
//So in function declaration you are not allowed to use "&"
//But during function calling you can use "&"
//As semantic changes when you use "&" in function definition it acts as address
int hi (int i) {
	return i;
}

int* hi_ptr(int *i) {
	return i;
}
int main() {
	//Declaration read from rt-lt <----
	//function pointer
	int (*fn) (int);
	int i = 10;
	fn = &hi;
	int sum = fn(i);
	printf(" sum = %d \n",sum);


	int op = 11;
	int* (*fn_ptr) (int *);
	fn_ptr = &hi_ptr;
	int *k = fn_ptr(&op);

	printf("sum = %d \n",*k);

}


