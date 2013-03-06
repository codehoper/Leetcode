#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}bst;

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
}
