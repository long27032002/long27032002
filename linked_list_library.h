#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
struct node_type
{
	T data;
	struct node_type* next;

	node_type() {
		data = 0;
		next = NULL;
	}

	node_type(T _data) {
		data = _data;
		next = NULL;
	}
};

template<typename T>
class LINK_LIST
{
public:
	struct node_type<T>* head;

	LINK_LIST(const size_t, T*);

	/// <summary>
	/// Lengths this obj.
	/// </summary>
	/// <returns></returns>
	size_t length();

	/// <summary>
	/// Insertheads the specified temporary.
	/// </summary>
	/// <param name="tmp">The temporary.</param>
	void inserthead(T tmp);

	/// <summary>
	/// Inserttails the specified .
	/// </summary>
	/// <param name="tmp">The temporary.</param>
	void inserttail(T tmp);

	/// <summary>
	/// Insert the specified index.
	/// </summary>
	/// <param name="index">Index(start by 0).</param>
	/// <param name="_data">The data</param>
	void insertafter(size_t index, T _data);

	/// <summary>
	/// Prints this obj.
	/// </summary>
	void print();

	struct node_type<T>* tail();

	/// <summary>
	/// Create a node in the specified index.
	/// </summary>
	/// <param name="index">The index(start by 0).</param>
	/// <returns></returns>
	struct node_type<T>* node_t(const size_t index);

	struct node_type<T>* deletehead();

	struct node_type<T>* deletetail();

	/// <summary>
	/// Delete the specified index.
	/// </summary>
	/// <param name="index">The index(start by 0).</param>
	/// <returns></returns>
	struct node_type<T>* deleteafter(const size_t index);

	~LINK_LIST();
};

template<typename T>
LINK_LIST<T>::LINK_LIST(const size_t length, T* tmp)
{
	head = new struct node_type<T>(tmp[0]);
	struct node_type<T>* cur = head;
	for (size_t i = 1; i < length; i++)
	{
		cur->next = new struct node_type<T>(tmp[i]);
		cur = cur->next;
	}
}

template<typename T>
LINK_LIST<T>::~LINK_LIST()
{
	struct node_type<T>* cur = head;
	struct node_type<T>* tmp;
	while (cur != NULL)
	{
		tmp = cur;
		cur = cur->next;
		delete tmp;
	}
	delete cur;
}

template<typename T>
size_t LINK_LIST<T>::length()
{
	size_t count = 0;
	struct node_type<T>* cur = LINK_LIST<T>::head;
	while (cur != NULL)
	{
		cur = cur->next;
		count++;
	}
	return count;
}

template<typename T>
inline void LINK_LIST<T>::inserthead(T _data)
{
	struct node_type<T>* temp = new struct node_type<T>(head->data);
	temp->next = head->next;
	head->data = _data;
	head->next = temp;
}

template<typename T>
inline void LINK_LIST<T>::inserttail(T _data)
{
	struct node_type<T>* tmp = head;
	struct node_type<T>* temp = new struct node_type<T>(_data);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = temp;
}

template<typename T>
inline void LINK_LIST<T>::insertafter(size_t t, T _data)
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
		struct node_type<T>* tmp = LINK_LIST::head;
		struct node_type<T>* temp = new struct node_type<T>(_data);
		for (size_t i = 1; i < t-1; i++)
			tmp = tmp->next;
		temp->next = tmp->next;
		tmp->next = temp;
	}
	else
		cout << "ERROR";
}

template<typename T>
inline void LINK_LIST<T>::print()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	struct node_type<T>* temp = LINK_LIST::head;
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

template<typename T>
inline node_type<T>* LINK_LIST<T>::tail()
{
	struct node_type<T>* temp = LINK_LIST::head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return temp;
}


template<typename T>
inline node_type<T>* LINK_LIST<T>::node_t(const size_t index)
{
	struct node_type<T>* cur = LINK_LIST::head;
	for (size_t i = 0; i < index; i++)
	{
		cur = cur->next;
	}
	return cur;
}

template<typename T>
inline node_type<T>* LINK_LIST<T>::deletehead()
{
	struct node_type<T>* buffer = LINK_LIST::head;
	T tmp = buffer->data;
	head = head->next;
	delete buffer;
	return node_type<T>*(tmp);
}

template<typename T>
inline node_type<T>* LINK_LIST<T>::deletetail()
{
	struct node_type<T>* buffer = LINK_LIST::head;
	T tmp = tail()->data;
	while ((buffer->next)->next != NULL)
		buffer = buffer->next;
	delete tail();
	buffer->next = NULL;
	return node_type<T>*(tmp);
}

template<typename T>
inline node_type<T>* LINK_LIST<T>::deleteafter(const size_t index)
{
	struct node_type<T>* buffer = LINK_LIST::head;
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
		struct node_type<T>* after = buffer->next;
		T tmp = after->data;
		buffer->next = (buffer->next)->next;
		delete after;
		return node_type<T>*(tmp);
	}
	else
		cout << "ERROR";
}
