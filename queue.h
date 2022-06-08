#pragma once
#include "linked_list.h"

template<typename Data_type>
class queue : protected LINK_LIST<Data_type>
{
protected:
	size_t _size;
	size_t _max_size;
public:
	queue(const size_t max_size);
	bool is_empty();
	bool is_full();
	Data_type peek_head();
	Data_type peek_tail();
	void queue_push(Data_type);
	void queue_push_t(Data_type);
	void print_queue();
	~queue();
};

template<typename Data_type>
inline queue<Data_type>::queue(const size_t max_size) : LINK_LIST<Data_type>::LINK_LIST()
{
	_size = 0;
	_max_size = max_size;
}

template<typename Data_type>
inline bool queue<Data_type>::is_empty()
{
	return (this->is_empty()) ? true : false;
}

template<typename Data_type>
inline bool queue<Data_type>::is_full()
{
	return (this->length() == _max_size) ? true : false;
}

template<typename Data_type>
inline Data_type queue<Data_type>::peek_head()
{
	return (this->head)->data;
}

template<typename Data_type>
inline Data_type queue<Data_type>::peek_tail()
{
	return Data_type((this->tail())->data);
}

template<typename Data_type>
inline void queue<Data_type>::queue_push(Data_type _data)
{
	if (!this->is_full())
	{
		this->inserthead(_data);
	}
}

template<typename Data_type>
inline void queue<Data_type>::queue_push_t(Data_type _data)
{
	if (this->is_full())
	{
		this->inserthead(_data);
		this->deletetail();
	}
	else
	{
		this->queue_push(_data);
	}
}

template<typename Data_type>
inline void queue<Data_type>::print_queue()
{
	this->print();
}

template<typename Data_type>
inline queue<Data_type>::~queue()
{
	LINK_LIST<Data_type>::~LINK_LIST();
	_size = 0;
	_max_size = 0;
}