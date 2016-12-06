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
		deleteAtHead();
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
				deleteAtHead();
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

void List::deleteAtHead()
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

void List::deleteAtRear()
{
	if (!head) // (head == NULL)
	{
		cout << "Cannot delete empty list!\n" << endl;
	}
	else
	{
		Node *previous = head;
		Node *current = head;
		// traverse to the end of the list
		if (head) // (head != NULL)
		{
			while (current->next != NULL) // (current != NULL)
			{
				previous = current;
				current = current->next;
			}
			previous->next = NULL;
			delete current;
		}
	}
}

void List::deletePhone(int id)
{	
	if (!head) // (head == NULL)
	{
		cout << "Cannot delete emply list!\n" << endl;
	}	
	else if (head->next == NULL) // only 1 node on the list
	{
		Node *temp = head;
		delete temp;
		head = NULL;
	}
	else if (head->p.id == id) // delete head ==> deleteMostRecent()
	{
		deleteAtHead();
	}
	else // traverse and find matching node for deleting
	{
		bool isDeleted = false;
		Node *previous;
		Node *current = head;
		while (current && !isDeleted) // (head != NULL) && (isDeleted == true)
		{			
			previous = current;
			current = current->next;
			if (current->p.id == id) // found matching
			{
				previous->next = current->next;
				delete current;
				isDeleted = true; // this will terminate the loop
			}
		}
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

void List::insertAtHead(int id, string make)
{
	Node *newNode = new Node(id, make);
	newNode->next = head;
	head = newNode;
}

void List::insertAtRear(int id, string make)
{
	Node *newNode = new Node(id, make);
	Node *current = head;
	Node *previous = NULL;
	while (current) // (current != NULL) ==> keep loop to the end
	{
		previous = current;
		current = current->next; // make progress
	}
	previous->next = newNode;
	newNode->next = current;
}

void List::insert(int id, string make, int position)
{
	Node *newNode = new Node(id, make);
	if (position <= 0) // insert at head
	{
		// could also call insertAtHead() to do the job
		newNode->next = head;
		head = newNode;
	}
	else
	{		 
		Node *previous = NULL;
		// initialise 2 lines below
		Node *current = head;
		int i = 0;
		while (i < position && current != NULL) // guards
		{
			previous = current;
			// make progress 2 line below
			current = current->next;
			i++; 
		}

		/* You can check either:
		 * if (current == NULL)
		 * if (i < position)
		 */
		if (i < position) // end of linked list ==> insert at rear
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

//void List::insert(int id, string make, int position)
//{
//	Node *newNode = new Node(id, make);
//	if (position <= 0) // insert at head
//	{
//		// could also call insertAtHead() to do the job
//		newNode->next = head;
//		head = newNode;
//	}
//	else
//	{
//		Node *current = head;
//		Node *previous = NULL;
//		for (int i = 0; i < position && current != NULL; current = current->next, i++)
//		{
//			previous = current;			
//		}
//
//		if (current == NULL) // end of linked list ==> insert at rear
//		{
//			previous->next = newNode;
//		}
//		else // insert in the middle of linked list
//		{			
//			previous->next = newNode;	
//			newNode->next = current;
//		}
//	}
//}
