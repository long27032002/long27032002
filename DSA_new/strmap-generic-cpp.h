#pragma once

#include <string>
#include "linked-list-generic-cpp.h"



template <typename T>
class StrMap {
protected:
	struct STR_MAP_LIST_DATA {
		std::string key;
		T value;
	};

	LinkedList<STR_MAP_LIST_DATA>* entries;
	int size;

public:
	virtual int hasher(const std::string& key) {
		if (size == 0) return 0;
		return key[0] % size;
	}

	StrMap(int _size) {
		size = _size;
		entries = new LinkedList<STR_MAP_LIST_DATA>[size];
	}

	virtual ~StrMap() {
		delete[] entries;
	}

	void insert(const std::string& key, const T& value) {
		int hashValue = hasher(key);
		auto& entry = entries[hashValue];

		for (auto p = entry.head; p != NULL; p = p->next) {
			STR_MAP_LIST_DATA itemData = p->data;
			if (itemData.key == key) {
				itemData.value = value;
				return;
			}
		}

		STR_MAP_LIST_DATA item;
		item.key = key;
		item.value = value;
		entry.insertTail(item);
	}

	bool find(const std::string& key, T& value) {
		int hashValue = hasher(key);
		auto& entry = entries[hashValue];

		for (auto p = entry.head; p != NULL; p = p->next) {
			STR_MAP_LIST_DATA itemData = p->data;
			if (itemData.key == key) {
				value = itemData.value;
				return true;
			}
		}

		return false;
	}

	void remove(const std::string& key) {
		int hashValue = hasher(key);
		auto& entry = entries[hashValue];

		typename LinkedList<STR_MAP_LIST_DATA>::LIST_ITEM* q = NULL;
		for (auto p = entry.head; p != NULL; q = p, p = p->next) {
			STR_MAP_LIST_DATA itemData = p->data;
			if (itemData.key == key) {
				if (q == NULL)
					entry.deleteHead();
				else entry.deleteAfter(q);
				return;
			}
		}
	}

};