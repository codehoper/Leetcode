#include<iostream>
#include<vector>
#include<algorithm>

/**
 * There are two sorted arrays A and B of size m and n respectively. 
 * Find the median of the two sorted arrays. 
 * The overall run time complexity should be O(log (m+n)). 
 */
class Solution {

public:

  int isOdd(int n) {
		if (n % 2 == 0) {
			return 0;
		}
		return 1;
	}

	int cmp(int a,int b)  {
		if(a == b) {
			return 1;
		}else if (a > b) {
			return 0;
		}
		return -1;
	}

	/***************************************************************************************************
	 * Merge array into single vector
	 * 1.Eliminate common elements
	 *  Use comparison and Bin serach
	 *  Time : Complexity (O(n) + O (log m+n) )
	 *  Space : O(m+n)
	 ****************************************************************************************************/

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
		int med = -1;
		std::vector<int> * acc = merge_array(A,m,B,n);
		med = acc->size() ;
		double result = 0;
		if (isOdd(med) == 1 && med > 0) {
			med = (med)/ 2;
			result = acc->at(med);
		} else if ( 0 == isOdd(med) && med > 0) {
			med = med/2;
			result =  (double)((double)acc->at(med-1) + (double)acc->at(med))/2;
		}

		return result;

	}
};

int main () {
		Solution* sol = new Solution();
        int A[] = {};
        int B[] = {2,3};
        std::cout << sol->findMedianSortedArrays(A,0,B,2);
}
