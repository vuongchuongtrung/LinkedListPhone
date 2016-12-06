#pragma once
#include "Node.h"
#include <iostream>
using namespace std;


class List
{
public:
	friend ostream& operator<<(ostream& os, const List& l);

	List();
	List(const List& l);
	~List();
	
	List& operator=(const List& l);
	void deleteMostRecent(); // delete at head
	void deletePhone(int id);
	
	void insertAtHead(int id, string make); // insert at head
	void insertAtRear(int id, string make); // insert at rear
	void insert(int id, string make, int position);

private:
	Node *head;
	void display(ostream& os) const;
};
