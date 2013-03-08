#include<stdio.h>
#include<stdlib.h>

typedef struct sll {
	int data;
	struct sll *next;
}node;

/*
 * Create single node in linked list
 *
 **/

node* create_node(int adata) {
	node *sll_node = (node *)malloc(sizeof(node));
	sll_node->data = adata;
	sll_node->next = 0;
	return sll_node;
}

/**
 *  insert node in linked list
 **/

void insert_node(node **head,int adata) {
	node *temp_node = create_node(adata);
	if(*head == 0) {
		*head = temp_node;
	}
	else {
		temp_node->next = *head;
		*head	= temp_node;
	}

}

/**
 *print linked list
 * */

void print_ll(node *head){
	while(head != 0) {
		printf("%d \t",(head->data));
		head = head->next;
	}
	printf("\n");
	
}


void do_swap1(node **h1,node **h2) {
	
	int temp = (*h1)->data;
	(*h1)->data = (*h2)->data; 
	(*h2)->data = temp;
}

void do_swap(node **h1,node **h2) {
	//printf("Before swap h1 = %d and h2 = %d\n",(*h1)->data,(*h2)->data);
	node *t = *h1;
	*h1 = *h2;
	*h2 = t;
	//int t = (*h1)->data;
	//(*h1)->data = (*h2)->data;
	//(*h2)->data = t; 	
	//printf("After swap h1 = %d and h2 = %d\n",(*h1)->data,(*h2)->data);

}

/*
 * 1.Use of swapping with double star or with reference to pointer
 *
 * Notice power of indirection
 * A single variable able to store 2 values
 * eg.node** indir = &temp;
 * now this indir variable store 2 values
 * 1.Complete node (with data and address)
 * 	a.To assign this
 * 	*indir = head1;
 * 	b.To use this
 * 	*indir
 * 2.Reference to next node (Reference is alias of object)
 * 	semantics of reference : 
 * 	IF you want to change value in variable you must have reference.
 * 	it is stored as
 * 	*indir = &(head1->next); //Store reference to the next variable
 *
 * 	NOTE in C
 * 	*node->next interpreted as (*node->next) which has 
 * 	different semantics than (*node)->next
 */

/**
 * input  : 2 sorted list
 * output : combined sorted list without extra space
 *
 **/


node* merge2_list_2(node** head1,node**	head2) {
	node* head3 = 0;
	node** indir = &head3;
	if(*head1 == 0 && *head2 == 0)
		return 0;
	else if(*head2 == 0)
		return *head1;
	else if(*head1 != 0) {	
		while(*head1 != 0) {
			if((*head1)->data > (*head2)->data) {
				do_swap(head1,head2);	
			}
		  *indir = *head1;
		  indir = &((*head1)->next);
		  *head1 = *indir;
		}
		*indir = *head2; 
		return head3;
	}
}

/*
 *
 * version 1 : just input parameters pointer instead of refrences
 **/
node* merge2_list_1(node *head1,node *head2) {
	node *temp3 = 0;
	node **indir = &temp3;
	if(head1 == 0 && head2 == 0)
		return 0;
	else if(head2 == 0)
		return head1;
	else if(head1 != 0) {	
		while(head1 != 0) {
			if(head1->data > head2->data) {
				do_swap(&head1,&head2);	
			}
		  *indir = head1;
		  indir = &head1->next;
		  head1 = *indir;
			
		}
		*indir = head2; 
		return temp3;
	}
	

}

/**
 * Reverse linked list with using double pointer to head
 * **/

static void print_rev_ll(node** head_ref) {

	node* curr = *head_ref;
	node* next = 0;
	node* prev = 0;

	while(curr) {
		
		next = curr->next;	
	        curr->next = prev;		
		prev = curr;
		curr = next;
	}

	*head_ref = prev;

}

/**
 *Reverse linked list with using single pointer
 * 
 * **/

static node * print_rev_ll1(node *head) {
	
	node *next;
	node *prev = 0;
	next = head;	
	
	while(head) {
		next = head->next;
		head ->next = prev;
		prev = head;
		head = next;	
	}
 	
	return prev;

}

/**
 * reverse list between m and n.
 * Idea : just swap the data instead of modifying pointer
 * This approach is problematic as we just swap 2 data items at a time.
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * return 1->4->3->2->5->NULL.
 * **/
static node * reverse_ll_between(node* head,int m,int n) {

	node *main_node = head;
        int t = n-m;
        int isRun = 0;
        node *prev = 0;
        node *temp = 0;
        while(m != 0 && main_node != 0) {
            prev = main_node;
            main_node = main_node->next;
            m--;
        }
        
        if(m != 0 || main_node == 0) {
            return head;
        }
        else {
            while(main_node != 0 && t != 0) {
                temp = main_node->next;
		do_swap1(&temp,&main_node);	
                //main_node->next = prev;
                //prev = main_node;
                main_node = temp;
                t--;
            }
        }
        
      //print_ll(head); to verify entries are clearly swapped
      return main_node;	
}

/**
 * Delete current node in the linked list.
 * **/

static void delete_node(node **node_ref) {
	
	node * curr = *node_ref;
	node *next = curr->next;
	if(next != 0) {
		//store next node information in the current node
		curr->data = next->data;
		curr->next = next->next;	
	}
	next = 0;
	free(next);
}

//Y-Problem : solution to detect Y problem in linked list
//Time complexity : O(n)
static void detect_y_problem(node *head1,node *head2) {
	
	int l1;
	int l2;
	int drift;
	node *temp2;
	node *temp = head1;
	while(head1 !=0) {
		temp = temp->next;
		l1++;
	}
	temp = head2;
	while(head2 != 0) {
		temp = temp->next;
		l2++;
	}
	//calculate drift and traverse the distance upto drift point
	drift = l1-l2;
	if(drift < 0) {
		drift = -drift;
	}
	
	temp = head1;
	temp2 = head2;	
	while(drift != 0) {
		if(l1 < l2) {
			temp = temp->next;
		}else {
			temp2 = temp2->next;	
		}
		drift--;
	}
	while ( temp != 0 && temp2 != 0 ) {
		if(temp == temp2) {
			printf ("\nY detected \n");
			break;
		}
		temp = temp->next;
		temp2 = temp2->next;
	}
	
}

//P-problem : Solution to detect P condition in linked list.
//Time complexity : O(n)
static void detect_cycle(node *head) {

	int found_cycle = 0;
	node *hare = head;		//Initially both run at same speed
	node *tortoise = head;

	while(hare) {
		hare = hare->next;	//hare runs twice as tortoise
		if(hare) {
			hare = hare->next;
			tortoise = tortoise->next;
			if(hare == tortoise) {
				found_cycle = 1;
				break;
			}
		}

	}

	if(found_cycle == 1) {
		printf("\nfound cycle \n");
	}
	else {
		printf("\nnot found cycle \n");
	}

}



int main() {

	int i=0	;
	int a[] = {8,7,2,1};
	int b[] = {10,8,5,4};
	node* head = 0;
	node* head2 = 0;
	for(;i<4;i++) {
		insert_node(&head,a[i]);	
		insert_node(&head2,b[i]);	
	}
	print_ll(head);
	print_ll(head2);
	node* h = merge2_list_2(&head,&head2);
//	node *h = merge2_list_1(&head,&head2);
	//node *h = MergeLists(head,head2);
	//node* h = merge2_list_1(head,head2);
	print_ll(h);
	print_rev_ll(&h);
	print_ll(h);
	node *t = h->next->next;
	delete_node(&t);
	print_ll(h);
	
	printf (" \n reversing list ...\n");
	node* h1 = print_rev_ll1(h);
	print_ll(h1);

	reverse_ll_between(h1,2,4);
	print_ll(h1);
}

