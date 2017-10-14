#ifndef __NODE_H
#define __NODE_H

// T has to overload operators: << , == , =
template <class T>
class Node
{
private:
    T data; //the object information
    Node* next; //pointer to the next node element

public:
	Node();

    void setData(const T& data);
	const T& getData() const;

	void setNext(Node*& next);
	const Node* getNext() const;
	Node*& getNext();

	void setNextNull();
};

template <class T>
Node<T>::Node()
{
	next = nullptr;
}

template <class T>
void Node<T>::setData(const T& data)
{
	this->data = data;
}

template <class T>
const T& Node<T>::getData() const
{
	return data;
}

template <class T>
void Node<T>::setNext(Node*& next)
{
	this->next = next;
}

template <class T>
const Node<T>* Node<T>::getNext() const
{
	return this->next;
}

template <class T>
Node<T>*& Node<T>::getNext()
{
	return this->next;
}

template <class T>
void Node<T>::setNextNull()
{
	this->next = nullptr;
}

#endif __NODE_H