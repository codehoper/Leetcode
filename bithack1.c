#include<stdio.h>

int no_of_ones(int number) {
	int cnt = 0;
	while(number != 0) {
		number = number & (number - 1);
		cnt ++;
	}	

	return cnt;
}

void which_endian() {
	short i = 0x0001;
	short index = 0x1234; 
	char *mem_block_c = (char*)&index;
	char* ch = &i;
	if(ch[0] == 1) {
		printf("little endian \n");
	}else {
		printf("Big endian \n");
	}

}

int main() {
	int cnt = 0;
	cnt = no_of_ones(20);
	printf("Total number of ones = %d\n",cnt);
	
	which_endian();

int num = 1;
if(*(char *)&num == 1)
{
    printf("\nLittle-Endian\n");
}
else
{
    printf("Big-Endian\n");
}

	
}
