#ifndef binary_tree_h
#define binary_tree_h

#define true 1
#define false 0

typedef int boolean;

typedef struct treenode {
	int data;
	struct treenode *left, *right;
} *binary_tree;

void init_binary_tree (binary_tree *);

boolean is_empty (binary_tree);

boolean is_full (void);

void add_binary_tree (binary_tree *, int);

void delete_binary_tree (binary_tree *, int);

void LNR (binary_tree); 

void RNL (binary_tree);

#endif
