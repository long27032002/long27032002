#include "linked_list.h"

nodetype* creat_new_node(llist_data _data) {
	nodetype* newnode = (nodetype*)malloc(sizeof(nodetype));

	if (newnode == NULL)
	{
		printf("ERROR!\nCan't create new node.\n");
		return NULL;
	}

	newnode->data = _data;
	newnode->next = NULL;
	return newnode;
};

bool is_empty(nodetype* head_t) {
	return (head_t->next == NULL) ? true : false;
};

void inserthead(nodetype* head, llist_data a) {
	nodetype* tmp = creat_new_node(a);
	
	if (tmp == NULL)
	{
		return;
	}

	tmp->next = head->next;
	head->next = tmp;
};

void inserttail(nodetype* head, llist_data a) {
	nodetype* tmp = creat_new_node( a);
	if (tmp == NULL)
		return;
	nodetype* head_t = head;
	while (head_t->next != NULL)
		head_t = head_t->next;
	head_t->next = tmp;
};

void insertafter(nodetype* head, int count, llist_data a) {
	nodetype* tmp = creat_new_node(a);
	nodetype* head_t = head;
	for (int i = count-1; i-- ;)
		head_t = head->next;
	tmp->next = head_t->next;
	head_t->next = tmp;
};

void deletehead(nodetype* head) {
	nodetype* tmp = head;
	head = head->next;
	free(tmp);
};

void deletetail(nodetype* list) {
	nodetype* head_t = list;
	while ((head_t->next)->next != NULL);
	free(head_t->next);
	head_t->next = NULL;
};

void deleteafter(nodetype* head, int a) {
	nodetype* head_t = head;
	for (size_t i = a; i--;)
	{
		head_t = head_t->next;
	}
	nodetype* tmp = head_t->next;
	head_t = (head_t->next)->next;
	free(tmp);
};

void deleteall(nodetype* head) {
	nodetype* p;
	for (p = head; head->next != NULL; p = head, head = head->next)
		free(p);
	free(head);
};