#define _CRT_SECURE_NO_WARNINGS

#include "strmap-generic.h"
#include <stdlib.h>
#include <string.h>
#include <memory.h>


void strmapInit(STR_MAP* m, int size, STR_MAP_HASH_FUNCTION hasher)
{
	m->size = size;
	m->hasher = hasher;

	m->entries = (LINKED_LIST*)malloc(size * sizeof(LINKED_LIST));
	for (int i = 0; i < size; i++)
		llInit(&(m->entries[i]));
}

void strmapDestroy(STR_MAP* m)
{
	for (int i = 0; i < m->size; i++)
		llDeleteAll(&(m->entries[i]));
}

void strmapInsert(STR_MAP* m, const char* key, void* value, int valueSize)
{
	int hashValue = m->hasher(key, m->size);
	LINKED_LIST* entry = &m->entries[hashValue];

	for (LIST_ITEM* p = *entry; p != NULL; p = p->next) {
		STR_MAP_LIST_ITEM* itemData = (STR_MAP_LIST_ITEM*)(p->data);
		if (strcmp(itemData->key, key) == 0) {
			free(itemData->value);

			itemData->value = malloc(valueSize);
			memcpy(itemData->value, value, valueSize);

			itemData->valueSize = valueSize;
			return;
		}
	}

	STR_MAP_LIST_ITEM item;

	int keyLen = (int)strlen(key);
	item.key = (char*)malloc(keyLen + 1);
	strcpy(item.key, key);

	item.value = malloc(valueSize);
	memcpy(item.value, value, valueSize);

	item.valueSize = valueSize;

	llInsertTail(entry, &item, sizeof(item));
}


void strmapFind(STR_MAP* m, const char* key, void** value, int* valueSize)
{
	int hashValue = m->hasher(key, m->size);
	LINKED_LIST* entry = &m->entries[hashValue];

	for (LIST_ITEM* p = *entry; p != NULL; p = p->next) {
		STR_MAP_LIST_ITEM* itemData = (STR_MAP_LIST_ITEM*)(p->data);
		if (strcmp(itemData->key, key) == 0) {
			*value = itemData->value;
			*valueSize = itemData->valueSize;
			return;
		}
	}

	*value = NULL;
}

void strmapDelete(STR_MAP* m, const char* key)
{
	int hashValue = m->hasher(key, m->size);
	LINKED_LIST* entry = &m->entries[hashValue];

	LIST_ITEM* q = NULL;
	for (LIST_ITEM* p = *entry; p != NULL; q = p, p = p->next) {
		STR_MAP_LIST_ITEM* itemData = (STR_MAP_LIST_ITEM*)(p->data);
		if (strcmp(itemData->key, key) == 0) {
			if (q == NULL)
				llDeleteHead(entry);
			else llDeleteAfter(entry, q);
			return;
		}
	}
}