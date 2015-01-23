#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <vector>

template <class T>
struct Node
{
	Node(const T& k) : 
		key{k},
		prev{nullptr},
		next{nullptr}
		{}

	Node* prev;
	Node* next;
	T key;
};

template <class T>
class LinkedList
{
	public:
		LinkedList();
		~LinkedList();

		Node<T>* search(const T& key);
		void insert(const T& key);
		void delete_node(Node<T>* node);
		void delete_node(const T& key);

		size_t count;
		inline size_t size() const { return count; };

		Node<T>* head;
};

template <class T>
LinkedList<T>::LinkedList() : head{nullptr}, count{0} {}

template <class T>
void LinkedList<T>::insert(const T& key)
{
	Node<T>* new_node = new Node<T>(key);
	new_node->next = head;

	if(head)	
	{
		head->prev = new_node;
	}

	head = new_node;
	new_node->prev = nullptr;

	++count;
}

template <class T>
Node<T>* LinkedList<T>::search(const T& key)
{
	Node<T>* current = head;

	while(current && current->key != key)
	{
		current = current->next;
	}

	return current;
}

template <class T>
void LinkedList<T>::delete_node(Node<T>* node)
{
	if(node->prev)
	{
		node->prev->next = node->next;
	}
	else
	{
		head = node->next;
	}
	if(node->next)
	{
		node->next->prev = node->prev;
	}

	delete(node);	
	--count;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	while(head != nullptr)
	{
		auto next = head->next;
		free(head);
		head = next;
	}
}

#endif //LINKEDLIST_H_