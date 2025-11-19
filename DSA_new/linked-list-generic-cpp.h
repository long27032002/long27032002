#pragma once


template <typename T>
class LinkedList {
public:
	struct LIST_ITEM;

	struct LIST_ITEM {
		T data;
		LIST_ITEM* next;
	};

	LIST_ITEM* head;

public:
	LinkedList() {
		head = NULL;
	}

	virtual ~LinkedList() {
		LIST_ITEM* p, * q;
		for (p = head; p->next != NULL; p = q) {
			q = p->next;
			delete p;
		}

		head = NULL;
	}


	void insertHead(const T& v) {
		LIST_ITEM* e = new LIST_ITEM;
		e->data = v;
		e->next = head;
		head = e;
	}

	void insertTail(const T& v) {
		LIST_ITEM* e = new LIST_ITEM;
		e->data = v;
		e->next = NULL;

		if (head == NULL) {
			head = e;
		}
		else {
			LIST_ITEM* p;
			for (p = head; p->next != NULL; p = p->next);

			p->next = e;
		}
	}

	void insertAfter(LIST_ITEM* a, const T& v) {
		LIST_ITEM* e = new LIST_ITEM;
		e->data = v;
		e->next = a->next;
		a->next = e;
	}

	void deleteHead() {
		if (head == NULL) return;

		LIST_ITEM* p = head;
		head = head->next;
		delete p;
	}

	void deleteTail() {
		if (head == NULL) return;

		if (head->next == NULL) {
			free(head);
			head = NULL;
			return;
		}

		LIST_ITEM* p;
		for (p = head; p->next->next != NULL; p = p->next);

		delete p->next;
		p->next = NULL;
	}

	void deleteAfter(LIST_ITEM* a) {
		if (a->next == NULL) return;

		LIST_ITEM* p = a->next;
		a = a->next;
		delete p;
	}

	LIST_ITEM* seek(int i) {
		LIST_ITEM* p;
		for (p = head; i > 0 && p->next != NULL; p = p->next, i--);

		if (i == 0) return p;
		return NULL;
	}

	int length() const {
		int n;
		LIST_ITEM* p;

		for (p = head, n = 0; p != NULL; p = p->next, n++);

		return n;
	}

};