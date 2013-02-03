#include<iostream>
#include<vector>
//using namespace std;

class Solution {
public:

    int cmp (int a,int b) {
        if (a > b) return 1;
        return 0;
    }
    
std::vector<int>* mergeArray (int A[], int m, int B[], int n) {
        std::vector<int>* temp = new std::vector<int>();
        int i = 0;
        int j = 0;
        while(i < m && j < n) {
            if (1 == cmp(A[i],B[j]) ) {
                temp->push_back(B[j]);
                j++;        
            }else {
                temp->push_back(A[i]);
                i++;
            }
        }
        
        if(i < m) {
            temp->push_back(A[i]);
            i++;        
        } 
        else if(j < n) {
            temp->push_back(B[j]);
            j++;
        }
	return (temp);
}

double findMedianSortedArrays(int A[], int m, int B[], int n) 
	{
		std::vector<int>* temp = mergeArray(A,m,B,n);	
		int len = temp->size();	
		

	}
};

int main () {
	Solution* sol = new Solution();
	int A[] = {1,2,3,4,6,7};
	int B[] = {2,7,8,9,12};
	sol->findMedianSortedArrays(A,6,B,5);
}
