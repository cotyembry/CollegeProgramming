#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

// This is not sending anything out, but it is recieving a binary_tree (type) that is a pointer called "root"
void init_binary_tree (binary_tree *root) {
	// This is setting (*root) to NULL to be able to make sure the tree starts off right
	(*root) = NULL;
}


// This will return a boolean value but it does not bring anything into the program
boolean is_full (void) {
	binary_tree root;
	// All this is doing is seeing if there is enough space to add root
	root = (binary_tree) malloc (sizeof(struct treenode));
	// After trying to allocate memory, if root still equals NULL, the true boolean variable is returned
	if (root == NULL)
		return true;
	// Otherwise, the false boolean variable will be returned
	else
		return false;
}
// This program will take in root (which is a binary_tree - my own type which is a structure) and return a boolean value
boolean is_empty (binary_tree root) {
	// If the tree is empty, true will be returned
	if ((root == NULL))
		return true;
	// Otherwise the false boolean value will be returned
	else
		return false;
}
// This will bring in a pointer to root (because it is being changed) and numadd (the integer the user wants to add)
void add_binary_tree (binary_tree *root, int numadd) {
	// the program calls on is_empty and sends the address of root because it is going to be changed. it allocates for root then puts the numadd data the user wanted into the data portion of root then sets left and right of root to NULL
	if	(is_empty(*root)) {
		(*root) = (binary_tree) malloc (sizeof(struct treenode));
		(*root) -> data = numadd;
		(*root) -> left = NULL;
		(*root) -> right = NULL;
	}
	// If the is_empty function returns the false boolean value, and if the number to add is less than or equal to the root data portion, using recursion, the program sends the the left of root along with the number to be added. otherwise, it will send the right side of root with numadd
	else {
		if (numadd <= (*root) -> data)
			add_binary_tree(&(*root) -> left, numadd);
		else
			add_binary_tree(&(*root) -> right, numadd);
	}

}

void delete_binary_tree (binary_tree *root, int numdelete) {
	// consider the possibilities: Left child only, Right child only, Has two Children
binary_tree temp;

// If no children
if (!is_empty(*root)) {
	// if the number to be deleted is the same as the roots data, (the data we want) the progrtam will go through different filters to see if there is no children, right child only, left child only, or two children. the program will set temp = to (*root) so the data is not lost, then assign root to either = NULL (with no children), to = the (*root) left if left child only, to = (*root) right if right child only, and the bottom most 
	if (numdelete == (*root) -> data) {
		if ((*root) -> left == NULL && (*root) -> right == NULL) {
			temp = (*root);
			(*root) = NULL;
			printf("%d\n", temp -> data);
			free (temp);			
		
		}
		else {
			// Left child only
			if ((*root) -> left != NULL && (*root) -> right == NULL) {
				temp = (*root);
				(*root) = (*root) -> left;				
				printf("%d\n", temp -> data);
				free (temp);
			}
			else {
				// Right child only
				if ((*root) -> left == NULL && (*root) -> right != NULL) {
					temp = (*root);
					(*root) = (*root) -> right;
					printf("%d\n", temp -> data);
					free (temp);
				}
				else {
					// Since I have filtered from no children, to left child only/right child only, the only other option is two children
					temp = (*root) -> left;
					while (temp -> right != NULL) {
						temp = temp -> right;
					}
					temp -> right = (*root) -> right;
					temp = (*root);
					(*root) = (*root) -> left;
					printf("%d\n", temp -> data);
					free (temp);
				}
			}
		}
	}
	else {
		// this would happen if the number to delete is less than the roots data. if it is <= it will go to the left else it will go to the right subtree to filter accordingly
		if (numdelete <= (*root) -> data)
			delete_binary_tree(&(*root) -> left, numdelete);
		else
			delete_binary_tree(&(*root) -> right, numdelete);
	}
}
else {	
	// this would be the default if the data is not in the tree
	printf("Data is not in the tree!\n");
}
}
// this will bring in root pass by value that is a binary_tree structure. if the root is not empty, it will use recursion and send the left of root, print the data of root then send the right portion of root. this will work its way from the left treenode to the right to be able to pring in ascending order.
void LNR (binary_tree root) {
if  (!is_empty(root)) {
LNR (root -> left);
printf("%d ", root -> data);
LNR (root -> right);
}
}
// this works the same as LNR except it is exactly opposity
void RNL (binary_tree root) {
if (!is_empty(root)) {
RNL (root -> right);
printf("%d ", root -> data);
RNL (root -> left);
}
}
