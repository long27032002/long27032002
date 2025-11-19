#pragma once



struct __LIST_ITEM;

typedef struct __LIST_ITEM LIST_ITEM;
typedef LIST_ITEM* LINKED_LIST;

struct __LIST_ITEM {
	int data;
	LIST_ITEM* next;
};


void llInit(LINKED_LIST* pl);
void llInsertHead(LINKED_LIST* pl, int v);
void llInsertTail(LINKED_LIST* pl, int v);
void llInsertAfter(LINKED_LIST* pl, LIST_ITEM* a, int v);
void llDeleteHead(LINKED_LIST* pl);
void llDeleteTail(LINKED_LIST* pl);
void llDeleteAfter(LINKED_LIST* pl, LIST_ITEM* a);
void llPrintAll(LINKED_LIST l);
LIST_ITEM* llSeek(LINKED_LIST l, int i);
void llDeleteAll(LINKED_LIST* pl);
int llLength(LINKED_LIST l);

void llForEach(LINKED_LIST l, void (*func)(int*), void* user);