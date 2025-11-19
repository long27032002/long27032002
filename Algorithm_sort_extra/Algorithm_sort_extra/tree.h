#include <stdio.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

void heapify(int*, int);
void arr_to_tree(int*);
