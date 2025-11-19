#include <iostream>
#include <algorithm>
#include <string>

#include "linked-list-generic-cpp.h"


using namespace std;

struct Tree;

struct Tree {
	string name;
	LinkedList<Tree*> children;
};


int main() {
	Tree* a = new Tree;
	a->name = "a";

	Tree* b = new Tree;
	b->name = "b";
	a->children.insertTail(b);

	Tree* c = new Tree;
	c->name = "c";
	a->children.insertTail(c);

	Tree* d = new Tree;
	d->name = "d";
	c->children.insertTail(d);

	Tree* e = new Tree;
	e->name = "e";
	c->children.insertTail(e);

	Tree* f = new Tree;
	f->name = "f";
	c->children.insertTail(f);

	return 0;
}