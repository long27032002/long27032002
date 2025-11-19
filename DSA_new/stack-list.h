#pragma once

#include <iostream>

class Stack {
protected:
	struct Item;

	struct Item {
		int data;
		Item* next;
	};

	Item* head;

public:
	Stack()
		: head(nullptr)
	{
	}

	virtual ~Stack() {
		while (head != nullptr) {
			Item* p = head->next;
			delete head;
			head = p;
		}
	}

	bool push(int v) {
		Item* e = new Item;
		e->data = v;
		e->next = head;
		head = e;
		return true;
	}

	bool pop() {
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
