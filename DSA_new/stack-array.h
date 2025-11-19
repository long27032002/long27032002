#pragma once
#include <iostream>

class Stack {
protected:
	int* a;
	int max_size, m;

public:
	Stack(int _max_size = 10)
		: max_size(_max_size)
	{
		m = 0;
		a = new int[max_size];
	}

	virtual ~Stack() {
		delete[] a;
	}

	bool push(int v) {
		if (m == max_size) return false;

		a[m] = v;
		m++;
		return true;
	}

	bool pop() {
		if (m == 0) return false;

		m--;
		return true;
	}

	int top() const {
		return a[m - 1];
	}

	bool isEmpty() const {
		return m == 0;
	}

	bool isFull() const {
		return m == max_size;
	}

	void print() const {
		std::cout << "[";
		for (int i = 0; i < m; i++)
			std::cout << " %d" << a[i];
		std::cout << " ]\n";
	}
};
