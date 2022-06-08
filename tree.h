#pragma once
#include <iostream>
#include <string>

template<class Data_type>
struct node {
	Data_type data;
	node* right;
	node* left;

	node(Data_type _data) {
		data = _data;
		right = NULL;
		left = NULL;
	}
};

template<class Data_type>
class tree : node<Data_type>
{
public:
	struct node<Data_type> root;

	tree();
	tree(const size_t, Data_type[]);
	node<Data_type>* CreateNode(Data_type _data);
	bool is_empty();
	void insert(Data_type);
	node<Data_type>* CreateNodeLR(Data_type _data, node<Data_type>* _left, node<Data_type>* _right);
	void AddToLeft(node<Data_type>* p, node<Data_type>* c);
	void AddToRight(node<Data_type>* p, node<Data_type>* c);
	~tree();
};

template<class Data_type>
inline tree<Data_type>::tree()
{
	this->root->data = 0;
	this->root->left = NULL;
	this->root->right = NULL;
}

template<class Data_type>
inline tree<Data_type>::tree(const size_t, Data_type[])
{

}

template<class Data_type>
inline node<Data_type>* tree<Data_type>::CreateNode(Data_type _data)
{
	return node<Data_type>*(_data);
}

template<class Data_type>
inline bool tree<Data_type>::is_empty()
{
	return (tree<Data_type>::root == NULL) ? true : false;
}

template<class Data_type>
inline void tree<Data_type>::insert(Data_type _data)
{
	struct node<Data_type>* new_node(_data);
	struct node<Data_type>* current;
	struct node<Data_type>* parent;

	if (is_empty())
	{
		tree<Data_type>::root = new_node;
	}
	else
	{
		current = tree<Data_type>::root;
		parent = NULL;

		while (true)
		{
			parent = current;

			if (_data < current->data)
			{
				current = current->left;
				if (current == NULL)
				{
					parent->left = new_node;
					return;
				}
			}
			else
			{
				current = current->right;
				if (current == NULL)
				{
					parent->right = new_node;
					return;
				}
			}
		}
	}
}

template<class Data_type>
inline node<Data_type>* tree<Data_type>::CreateNodeLR(Data_type _data, node<Data_type>* _left, node<Data_type>* _right)
{
	struct node<Data_type>* tmp(_data);
	tmp->left = _left;
	tmp->right = _right;
	return tmp;
}

template<class Data_type>
inline void tree<Data_type>::AddToLeft(node<Data_type>* p, node<Data_type>* c)
{
	p->left = c;
}

template<class Data_type>
inline void tree<Data_type>::AddToRight(node<Data_type>* p, node<Data_type>* c)
{
	p->right = c;
}

template<class Data_type>
inline tree<Data_type>::~tree()
{

}
