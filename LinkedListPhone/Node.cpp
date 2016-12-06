#include "Node.h"


Node::Node()
{
	p.id = 0;
	p.make = "";
	next = NULL;
}

Node::Node(int id, string make)
{
	p.id = id;
	p.make = make;
	next = NULL;
}
