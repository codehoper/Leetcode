#include<stdio.h>



static void merge(int a[],int start,int mid,int end) {
	int* temp1 = (int)malloc(sizeof(int * (mid-start)));
	int* temp = (int)malloc(sizeof(int * (end-start)));
	int temp2[] = (int)malloc(sizeof(int * (end-mid)));
	int i = start;
	int j = mid;
	int k = 0;	
	
	while(i < mid && j < high) {
		if(s[i] <= s[j])	{
			temp[k]	= s[i];
			i++;
		}else {
			temp[k] = s[j];
			j++;
		}
	  k++;
	}

	while(i < mid)  {
		temp[k++] = s[i];
		i++;	
	}
  	while(j < high) {
		temp[k++] = s[j];
		j++;
	}
	
	int len = end - start;
	k =0;
	for(k=0;k< (end-start);k++) {
		s[k] = temp[k];

	}
		

}

static void merge_sort(int a[],int start,int end) {
	int mid;
	if(start < end) {
		mid = start + (end-start)/2;
		merge_sort(a,start,mid);
		merge_sort(a,mid+1,end);
		merge(a,start,mid,end);
	}

}

int main() {

	int a[] = {5,2,12,1,212,10,6};

	merge_sort(a,0,6);

}
