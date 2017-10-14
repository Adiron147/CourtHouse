#ifndef __MY_LIST_H
#define __MY_LIST_H

#include <iostream>
#include "Node.h"
using namespace std;

// T has to overload operators: << , == , =
template <class T>
class MyList
{
    Node<T> *head, *tail;
	int size;
public:

    MyList();

    ~MyList();

    void addToEnd(const T& info);

	bool removeFirstNodeOf(const T& info);

	int getSize() const;

	const Node<T>* getHead() const;

	template <class T>
	friend ostream& operator<<(ostream& os, const MyList<T>& list)
	{
		Node<T>* headCopy = list.head;
		while(headCopy != nullptr)
		{
			os << headCopy->getData() << ' ';
			headCopy = headCopy->getNext();
		}
		return os;
	}
};

template <class T>
MyList<T>::MyList()
{
    head = nullptr;
    tail = nullptr;
	size = 0;
}

template <class T>
int MyList<T>::getSize() const
{
    return size;
}

template <class T>
const Node<T>* MyList<T>::getHead() const
{
	return head;
}

//Method adds info to the end of the list
template <class T>
void MyList<T>::addToEnd(const T& info)
{
    if(head == nullptr) //if our list is currently empty
    {
        head = new Node<T>; //Create new node of type T
        head->setData(info);
        tail = head;
    }
    else //if not empty add to the end and move the tail
    {
        Node<T>* temp = new Node<T>;
        temp->setData(info);
        temp->setNextNull();
        tail->setNext(temp);
        tail = tail->getNext();
    }

	++size;
}

//Method adds info to the end of the list
template <class T>
bool MyList<T>::removeFirstNodeOf(const T& info)
{
	bool isFound = false;
	if(head != nullptr)
	{
		Node<T>* listPtr = this->head->getNext();
		Node<T>* listPrevPtr = this->head;

		// Checking if the first node is the one to remove
		if(head->getData() == info)
		{
			// Checking if we have only one node in the list
			if(head == tail)
			{
				// Removing the first node
				this->tail = this->tail->getNext();
			}
		
			// Saving the head to delete it
			listPtr = head;

			// Removing the first node
			this->head = this->head->getNext();

			delete listPtr;

			--size;

			isFound = true;
		}
		else
		{
			while(listPtr != nullptr)
			{
				if(listPtr->getData() == info)
				{
					// Skipping the removed node
					listPrevPtr->setNext(listPtr->getNext());
					delete listPtr;
					
					isFound = true;

					--size;

					// We have found the node, no need to continue
					break;
				}
				else
				{
					listPtr = listPtr->getNext();
					listPrevPtr = listPrevPtr->getNext();
				}
			}
		}
	}

	return isFound;
}

template <class T>
MyList<T>::~MyList()
{
	// Starting from the head
	Node<T>* nodePtr = head;
	Node<T>* copyToDelete;
	while(nodePtr != nullptr)
	{
		// Saving the current node to release it
		copyToDelete = nodePtr;
		// Advancing for the next round
		nodePtr = nodePtr->getNext();

		// Deleting the current node
		delete copyToDelete;
	}
}

#endif __MY_LIST_H