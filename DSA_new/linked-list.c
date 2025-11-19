
#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

void llInit(LINKED_LIST* pl) {
	*pl = NULL;
}


void llInsertHead(LINKED_LIST* pl, int v) {
	LIST_ITEM* e = (LIST_ITEM*)malloc(sizeof(LIST_ITEM));
	e->data = v;
	e->next = *pl;
	*pl = e;
}

void llInsertTail(LINKED_LIST* pl, int v) {
	LIST_ITEM* e = (LIST_ITEM*)malloc(sizeof(LIST_ITEM));
	e->data = v;
	e->next = NULL;

	if (*pl == NULL) {
		*pl = e;
	}
	else {
		LIST_ITEM* p;
		for (p = *pl; p->next != NULL; p = p->next);

		p->next = e;
	}
}

void llInsertAfter(LINKED_LIST* pl, LIST_ITEM* a, int v) {
	LIST_ITEM* e = (LIST_ITEM*)malloc(sizeof(LIST_ITEM));
	e->data = v;
	e->next = a->next;
	a->next = e;
}

void llDeleteHead(LINKED_LIST* pl) {
	if (*pl == NULL) return;

	LIST_ITEM* p = *pl;
	*pl = (*pl)->next;
	free(p);
}

void llDeleteTail(LINKED_LIST* pl) {
	if (*pl == NULL) return;

	if ((*pl)->next == NULL) {
		free(*pl);
		*pl = NULL;
		return;
	}

	LIST_ITEM* p;
	for (p = *pl; p->next->next != NULL; p = p->next);

	free(p->next);
	p->next = NULL;
}


void llDeleteAfter(LINKED_LIST* pl, LIST_ITEM* a) {
	if (a->next == NULL) return;

	LIST_ITEM* p = a->next;
	a = a->next;
	free(p);
}

void llPrintAll(LINKED_LIST l) {
	for (LIST_ITEM* p = l; p != NULL; p = p->next) {
		printf("%d ", p->data);
	}
	printf("\n");
}

LIST_ITEM* llSeek(LINKED_LIST l, int i) {
	LIST_ITEM* p;
	for (p = l; i > 0 && p->next != NULL; p = p->next, i--);

	if (i == 0) return p;
	return NULL;
}

void llDeleteAll(LINKED_LIST* pl) {
	LIST_ITEM* p, * q;
	for (p = *pl; p->next != NULL; p = q) {
		q = p->next;
		free(p);
	}

	*pl = NULL;
}

int llLength(LINKED_LIST l) {
	int n;
	LIST_ITEM* p;

	for (p = l, n = 0; p != NULL; p = p->next, n++);

	return n;
}

void llForEach(LINKED_LIST l, void (*func)(int*, void*), void* user)
{
	for (LIST_ITEM* p = l; p != NULL; p = p->next)
		func(&p->data, user);

}