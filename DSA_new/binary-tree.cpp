#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct BinaryTree;

struct BinaryTree {
	string name;
	BinaryTree* left, * right;

	BinaryTree(const string& _name, BinaryTree* _left = NULL, BinaryTree* _right = NULL)
		: name(_name),
		left(_left),
		right(_right)
	{
	}

	virtual ~BinaryTree() {
		if (left != NULL) delete left;
		if (right != NULL) delete right;
	}

	void addToLeft(BinaryTree* t) {
		if (left != NULL) delete left;
		left = t;
	}
	void addToRight(BinaryTree* t) {
		if (right != NULL) delete right;
		right = t;
	}

	void deleteLeft() {
		if (left != NULL) delete left;
		left = NULL;
	}
	void deleteRight(BinaryTree* t) {
		if (right != NULL) delete right;
		right = NULL;
	}

	bool isLeaf() const {
		return left == NULL && right == NULL;
	}

	const BinaryTree* leftMost() const {
		return left != NULL ? left->leftMost() : this;
	}

	const BinaryTree* rightMost() const {
		return right != NULL ? right->rightMost() : this;
	}

	bool isFull() const {
		return ((left != NULL) == (right != NULL))
			&& (left == NULL || left->isFull())
			&& (right == NULL || right->isFull());
	}

	bool count() const {
		return 1
			+ (left == NULL ? 0 : left->count())
			+ (right == NULL ? 0 : right->count());
	}

	bool depth() const {
		return 1 + std::max(
			left == NULL ? 0 : left->depth(),
			right == NULL ? 0 : right->depth()
		);
	}

	BinaryTree* clone() const {
		return new BinaryTree(name,
			left == NULL ? NULL : left->clone(),
			right == NULL ? NULL : right->clone());
	}

	void traverse(void (*callback)(BinaryTree*)) {
		callback(this);
		if (left) left->traverse(callback);
		if (right) right->traverse(callback);
	}

	void printList() const {
		cout << "(" << name << ", [";
		if (left) left->printList();
		if (left != NULL && right != NULL) cout << ", ";
		if (right) right->printList();
		cout << "])";
	}

	void printTree() const {
		//...
	}
};


int main() {
	BinaryTree* a = new BinaryTree("a",
		new BinaryTree("b",
			new BinaryTree("f"), NULL),
		new BinaryTree("c",
			new BinaryTree("d"),
			new BinaryTree("e"))
	);

	a->printList();

	return 0;
}