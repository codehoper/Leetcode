//Select Kth element from unsorted array 
//O(n) algorithm : 2 functions
//Select with partition

/**
Quicksort(A, p, q)
if p < q then
	next_pivot  ← Partition(A, p, q)
	Quicksort(A, p, next_pivot − 1)
	Quicksort(A, next_pivot + 1, q)
end if

The following code partitions A[p..q] around A[q]

Partition(A, p, q)
x ← A[q]
next_pivot ← p − 1
for j ← p to q do
	if A[j] ≤ x then
	swap A[i + 1] and A[j]
	next_pivot ← next_pivot +1
	end if
end for
return i
**/


#include<stdio.h>

void do_swap(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[],int start,int end) {
	
	int x = a[end];	
	int next_pivot = start - 1;
	int i;
	for (i = start;i<=end;i++) {
		if(a[i] <= x) {
		  do_swap(&a[next_pivot+1],&a[i]);
		  next_pivot = next_pivot + 1;
		}
	}
	return next_pivot;
}

int select(int a[],int start,int end,int k) {
	
	int next_pivot;
	while(start <=end ) {
		next_pivot = partition(a,start,end);	
		if(k == next_pivot) {
			return 1;
		}else if(k < next_pivot) {
			end = next_pivot - 1; // as pivot is at right position do not consider pivot again
		}else {
			start = next_pivot + 1;
		}

	}
	return -1;
	
}




int main() {
	int k = 4;	
	int result;
	int a [] = {20,8,12,2,5,40};
	result = select(a,0,5,k);
	if(1 == result)  {
		printf("\n element found %d\n",a[k]);
	}else {
		printf("\n element not fount \n");
	}
			
}
