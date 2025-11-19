#pragma once

#include "linked-list.h"

typedef int (*STR_MAP_HASH_FUNCTION)(const char* key, int size);

typedef struct {
	LINKED_LIST* entries;
	int size;
	STR_MAP_HASH_FUNCTION hasher;
} STR_MAP;

typedef struct {
	char* key;
	void* value;
	int valueSize;
} STR_MAP_LIST_ITEM;


void strmapInit(STR_MAP* m, int size, STR_MAP_HASH_FUNCTION hasher);
void strmapDestroy(STR_MAP* m);

void strmapInsert(STR_MAP* m, const char* key, void* value, int valueSize);
void strmapFind(STR_MAP* m, const char* key, void** value, int* valueSize);
void strmapDelete(STR_MAP* m, const char* key);