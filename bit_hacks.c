#include<stdio.h>

//bit hacks
//1.swap two numbers
//2.take 1's complement
//3.detect no is power of 2 or not(the most efficient way)
//4.count no of 1's


void count_no_of_ones(int *x) {
  int t = *x;	
	int count = 0;
	while(t!=0) {
		t &= (t-1);
		count++;
	}
	printf("total number of 1's in %d= %d\n",*x,count);

}
/*
 *negate all bits and add 1
 **/
void get_twos_complement() {
	int x = 1;
	printf("2's complement in decimal = %d\n",-x);
}

void presentation() {
	
	int i = -1;
	int len = sizeof(int);
	char *byte = (char*)&i;
	int index = 0;
	for(;index<len;index++) {
		printf("byte[%d] = %.2X \n",index,byte[index]);
	}
	/**
	*byte[0] = FFFFFFFF 
	*byte[1] = FFFFFFFF 
	*byte[2] = FFFFFFFF 
	*byte[3] = FFFFFFFF
 	**/
}

/**
 ** swap two numbers with XOR inverse property.
 ** 	A ^ A = 0;
 **/
void swap_numbers(int *x,int *y) {
	printf("before swap x=%d and y=%d \n",*x,*y);
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
	printf("After swap x=%d and y=%d \n",*x,*y);
}

/**
 * To detect endian use byte pointer to access byte level address.
 * for the representation.
 * TRY TO AVOID USE OF HEX FOR ASSIGNMENT.
 **/

void detect_endian1() {
	int word = 1;
	char* byte = (char*)&word;
	printf("byte[0]=%.2X\n",byte[0]); //first byte	
	printf("byte[1]=%.2X\n",byte[1]); //second byte
	printf("byte[0]=%.2X\n",*byte);
	printf("byte[0]=%.2X\n",byte);
	if(byte[0] == 1) {
		printf("big endian \n");
	} else {
		printf("little endian \n");
	}
/**
 *output of the function
 *byte[0]=01
 *byte[1]=00
 *byte[0]=01
 *byte[0]=BFF9B518
 *big endian 
 */

}
//wrong version
void detect_endian() {
	
	//char byte = 0xFF;
	unsigned char byte = 255;
	int word = byte;
	if(word == 0xFF) {
		printf("big endian \n");
	} else {
		printf("little endian \n");
	}
	printf ("byte=%d and word=%d \n",byte,word);
}

void information_storage()
{
	int a = 0xFFFF;
	int b = 0xFFFFFFFF;
	printf ("a= %d and b=%d\n",a,b);	
	/**
 	* a= 65535 and b=-1
 	*/
}

int main() {
	detect_endian1();	
	int x = 10;
	int y = 45;
	swap_numbers(&x,&y);	
	presentation();
	count_no_of_ones(&y);
	return 0;
}
