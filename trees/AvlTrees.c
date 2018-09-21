/*
    Problem Name : AVL Trees (Balanced BST with balance factor of 1 at every node)
    Description  : AVL tree is a self-balancing Binary Search Tree (BST) where 
    the difference between heights of left and right subtrees cannot be more than one for all nodes.
    Complexity	 : O(logN)
    Source		 : https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
	int height;
}TreeNode;

TreeNode* newNode(int data) {
	TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	
	return node;
}

int maximum(int a, int b) {
	return (a > b ? a : b);
}

int getHeight(TreeNode *node) {
	if(!node)
		return 0;
	
	return node->height;
	//return(1 + maximum(height(node->left), height(node->right));
}

int getTreeBalance(TreeNode *node) {
	if(!node)
		return 0;
	
	return (getHeight(node->left)-getHeight(node->right));
}

/**
	Right Rotation transitions the tree as below :

			node				 leftNode
		   /    \				 /      \
 	 leftNode   T3		==>	  	T1	   node
  	/       \			 			  /    \
    T1   rightSubTree		 rightSubTree  T3

*/
TreeNode* performRightRotation(TreeNode *node) {
	TreeNode *leftNode = node->left;
	TreeNode *rightSubTree = leftNode->right;
	
	// Perform rotation
	leftNode->right = node;
	node->left = rightSubTree;
	
	// Update heights
	node->height = 1 + maximum(getHeight(node->left), getHeight(node->right));
	leftNode->height = 1 + maximum(getHeight(leftNode->left), getHeight(leftNode->right));
	
	// Return new root
	return leftNode;
}


/**
	Left Rotation transitions the tree as below :

		node						rightNode
	   /    \					    /       \
	  T1   rightNode	==>		  node 		T2
	   	   /       \			 /    \
	 leftSubTree   T2			T1	leftSubTree

*/
TreeNode* performLeftRotation(TreeNode *node) {
	TreeNode *rightNode = node->right;
	TreeNode *leftSubTree = rightNode->left;
	
	// Perform rotation
	rightNode->left = node;
	node->right = leftSubTree;
	
	// Update heights
	node->height = 1 + maximum(getHeight(node->left), getHeight(node->right));
	rightNode->height = 1 + maximum(getHeight(rightNode->left), getHeight(rightNode->right));

	// Return new root	
	return rightNode;  
}

TreeNode* insertNode(TreeNode *node, int data) {
	
	// 1. Perform normal BST insertion
	if(!node) 
		return newNode(data);
	
	if(data < node->data)
		node->left = insertNode(node->left, data);
	else if(data > node->data)
		node->right = insertNode(node->right, data);
	else	// Equal keys are not allowed in BST
		return node;
	
	// 2. Update the height of this ancestor node
	node->height = 1 + maximum(getHeight(node->left), getHeight(node->right));
	
	// 3. Get balance factor of the current node to check if its unbalanced
	int balance = getTreeBalance(node);
	
	// 4. If the tree is unbalanced, then perform rotations 
	
	// 4.1 Left-Left Case 
	if(balance > 1 && data < node->left->data)
		return performRightRotation(node);
	
	// 4.2 Right-Right Case
	if(balance < -1 && data > node->right->data)
		return performLeftRotation(node);
		
	// 4.3 Left-Right Case
	if(balance > 1 && data > node->left->data) {
		node->left = performLeftRotation(node->left);
		return performRightRotation(node);
	}
	
	// 4.4 Right-Left Case
	if(balance < -1 && data < node->right->data) {
		node->right = performRightRotation(node->right);
		return performLeftRotation(node);
	}
	
	return node;
}

void preOrderTreeTraversal(TreeNode *node) {
	if(node) {
		printf("\t %d", node->data);
		preOrderTreeTraversal(node->left);
		preOrderTreeTraversal(node->right);
	}
}

int main (void) {
	TreeNode *root = NULL;
	
	root = insertNode(root, 10); 
	root = insertNode(root, 20); 
	root = insertNode(root, 50); 
	root = insertNode(root, 30); 
	root = insertNode(root, 40); 
	root = insertNode(root, 25); 
	root = insertNode(root, 60); 

	preOrderTreeTraversal(root);
	printf("\n");
}
