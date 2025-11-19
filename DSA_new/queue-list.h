#pragma once

#include <iostream>

class Queue {
protected:
	struct Item;

	struct Item {
		int data;
		Item* next;
	};

	Item* head;

public:
	Queue()
		: head(nullptr)
	{
	}

	virtual ~Queue() {
		while (head != nullptr) {
			Item* p = head->next;
			delete head;
			head = p;
		}
	}

	bool enqueue(int v) {
		Item* e = new Item;
		e->data = v;
		e->next = nullptr;

		if (head == nullptr) {
			head = e;
			return true;
		}

		Item* p;
		for (p = head; p->next != nullptr; p = p->next);
		p->next = e;
		return true;
	}

	bool dequeue() {
		if (head == nullptr) return false;
		
		Item* p = head->next;
		delete head;
		head = p;
		return true;
	}

	int top() const {
		return head->data;
	}

	bool isEmpty() const {
		return head == nullptr;
	}

	bool isFull() const {
		return false;
	}

	void print() const {
		std::cout << "[ ";

		for (Item* p = head; p != nullptr; p = p->next)
			std::cout << " " << p->data;
		std::cout << " ]" << std::endl;
	}
};
