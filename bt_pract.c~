#include<stdio.h>
typedef struct bt {
	int data;
	struct bt *left;
	struct bt *right;
}bt_node;


bt_node* findLCA (bt_node* root,bt_node* n1,bt_node* n2)  {

	if(root == NULL || n1 == NULL || n2 == NULL) {
		return;
	}
	else if(root->data < n1->data && root->data < n2->data) {
		//Go to right
		findLCA(root->right,n1,n2);	
	} else if (root->data > n1->data && root->data > n2->data) {
		//GO to left
		findLCA(root->left,n1,n2);
	}
	return root;
	
}
