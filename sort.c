#include<stdio.h>



static void do_swap(int *a,int *b) {
	int temp = *a + *b;
	*b = temp - *b;
	*a = temp - *b;
	
}

static void selection_sort(int u_arr[],int len) {
	int i = 1;
	int j;
	for(i = 0; i< len ; i++)  {
		int min_value = u_arr[i]; 			//select the minimum value
	for(j = i+1;j< len;j++)  {
			if(u_arr[j] < min_value) 
				{		//compare all the min values
				min_value = u_arr[j];
				do_swap(&u_arr[i],&u_arr[j]);	//put or swap the min value on first index and ++ index
				
			   	}
			}
		}
}	

//Algorithm
//InsertionSort(A)
//A[0] = −∞
//for i = 2 to n do
//j=i
//while (A[j] < A[j − 1]) do
//swap(A[j], A[j − 1])
//j =j−1
static void insertion_sort(int u_arr[],int len) 
{
	int i ,j;
	int temp;
	for(i = 1;i<len;i++) {		//right now I have one card in my hand
		j = i;
		while(j>=0 && u_arr[j] < u_arr[j-1]) {	//I am going to compare untill my last card in hand
			 do_swap(&u_arr[j],&u_arr[j-1]);
			 j = j-1;
			}

		}

}
