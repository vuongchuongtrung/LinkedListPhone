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
	void insert(int id, string make); // insert at head
	void deleteMostRecent(); // delete at head
	
	void insert(int id, string make, int position);
private:
	Node *head;
	void display(ostream& os) const;
};
