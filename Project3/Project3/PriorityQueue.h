#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "Node.h"
#include <exception>

using namespace std;

template <class Type>
class UnsortedPriorityQueue
{
private:
	int s;
	Node<Type>* head;
	Node<Type>* tail;

public:
	UnsortedPriorityQueue() 
	{
		s = 0;
		head = nullptr;
		tail = nullptr;
	};

	~UnsortedPriorityQueue()
	{

	}

	bool isEmpty() //returns if the PQ is empty based on the size
	{
		if (size() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int size() //returns the number of elements added to the PQ so far
	{
		return s;
	}

	// inserts a piece of data into the priority queue
	// simple insertion at the end of list without any sorting done
	void insertItem(Type data)
	{
		if (s == 0) 
		{
			Node<Type>* newNode = new Node<Type>(data);
			tail = newNode;
			head = newNode;
			s++;
		}
		else
		{
			Node<Type>* newNode = new Node<Type>(data);
			newNode->setPrev(tail);
			tail->setNext(newNode);
			tail = newNode;
			s++;
		}
	}

	// removes and returns the minimum value in the queue
	// throws an exception if the queue is empty
	Type removeMin()
	{
		if (isEmpty())
		{
			throw std::runtime_error("Priority queue is empty.");

		}
		else
		{
			Type min = minValue();
			Node<Type>* curr = new Node<Type>(head->getData(), head->getNext(), head->getPrev());
			while (curr->getData() != min)
			{
				curr = curr->getNext();
			}
			if (curr->getData() == head->getData()) //if min is head
			{
				head = head->getNext();
				delete curr;
			}
			else if (curr->getData() == tail->getData()) //if min is tail
			{
				tail = tail->getPrev();
				delete curr;
			}
			else //if the minimum value is not one of the end nodes
			{
				curr->getPrev()->setNext(curr->getNext()); //Pointing the previous node to the next node before deletion
				curr->getNext()->setPrev(curr->getPrev()); //Pointing the next node to the previous node before deletion
				delete curr;
			}
			return min;
		}
	}

	// return the minimum value in the queue without removing it
	// throws an exception if the queue is empty
	Type minValue()
	{
		if (isEmpty())
		{
			throw std::runtime_error("Priority queue is empty.");

		}
		else
		{
			Node<Type>* current = new Node<Type>(head->getData(), head->getNext(), head->getPrev());
			Type min = current->getData(); //initalize to the first value to have something to compare 
			while (current != nullptr) //traverse through the linked list and compare values to determine the min value
			{
				if (current->getData() < min)
				{
					min = current->getData();
				}
				current = current->getNext();
			}
			delete current;
			return min;
		}
	}
};

template <class Type>
class SortedPriorityQueue
{
private:
	int s;
	Node<Type>* head;
	Node<Type>* tail;

public:
	SortedPriorityQueue()
	{
		s = 0;
		head = nullptr;
		tail = nullptr;
	};

	~SortedPriorityQueue()
	{

	}

	bool isEmpty() //returns if the PQ is empty based on the size
	{
		if (size() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int size() //returns the number of elements added to the PQ so far
	{
		return s;
	}

	// inserts a piece of data into the priority queue
	// simple insertion at the end of list without any sorting done
	void insertItem(Type data)
	{
		if (s == 0)
		{
			Node<Type>* newNode = new Node<Type>(data);
			tail = newNode;
			head = newNode;
			s++;
		}
		else
		{
			Node<Type>* newNode = new Node<Type>(data);
			newNode->setPrev(tail);
			tail->setNext(newNode);
			tail = newNode;
			s++;
		}
	}

	// removes and returns the minimum value in the queue
	// throws an exception if the queue is empty
	Type removeMin()
	{
		if (isEmpty())
		{
			throw std::runtime_error("Priority queue is empty.");

		}
		else
		{
			Type min = minValue();
			Node<Type>* curr = new Node<Type>(head->getData(), head->getNext(), head->getPrev());
			while (curr->getData() != min)
			{
				curr = curr->getNext();
			}
			if (curr->getData() == head->getData()) //if min is head
			{
				head = head->getNext();
				head->setPrev(nullptr);
				delete curr;
			}
			else if (curr->getData() == tail->getData()) //if min is tail
			{
				tail = tail->getPrev();
				tail->setNext(nullptr);
				delete curr;
			}
			else //if the minimum value is not one of the end nodes
			{
				curr->getPrev()->setNext(curr->getNext()); //Pointing the previous node to the next node before deletion
				curr->getNext()->setPrev(curr->getPrev()); //Pointing the next node to the previous node before deletion
				delete curr;
			}
			return min;
		}
	}

	// return the minimum value in the queue without removing it
	// throws an exception if the queue is empty
	Type minValue()
	{
		if (isEmpty())
		{
			throw std::runtime_error("Priority queue is empty.");

		}
		else
		{
			Node<Type>* current = new Node<Type>(head->getData(), head->getNext(), head->getPrev());
			Type min = current->getData(); //initalize to the first value to have something to compare 
			while (current != nullptr) //traverse through the linked list and compare values to determine the min value
			{
				if (current->getData() < min)
				{
					min = current->getData();
				}
				current = current->getNext();
			}
			delete current;
			return min;
		}
	}
};

template <class Type>
class HeapPriorityQueue
{
private:
	int s;
	int n;
	Type HeapArray[n];
public:
	HeapPriorityQueue(int k)
	{
		s = 0;
		n = k;
	}

	~HeapPriorityQueue(void);

	bool isEmpty() //returns if the PQ is empty based on the size
	{
		if (size() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int size() //returns the number of elements added to the PQ so far
	{
		return s;
	}

	// inserts a piece of data into the priority queue
	void insertItem(Type data)
	{

	}

	// removes and returns the minimum value in the queue
	// throws an exception if the queue is empty
	Type removeMin(void);

	// return the minimum value in the queue without removing it
	// throws an exception if the queue is empty
	Type minValue(void);
};
#endif