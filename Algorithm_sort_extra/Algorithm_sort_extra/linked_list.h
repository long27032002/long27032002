#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

typedef int llist_data;

typedef struct _newNodetype {
	llist_data data;
	struct _newNodetype* next;
} nodetype;

typedef struct {
	nodetype* head;
	nodetype* tail;
} LINKED_LIST;

nodetype* creat_new_node(llist_data);
bool is_empty(nodetype*);
void inserthead(llist_data);
void inserttail(nodetype*, llist_data);
void insertafter(nodetype*, llist_data);
void deletehead(nodetype*);
void deletetail(nodetype*);
void deleteafter(nodetype* ,int);
void deleteall(nodetype*);