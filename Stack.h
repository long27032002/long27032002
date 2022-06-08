#pragma once
#include "linked_list.h"

template<typename Data_type>
class stack : protected LINK_LIST<Data_type>
{
protected:
	size_t max_size;
	size_t _size;
public:
	stack(const size_t);
	stack(Data_type[], const int);
	bool is_empty();
	bool is_full();
	Data_type peek();
	void push_stack(Data_type);
	Data_type delete_top();
	void print_stack();
	~stack();
};

template<typename Data_type>
inline stack<Data_type>::stack(const size_t _max_size) : LINK_LIST<Data_type>::LINK_LIST() 
{
	max_size = _max_size;
	_size = 0;
}

template<typename Data_type>
inline stack<Data_type>::stack(Data_type Arr_data[], const int length)
{
	this->max_size = 0;
	for (size_t i = 0; i < length; i++)
	{
		this->max_size++;
		this->push_stack(Arr_data[i]);
	}
}

template<typename Data_type>
inline bool stack<Data_type>::is_empty()
{
	return LINK_LIST<Data_type>::is_empty();
}
template<typename Data_type>
inline bool stack<Data_type>::is_full()
{
	return (_size == max_size) ? true : false;
}

template<typename Data_type>
inline Data_type stack<Data_type>::peek()
{
	return (this->head)->data;
}


template<typename Data_type>
inline void stack<Data_type>::push_stack(Data_type tmp)
{
	if (!is_full())
	{
		this->inserthead(tmp);
	}
	else {
		cout << "Stack is full!" << endl;
	}
}

template<typename Data_type>
inline Data_type stack<Data_type>::delete_top()
{
	if (is_empty())
	{
		return  0;
	}
	else {
		return this->deletehead();
	}
}

template<typename Data_type>
inline void stack<Data_type>::print_stack()
{
	stack<Data_type>::print();
};

template<typename Data_type>
inline stack<Data_type>::~stack()
{
	LINK_LIST<Data_type>::~LINK_LIST();
	max_size = 0;
	_size = 0;
};