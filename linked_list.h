#pragma once
#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

template<typename Data_type>
struct node_type
{
	Data_type data;
	struct node_type* next;

	node_type(Data_type _data = 0) {
		data = _data;
		next = NULL;
	};
};

template<typename Data_type>
class LINK_LIST
{
public:
	struct node_type<Data_type>* head;
	struct node_type<Data_type>* tail();
	
	LINK_LIST();
	LINK_LIST(const size_t, Data_type*);

	/// <summary>
	/// Lengths this obj.
	/// </summary>
	/// <returns></returns>
	size_t length();

	/// <summary>
	/// Insertheads the specified temporary.
	/// </summary>
	/// <param name="tmp">Data_typehe temporary.</param>
	void inserthead(Data_type tmp);

	/// <summary>
	/// Inserttails the specified .
	/// </summary>
	/// <param name="tmp">Data_typehe temporary.</param>
	void inserttail(Data_type tmp);

	/// <summary>
	/// Insert the specified index.
	/// </summary>
	/// <param name="index">Index(start by 0).</param>
	/// <param name="_data">Data_typehe data</param>
	void insertafter(size_t index, Data_type _data);

	/// <summary>
	/// Prints this obj.
	/// </summary>
	void print();

	void operator = (const LINK_LIST<Data_type> parameter);
	
	LINK_LIST<Data_type> operator+(const LINK_LIST<Data_type> parameter);

	/// <summary>
	/// Sorts this instance.
	/// </summary>
	void sort();

	/// <summary>
	/// Swaps the specified.
	/// </summary>
	/// <param name="index_1">Data_typehe index fisrt.</param>
	/// <param name="index_2">Data_typehe index second.</param>
	void swap(const size_t index_1, const size_t index_2);

	virtual bool is_empty();
	
	/// <summary>
	/// Create a node in the specified index.
	/// </summary>
	/// <param name="index">Data_typehe index(start by 0).</param>
	/// <returns></returns>
	struct node_type<Data_type>* node_t(const size_t index);

	Data_type deletehead();

	struct node_type<Data_type>* deletetail();

	/// <summary>
	/// Delete the specified index.
	/// </summary>
	/// <param name="index">Data_typehe index(start by 0).</param>
	/// <returns></returns>
	struct node_type<Data_type>* deleteafter(const size_t index);

	~LINK_LIST();
};

template<typename Data_type>
inline LINK_LIST<Data_type>::LINK_LIST()
{
	LINK_LIST<Data_type>::head = NULL;
}

template<typename Data_type>
LINK_LIST<Data_type>::LINK_LIST(const size_t length, Data_type* tmp)
{
	head = new struct node_type<Data_type>(tmp[0]);
	struct node_type<Data_type>* cur = head;
	for (size_t i = 1; i < length; i++)
	{
		cur->next = new struct node_type<Data_type>(tmp[i]);
		cur = cur->next;
	}
}

template<typename Data_type>
LINK_LIST<Data_type>::~LINK_LIST()
{
	struct node_type<Data_type>* cur = head; head = NULL;
	struct node_type<Data_type>* tmp;
	while (cur != NULL)
	{
		tmp = cur;
		cur = cur->next;
		delete tmp;
	}
	delete cur;

}

template<typename Data_type>
size_t LINK_LIST<Data_type>::length()
{
	size_t count = 0;
	struct node_type<Data_type>* cur = LINK_LIST<Data_type>::head;
	while (cur != NULL)
	{
		cur = cur->next;
		count++;
	}
	return count;
}

template<typename Data_type>
inline void LINK_LIST<Data_type>::inserthead(Data_type _data)
{
	if (is_empty())
	{
		LINK_LIST<Data_type>::head = new struct node_type<Data_type>(_data);
	}
	else
	{
		struct node_type<Data_type>* temp = new struct node_type<Data_type>(head->data);
		temp->next = head->next;
		head->data = _data;
		head->next = temp;
	}
}

template<typename Data_type>
inline void LINK_LIST<Data_type>::inserttail(Data_type _data)
{
	struct node_type<Data_type>* tmp = head;
	struct node_type<Data_type>* temp = new struct node_type<Data_type>(_data);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = temp;
}

template<typename Data_type>
inline void LINK_LIST<Data_type>::insertafter(size_t t, Data_type _data)
{
	if (t == 0)
	{
		inserthead(_data);
	}
	else if (t == length()-1)
	{
		inserttail(_data);
	}
	else if (0 < t && t < (length()-1)){
		struct node_type<Data_type>* tmp = LINK_LIST::head;
		struct node_type<Data_type>* temp = new struct node_type<Data_type>(_data);
		for (size_t i = 1; i < t-1; i++)
			tmp = tmp->next;
		temp->next = tmp->next;
		tmp->next = temp;
	}
	else
		cout << "ERROR";
}

template<typename Data_type>
inline void LINK_LIST<Data_type>::print()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	struct node_type<Data_type>* temp = LINK_LIST::head;
	for (size_t i = 0; i < length(); i++)
	{
		cout << "(" << i + 1 << "," << temp->data << ")";
		if (i != length()-1)
		{
			cout << " -> ";
		}
		temp = temp->next;
	}
	cout << endl;
}

template<typename Data_type>
inline void LINK_LIST<Data_type>::operator=(const LINK_LIST<Data_type> parameter)
{
	if (this->head != NULL)
	{
		this->~LINK_LIST();
	}
	for (struct node_type<Data_type>* tmp = parameter.head; tmp != NULL; tmp = tmp->next)
	{
		this->inserttail(tmp->data);
	};
}

template<typename Data_type>
inline LINK_LIST<Data_type> LINK_LIST<Data_type>::operator+(const LINK_LIST<Data_type> parameter)
{
	LINK_LIST<Data_type> tmp;
	tmp = *this;
	for (struct node_type<Data_type>* cur = tmp.tail(); cur != NULL; cur = cur->next)
	{
		tmp.inserttail(cur->data);
	};
	return tmp;
}

template<typename Data_type>
inline void LINK_LIST<Data_type>::sort()
{
	for (size_t i = 0; i < this->length(); i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (node_t(j)->data > node_t(i)->data)
			{
				this->swap(i, j);
			}
		}
	}
}

template<typename Data_type>
inline void LINK_LIST<Data_type>::swap(const size_t index_1, const size_t index_2)
{
	struct node_type<Data_type>* node_1 = LINK_LIST<Data_type>::node_t(index_1);
	struct node_type<Data_type>* node_2 = LINK_LIST<Data_type>::node_t(index_2);
	auto tmp_t = node_1->data;
	node_1->data = node_2->data;
	node_2->data = tmp_t;
}

template<typename Data_type>
inline node_type<Data_type>* LINK_LIST<Data_type>::tail()
{
	struct node_type<Data_type>* temp = LINK_LIST<Data_type>::head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return temp;
}

template<typename Data_type>
inline bool LINK_LIST<Data_type>::is_empty()
{
	return (LINK_LIST<Data_type>::head == NULL) ? true : false;
}

template<typename Data_type>
inline node_type<Data_type>* LINK_LIST<Data_type>::node_t(const size_t index)
{
	struct node_type<Data_type>* cur = LINK_LIST::head;
	for (size_t i = 0; i < index; i++)
	{
		cur = cur->next;
	}
	return cur;
}

template<typename Data_type>
inline Data_type LINK_LIST<Data_type>::deletehead()
{
	struct node_type<Data_type>* buffer = LINK_LIST::head;
	Data_type tmp = buffer->data;
	head = head->next;
	delete buffer;
	return tmp;
}

template<typename Data_type>
inline node_type<Data_type>* LINK_LIST<Data_type>::deletetail()
{
	struct node_type<Data_type>* buffer = LINK_LIST::head;
	Data_type tmp = tail()->data;
	while ((buffer->next)->next != NULL)
		buffer = buffer->next;
	delete tail();
	buffer->next = NULL;
	return node_type<Data_type>*(tmp);
}

template<typename Data_type>
inline node_type<Data_type>* LINK_LIST<Data_type>::deleteafter(const size_t index)
{
	struct node_type<Data_type>* buffer = LINK_LIST::head;
	if (index == 0)
	{
		return deletehead();
	}
	else if (index == length() - 1)
	{
		return deletetail();
	}
	else if (0 < index && index < length() - 1) {
		for (size_t i = 0; i < index - 1; i++)
		{
			buffer = buffer->next;
		}
		struct node_type<Data_type>* after = buffer->next;
		Data_type tmp = after->data;
		buffer->next = (buffer->next)->next;
		delete after;
		return node_type<Data_type>*(tmp);
	}
	else
		cout << "ERROR";
}
