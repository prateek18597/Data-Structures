#include<iostream>
#include<string.h>
using namespace std;

template <class T>
struct Node
{
	T value;
	Node<T> *prev=NULL;
	Node<T> *next=NULL;
};

template<class T>
class LinkedList
{
	public:
		Node<T> * head;
		Node<T> * tail;
		int length;
		LinkedList<T>()
		{
			head=NULL;
			tail=NULL;
			length=0;
		}

		bool isEmpty();
		int length1();
		void display();
		void append_front(T value);
		void append_back(T value);
};

template<class T>
bool LinkedList<T>::isEmpty()
{
	return length==0;
}

template<class T>
int LinkedList<T>::length1()
{
	return length;
}

template<class T>
void LinkedList<T>::append_front(T value)
{
	Node<T> *node=new Node<T>;
	node->value=value;

	if(length==0)
	{
		head=node;
		tail=node;
	}
	else
	{
		node->next=head;
		node->prev=NULL;
		head->prev=node;
		head=node;
		node=NULL;
	}
	length++;
}

template<class T>
void LinkedList<T>::append_back(T value)
{
	Node<T> *node=new Node<T>;
	node->value=value;

	if(length==0)
	{
		head=node;
		tail=node;
	}
	else
	{
		node->next=NULL;
		node->prev=tail;
		tail->next=node;
		tail=node;
		node=NULL;
	}
	length++;
}

template<class T>
void LinkedList<T>::display()
{
	Node<T> *node=new Node<T>;
	node=head;
	while(node->next!=NULL)
	{
		cout<<"-->"<<node->value;
		node=node->next;
	}
	cout<<"-->"<<node->value;
}

int main()
{
	LinkedList<string> list;
	list.append_back("Aaa");
	list.append_back("Bbb");
	list.append_back("Ccc");
	list.append_back("Ddd");
	list.display();
	return 0;
}