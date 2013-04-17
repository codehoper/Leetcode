#include<stdio.h>

void print()
{
	char str[20] = "hello world\0";
	int i=0;
	while (str[i]!='\0')
	{
	  printf("%c", str[i]);
	  i++;
	  str[i] = str[i-1];
	  }
}

typedef struct abc {
	int b : 1;
}abc;

typedef struct abc1 {
	abc l1[2];
	abc l2[2];
}d;


int main() {
	int i,j;
	d dd[10];
	for (i=0;i<10;i++) {
			dd[i].l1[j++].b = 0  >> 8;
			dd[i].l1[j++].b = 1 ;
		
	}
	//print();
}
