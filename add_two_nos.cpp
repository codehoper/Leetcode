#include<iostream>
using namespace std;

struct ListNode
	{
		int val;
		ListNode *next;
		ListNode(int x) : val(x),next(NULL){}
	};

class Solution {

public :
	ListNode *addTwoNumbers(ListNode *l1,ListNode *l2) 
	{
	ListNode *l3 = 0;
        int result = 0;
        int carry = 0;
        void * start_add = 0;
        int flag = 0;
        while( l1 != 0 &&  l2 !=0 ) {
            result = l1->val + l2->val + carry;
            carry = 0;
            
            if(result > 9) {
                result = 0;
                carry = 1;
            }
            
            l3 =  new ListNode(result);
            if(flag == 0) {
                start_add = l3;
            }
            l1 = l1->next;
            l2 = l2->next;
            l3 = l3->next;
            flag =1;
        }
        
        if(l1 != 0) {
            result = carry + l1->val;
            carry = 0;
            
            if(result > 9) {
                result = 0;
                carry = 1;
            }
            
            l3 =  new ListNode(result);
            l1 = l1->next;
            l3 = l3->next;
        }
        
        if (l2 != 0) {
            result = carry + l2->val;
            carry = 0;
            
            if(result > 9) {
                result = 0;
                carry = 1;
            }
            
            l3 =  new ListNode(result);
            l2 = l2->next;
            l3 = l3->next;
            
        }
        
        l3 = (ListNode *) start_add;
	while(l3 != 0) {
		cout << l3->val << "\n";
		l3 = l3->next;
	}
        return l3;
	}

};

int main() {
	Solution *sol = new Solution();
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(8);
//	l1->next->next = new ListNode(6);
	
	ListNode *l2 = new ListNode(0);
//	l2->next = new ListNode(5);
//	l2->next->next = new ListNode(6);	
	
	ListNode *l3 = sol->addTwoNumbers(l1,l2);
}
