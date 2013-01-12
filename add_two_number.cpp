/**
 * 
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class AddBinary {
public:
    void insert_node(ListNode **head,int result) {
        ListNode *temp = new ListNode(result);
  	if(*head == 0) {
			*head =  temp;
		}else {
			temp ->next = *head;
			*head= temp;
		}
	}
    
    void append_node(ListNode **head,int result,ListNode **tail) {
        ListNode *temp = new ListNode(result);
    	if(*head == 0) {
			*head =  temp;
            *tail = *head;
		}else {
            (*tail)->next = temp;
			*tail = temp;
		}
	}
    
  

	ListNode *addTwoNumbers(ListNode *l1,ListNode *l2)
	{
		ListNode *l3 = 0;
        ListNode *tail = 0;
		int result = 0;
		int carry = 0;
		//		*l3 = new ListNode(result);
		while( l1 != 0 &&  l2 !=0 ) {
			result = l1->val + l2->val + carry;
			carry = 0;
			if(result > 9) {
				result = result - 10;
				carry = 1;
			}
			//insert_node(&l3,result);
            append_node(&l3,result,&tail);
			l1 = l1->next;
			l2 = l2->next;
		}

		while(l1 != 0) {
			result = carry + l1->val;
			carry = 0;
			if(result > 9) {
				result = result - 10;
				carry = 1;
			}
		 append_node(&l3,result,&tail);
			l1 = l1->next;
		}

		while (l2 != 0) {
			result = carry + l2->val;
			carry = 0;
			if(result > 9) {
				result = result - 10;
				carry = 1;
			}
			 append_node(&l3,result,&tail);
			l2 = l2->next;
		}
        
        if(carry == 1) {
            append_node(&l3,carry,&tail);
        }
        
		return l3;
	}

};
