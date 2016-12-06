#include "List.h"


List::List()
	: head(NULL)
{}

List::List(const List& l)
	: head(NULL)
{
	*this = l;
}

List::~List()
{
	while (head) // (head != NULL)
	{
		deleteMostRecent();
	}
}

List& List::operator=(const List& l)
{
	if (this != &l) // check for self-assignment
	{
		if (head) // (head != NULL)
		{
			while (head) // (head != NULL)
			{
				deleteMostRecent();
			}
		}

		Node *copyPtr = NULL;
		for (Node *originPtr = l.head; originPtr != NULL; originPtr = originPtr->next)
		{
			if (!head) // (head == NULL)
			{
				head = copyPtr = new Node(originPtr->p.id, originPtr->p.make);
			}
			else
			{
				copyPtr->next = new Node(originPtr->p.id, originPtr->p.make);
				copyPtr = copyPtr->next;
			}
		}
	}
	return *this;
}

void List::insert(int id, string make)
{
	Node *newNode = new Node(id, make);
	newNode->next = head;
	head = newNode;
}

void List::deleteMostRecent()
{
	if (!head) // (head == NULL)
	{
		cout << "Cannot delete empty list!\n" << endl;
	}
	else
	{
		Node *temp = head;
		head = head->next;
		delete temp;
	}
}

void List::display(ostream& os) const
{
	if (!head) // (head == NULL)
	{
		cout << "Cannot display empty list!\n" << endl;
	}
	else
	{
		cout << "Phone List Details\n"
			 << "==================" << endl;
		for (Node *temp = head; temp != NULL; temp = temp->next)
		{
			cout << temp->p.id << "   " << temp->p.make << endl;
		}
		cout << endl; // print empty line
	}
}

ostream& operator<<(ostream& os, const List& l)
{
	l.display(os);
	return os;
}

void List::insert(int id, string make, int position)
{
	Node *newNode = new Node(id, make);
	if (position <= 0) // insert at head
	{
		// could also call insert() to do the job
		newNode->next = head;
		head = newNode;
	}
	else
	{
		Node *current = head;
		Node *previous = NULL;
		for (int i = 0; i < position && current != NULL; current = current->next, i++)
		{
			previous = current;			
		}

		if (current == NULL) // end of linked list ==> insert at rear
		{
			previous->next = newNode;
		}
		else // insert in the middle of linked list
		{			
			previous->next = newNode;	
			newNode->next = current;
		}
	}
}
