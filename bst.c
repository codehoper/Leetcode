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
	}else if(temp->data < data) {
		make_bst(&temp->left,data);	//semantics &(temp->left)
	}else {
		make_bst(&temp->right,data);
	}
}

void do_preorder(bst *root) {
	if(root != 0) {
		do_preorder(root->left);
		printf("%d\t",root->data);
		do_preorder(root->right);
	}
}



int main () {
	int tree_bag[] = {23,12,4,89,34,8,0,67};
	int i =0;
	bst *root = 0;
	for (;i<7;i++) {
		make_bst(&root,tree_bag[i]);	
	}
	do_preorder(root);
	printf("\n");
}
