#pragma once
#include "Phone.h"


class Node
{
	friend class List;
public:
	Node();
	Node(int id, string make);

private:
	Phone p;
	Node *next;
}; typedef Node *nodePtr;
