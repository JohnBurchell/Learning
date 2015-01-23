#ifndef STACK_H_
#define STACK_H_

#include <vector>
#include <stdexcept>

#include "linkedlist.h"

template <class T>
class Stack
{
public:
	Stack<T>();
	~Stack<T>();

	T pop();
	T peek() const;

	bool empty() const;
	void push(const T& input);
	inline size_t size() const { return list.size(); };

private:
	LinkedList<T> list;
};

//Implementation
template<class T>
Stack<T>::Stack() :
	list()
{

};

template<class T>
bool Stack<T>::empty() const
{
	return list.size() == 0 ? true : false;
}

template<class T>
void Stack<T>::push(const T& input)
{	
	list.insert(input);
}

template<class T>
T Stack<T>::pop()
{
	if(empty())
	{
		throw std::out_of_range{"Stack<T>::pop() empty stack - stack underflow"};
	}

	auto value = list.head->key;
	list.delete_node(list.head);

	return value;
}

template<class T>
T Stack<T>::peek() const
{
	if(empty())
	{
		throw std::out_of_range{"Stack<T>::pee() empty stack - stack underflow"};
	}

	return list.head->key;
}

template<class T>
Stack<T>::~Stack()
{
	//Free anything here that might need to be freed
}

#endif //STACK_H_