#include <stdio.h>

 /* reverse:  reverse string s in place */
 void reverse(char s[])
 {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }


int do_atoi(char *number) {
	int result = 0;
	int i = 0;
	while(number[i] != '\0') {
		result = result *10 + (number[i] - '0');
		i++;
	}
	return result;		
}

 /* itoa:  convert n to characters in s */
 void itoa(int n, char s[])
 {
     int i, sign;
 
     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }


int do_atoi1(char *number) {
	int result = 0;
	int i = 0;
	while(number != 0) {
		result = result *10 + (*number - '0');
		number++;	
	}		
	return result;
}

int do_atoi2(char *number){
	int len =0;
	while(number[len] != '\0') {
		len ++;
	}
	len --;
	int no = 0;
	int factor = 1;
	for (;len>=0;len--) {
		int unit = number[len] - '0';
		no += unit * factor;
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
