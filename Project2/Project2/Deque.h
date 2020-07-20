#pragma once

#include "Node.h"
#include <assert.h>
#include <iostream>
using namespace std;

template <class Type>
class Deque {
private:
	int s;
	Node<Type>* head;
	Node<Type>* tail;

public:
	Deque() { //deque constructor
		s = 0;
		head = nullptr;
		tail = nullptr;
	}

	~Deque() { //deque destructor NOTE: the 'n' counter and cout that is commented was used to confirm 
			   // the destructor is deleting the right amount of nodes.
		Node<Type>* current = new Node<Type> (head->getData(), head->getNext(), head->getPrev());
		//int n = 0;
		while (current != nullptr)
		{
			Node<Type>* deleteNode = new Node<Type> (current->getData(), current->getNext(), head->getPrev());
			deleteNode = current;
			current = current->getNext();
			delete deleteNode;
			//n++;
			//cout << n << endl;
		}
	}

	bool isEmpty() {//checks to see if the deque is empty or not
		if (s == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int size() { //returns the size of the deque
		return s;
	}

	Type first() { //returns the first element of the deque if it is not empty
		if (isEmpty())
		{
			throw std::runtime_error("Deque is empty.");
		}
		else
		{
			return head->getData();
		}
	}

	Type last() { //returns the last element of the deque if it is not empty
		if (isEmpty())
		{
			throw std::runtime_error("Deque is empty.");
		}
		else
		{
			return tail->getData();
		}
	}

	void insertFirst(Type o) { //inserts element at the beginning of deque
		if (s == 0) //the new node is set as both the head and tail of the deque if it is the only node
		{
			Node<Type>* newNode = new Node<Type>(o);
			head = newNode;
			tail = newNode;
			s++;
		}
		else
		{
			Node<Type>* newNode = new Node<Type>(o);
			newNode->setNext(head);
			head->setPrev(newNode);
			head = newNode;
			s++;
		}
	}

	void insertLast(Type o) { //inserts element at the beginning of deque
		if (s == 0)//the new node is set as both the head and tail of the deque if it is the only node
		{
			Node<Type>* newNode = new Node<Type>(o);
			tail = newNode;
			head = newNode;
			s++;
		}
		else
		{
			Node<Type>* newNode = new Node<Type>(o);
			newNode->setPrev(tail);
			tail->setNext(newNode);
			tail = newNode;
			s++;
		}
	}

	Type removeFirst() { //removes the first element of deque 
		if (isEmpty())
		{
			throw std::runtime_error("Deque is Empty");
		}
		else if (s == 1) //if there is only one node and it gets deleted, the deque will be empty and the head/tail will be nullptr
		{
			Node<Type>* deleteHead = new Node<Type>(head->getData(), head->getNext(), head->getPrev());
			deleteHead = head;
			Type value = deleteHead->getData();
			head = nullptr;
			tail = nullptr;
			delete deleteHead;
			s--;
			return value;
		}
		else
		{
			Node<Type>* deleteHead = new Node<Type>(head->getData(), head->getNext(), head->getPrev());
			deleteHead = head;
			Type value = deleteHead->getData();
			head = (head->getNext());
			head->setPrev(nullptr);
			delete deleteHead;
			s--;
			return value;
		}
	}

	Type removeLast() { //removes the last element of the deque
		if (isEmpty())
		{
			throw std::runtime_error("Deque is Empty");
		}
		else if (s == 1) //if there is only one node and it gets deleted, the deque will be empty and the head/tail will be nullptr
		{
			Node<Type>* deleteTail = new Node<Type>(tail->getData(), tail->getNext(), tail->getPrev());
			deleteTail = tail;
			Type value = deleteTail->getData();
			tail = nullptr;
			head = nullptr;
			delete deleteTail;
			s--;
			return value;
		}
		else
		{
			Node<Type>* deleteTail = new Node<Type>(tail->getData(), tail->getNext(), tail->getPrev());
			deleteTail = tail; 
			Type value = deleteTail->getData();
			tail = tail->getPrev();
			tail->setNext(nullptr);
			delete deleteTail;
			s--;
			return value; 
		}
			
	}
};