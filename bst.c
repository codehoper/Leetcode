#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/***
 * Author : Pandhari
 * **/
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}bst;

//Insert node into bst

bst* insert_node(int adata){
	bst *tree_node = (bst *)malloc(sizeof(bst));
	tree_node->left = 0;
	tree_node->right = 0;
	tree_node->data = adata;
	return (tree_node);
} 

void make_bst(bst **root,int data){
	bst *temp = *root;
	if(*root == 0) {
		bst* temp_node = insert_node(data);
		*root = temp_node;
	}else if(temp->data < data) {		//bigger data always go to right
		make_bst(&temp->right,data);	//semantics &(temp->left)
	}else {
		make_bst(&temp->left,data);
	}
}

void do_preorder(bst *root) {
	if(root != 0) {
		printf("%d\t",root->data);
		do_preorder(root->left);
		do_preorder(root->right);
	}
}

void do_inorder(bst *root) {
	if(root != 0) {
		do_inorder(root->left);
		printf("%d\t",root->data);
		do_inorder(root->right);
	}
}

int max(int i,int j) {
	if(i > j) {
	 	return i;
	}else {
		return j;
	}
}

/**
 * find max height of the bst
 * Always give unit cost to each node 
 * 1.root 2.left 3.right
 * **/
int findMaxHeight(bst *root) {
	int rt = 0;
	int lt = 0;
	if(root == 0) {
		return 1;	
	}else {
	    lt = findMaxHeight(root->left);
	    rt = findMaxHeight(root->right);
	   //The reason to add 1 is to just make sure that you have traversed from top
	   //and you are 1 height below from the top.
	    if(lt < rt) {
		return rt+1;	
	    }
	    return lt+1;
	}

}


int is_balanced(bst *root) {

	if(root == 0)	return 0;
	int lt = is_balanced(root->left);
	int rt = is_balanced(root->right);
	if (abs(lt - rt) > 1 || lt < 0 || rt < 0)
		return 0;
	return max(lt,rt) + 1; //add root weight = 1;

}



void getkth_max(bst *root,int k) {
	
	if(root == 0 || k < 0)	{
		return ;
	}
	//printf ("\n%d\t",k);
	static int index = 0;  //to ensure between stack excution we get latest/updated value
	getkth_max(root->left,k);
	++index;
	if( k == index) {
		printf ("\nthe largest element =  %d\n",root->data);
		//return root->data;
	}
	getkth_max(root->right,k);
		
}

void getkth_max_1(bst *root,int* k) {
	
	if(root == 0 || *k < 0)	{
		return 1;
	}
	getkth_max(root->left,*k);
	-- (*k);
	if( *k == 0) {
		printf ("\nthe largest element =  %d\n",root->data);
		return root->data;
	}
	getkth_max(root->right,*k);
		
}

//left sided doubling or one sided doubling
void double_tree(bst *root) {

	bst *oldptr;
	if(root == 0) return;
	//NOTE : Here we do not return anything we utilize stack 
	//feature not to avoid communication
	double_tree(root->left);
	double_tree(root->right);
	//store the in oldptr
	oldptr = root->left;
	
	//Update load new
	root->left = insert_node(root->data);

	//store old again for consistency purpose restore the old value
	root->left->left = oldptr;

	//we cannot use above tric in faltten as we know that we have to suplicate the strucutre only once but in flatten example we have to make count about how many levels/count we should maintain in order to append the data i.e. right pointer/old_ptr 

}


void flatten(bst *root) {
	if (!root) return;
	bst* left = root->left;
	bst* right = root->right;
	if (left) {
		root->right = left;
		root->left = NULL;
		bst* rightmost = left;

	while(rightmost->right) {
		rightmost = rightmost->right;
	}
	rightmost->right = right; 
	// point the right most to the original right child
									    }
	flatten(root->right);        
}

void flatten_bt(bst *root) {

	bst *old_ptr;
	bst *dummy_ptr;
	if(0 == root) return;
	//Verifed : order make no sense i.e you can use root->left or root->right 1st or 2nd
	flatten_bt(root->left);
	flatten_bt(root->right);
	//flatten_bt(root->left);

	//if(0 == root->left) return;
	//else {
	if(root->left) {
		old_ptr	= root->right;
		//TODO : Do we have to do insert_node here
		//NO NEED OF ABOVE
		//root->right = insert_node(root->left->data);
		root->right = (root->left);
		dummy_ptr = root->right;
		//To maintain consistency
		while(dummy_ptr->right) {
			dummy_ptr = dummy_ptr->right;
		}

		if (0 != old_ptr)
			dummy_ptr->right = old_ptr;
	

		//Zero out left part
		root->left = 0;
	}


}


//Use sorted array / linked list to compute balanced bst
//Complexity of recursion = # recusrion calls
//so runtime = O(logn)

bst* arr_convert_to_bst(int a[],int start,int end) {
	if(start < end)
	{
		//use recursion (Top down approach)
		int mid = start + (end - start)/2;
		bst *root = insert_node(a[mid]);
		root->left = arr_convert_to_bst(a,start,mid-1);
		root->right = arr_convert_to_bst(a,mid+1,end);
		return root;
	} else {
		return 0;	
	}

}



int main () {
	int tree_bag[] = {23,12,4,89,34,8,0,67};
	int i =0;
	bst *root = 0;
	for (;i<7;i++) {
		make_bst(&root,tree_bag[i]);	
	}
	printf ("Preorder : \t");
	do_preorder(root);
	printf("\n");
	
	printf ("Inorder : \t");
	do_inorder(root);
	printf("\n");

	int ht;
	ht = findMaxHeight(root);	
	printf("the max height of the tree = %d\n",ht);

	int no;
	int k = 3;
	getkth_max(root,k);


	printf ("Inorder Before flattening: \t");
	do_inorder(root);
	printf("\n");

	flatten_bt(root);
	//flatten(root);
	printf ("Inorder After flattening: \t");
	do_inorder(root);
	//do_inorder(t);
	printf("\n");

}
