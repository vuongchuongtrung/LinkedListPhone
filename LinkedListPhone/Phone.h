#pragma once
#include <string>
using namespace std;


class Phone
{
	friend class List;
	friend class Node;
public:
	Phone();
	Phone(int id, string make);

private:
	int id;
	string make;
};
