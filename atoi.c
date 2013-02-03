#include <stdio.h>
int do_atoi(char *number){
	int len =0;
	while(number[len] != '\0') {
		len ++;
	}
	len --;
	int no = 0;
	int factor = 1;
	for (;len>=0;len--) {
		int rem = number[len] - '0';
		no += rem * factor;
		factor = factor * 10;
		//printf("%d , %d number = %d ;no =%d;len = %d\n",number,*number,rem,no,len);
	}

return no;

}
int main() {

	char *number = "234";
	int n =	do_atoi(number);
	printf("atoi(%s) = %d \n",number,n);
	return (0);
}
