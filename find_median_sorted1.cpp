#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:

    int isOdd(int n) {
        if (n % 2 == 0) {
            return 0;
        }
        return 1;
        
    }
    
    int getMedianPoint(int len,int m,int n) {
        int m1 = 0;
        if (isOdd(len) == 1) {
            m1 = len + 1/2;
        } 
        if(m1 > m) {
            m1 = m1 - m;
        }
        return m1;
    }
    
    int cmp(int a,int b)  {
        if(a == b) {
            return 1;
        }else if (a > b) {
            return 0;
        }
        return -1;
    }
    
    
    
    std::vector<int>* merge_array(int A[], int m, int B[], int n) {
        std::vector<int>* temp_vec = new std::vector<int>();
        int i=0;
        int j = 0;
        while(i < m && j < n) {
            if( 1 == (cmp (A[i],B[j])) ) {
                temp_vec->push_back(A[i]);
                i++;
                j++;
            }
            else if ( 0 == (cmp (A[i],B[j])) ) {
                temp_vec->push_back(B[j]);
                j++;
            }
            else if ( -1 == (cmp (A[i],B[j])) ) {
                temp_vec->push_back(A[i]);
                i++;
            }        
        }
        
        while(i < m) {
            if (true != binary_search(temp_vec->begin(),temp_vec->end(),A[i])) {
                temp_vec->push_back(A[i]);
            }      
            i++;
        }
        
        while(j < n) {
            if (true != binary_search(temp_vec->begin(),temp_vec->end(),B[j])) {
                temp_vec->push_back(B[j]);
            }      
            j++;
        }
	return (temp_vec);
        
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int med = 0;
        std::vector<int> * acc = merge_array(A,m,B,n);
        med = acc->size();    
        int result = 0;
        if (isOdd(med) == 1 && med != 0) {
            result = acc->at(med);    
        } else if ( 0 == isOdd(med) && med != 0) {
            med = med/2;
            result =  (double)(acc->at(med) + acc->at(med + 1))/2;
        }
        
        return result;
        
    }
};

int main () {
	Solution* sol = new Solution();
        int A[] = {1,2,3,4,6,7};
        int B[] = {2,7,8,9,12};
        sol->findMedianSortedArrays(A,6,B,5);
}
