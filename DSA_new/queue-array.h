#pragma once

#include <iostream>

class Queue {
protected:
	int* a;
	int head, count;
	int max_size;

public:
	Queue(int _max_size = 10)
		: max_size(_max_size)
	{
		a = new int[max_size];
		head = count = 0;
	}

	virtual ~Queue() {
		delete[] a;
	}

	bool enqueue(int v) {
		if (isFull()) return false;

		int i = (head + count) % max_size;
		a[i] = v;
		count++;
		return true;
	}

	bool dequeue() {
		if (isEmpty()) return false;

		head = (head + 1) % max_size;
		count--;
		return true;
	}

	int top() const {
		return a[head];
	}

	bool isFull() const {
		return count == max_size;
	}

	bool isEmpty() const {
		return count == 0;
	}

	void print() const {
		std::cout << "[ ";
		for (int i = 0; i < count; i++)
			std::cout << " " << a[(head + i) % max_size];
		std::cout << " ]" << std::endl;
	}
};