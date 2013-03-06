//Find two elements in sorted array which sums to a given number 
#include<stdio.h>

static void find_sum_element(int a[],int start,int end,int sum) {
	
	while(end >= start) {
		int temp_sum;
		temp_sum = a[start] + a[end];
		if(temp_sum == sum) {
			printf("the sum = %d required element are %d %d and at index %d %d\n",sum,
			a[start],a[end],start,end);
			break;
		}else if(temp_sum < sum) {
			++start;
		} else {
		     --end;
		}
	}
}


int main() {

	int a[] = {2,5,6,9,12,35,45};
	find_sum_element(a,0,6,17);	
}
