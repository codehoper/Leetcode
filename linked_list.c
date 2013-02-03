
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

void swap_2nodes(){

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

//Y-Problem : solution to detect Y problem in linked list
//Time complexity : O(n)

//P-problem : Solution to detect P condition in linked list.
//Time complexity : O(n)


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
		
}

