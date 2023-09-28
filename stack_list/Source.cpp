#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct Element
{
	T data;
	Element* next;
	Element* prev;
};
template <class T>
class List
{
	Element<T>* head;
	Element<T>* tail;
	unsigned int count;
public:
	List();
	~List();
	void push(T data);
	void print();
	void pop();
	void delete_all();
};
template <class T>
List<T>::List()
{
	head = tail = NULL;
	count = 0;
}
template <class T>
List<T>:: ~List()
{
	delete_all();
}
template <class T>
void List<T>:: push(T data)
{
	Element<T>* elem = new Element<T>;
	elem->data = data;
	elem->next = elem->prev = NULL;
	if (head == NULL)
		head = tail = elem;
	else
	{
		tail->next = elem;
		elem->prev = tail;
		tail = elem;
	}
	count++;
}
template <class T>
void List<T>::print()
{
	Element<T>* elem = head;
	if (head == NULL)
	{
		cout << "No elements to print" << endl;
		return;
	}
	while (elem != NULL)
	{
		cout << elem->data << ' ';
		elem = elem->next;
	}
	cout << endl;
}
template <class T>
void List<T>::pop()
{
	Element<T>* del = tail;
	if (head == NULL)
	{
		cout << "No elements to delete" << endl;
		return;
	}
	else
	{
		tail = tail->prev;
		if (tail != NULL) 
			tail->next = NULL;
		else 
			head = NULL; 
		delete del;
		count--;
	}
}
template <class T>
void List<T>:: delete_all()
{
	while (head != NULL)
		pop();
}
void main()
{
	List<int> a;
	a.push(5);
	a.push(7);
	a.print();
	a.pop();
	a.print();
	a.pop();
	a.print();
	
}