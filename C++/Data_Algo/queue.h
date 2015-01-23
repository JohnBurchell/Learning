#ifndef QUEUE_H_
#define QUEUE_H_

#include <array>
#include <stdexcept>

#include "linkedlist.h"

using namespace std;

template <class T>
class Queue
{
	public:
		Queue<T>();
		~Queue<T>();

		void enqueue(const T& item);
		T dequeue();
		void display();

		Node<T>* head;
		Node<T>* tail;

	private:
		LinkedList<T> list;
};

template <class T>
Queue<T>::Queue() :
	list{},
	head{nullptr},
	tail{nullptr}
{

}

template <class T>
void Queue<T>::enqueue(const T& item)
{
	list.insert(item);
	tail = list.head;
	if(!tail->next)
	{
		head = list.head;
	}
}

//Note! - This would be easier with a double linked list, we could go backwards
template <class T>
T Queue<T>::dequeue()
{
	auto value = head;
	list.delete_node(head);
	head = value;

	while(head->next)
	{
		head = head->next;
	}

	return value->key;
}

template <class T>
void Queue<T>::display()
{
	auto current = list.head;

	cout << "Start of the queue: ";

	while(current)
	{
		cout << current->key << " ";
		current = current->next;
	}

	cout << "\n";
}

template <class T>
Queue<T>::~Queue()
{
	//Free if needed
}


#endif //QUEUE_H_