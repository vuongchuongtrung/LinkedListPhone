#include "List.h"


int main()
{
	List l1;
	l1.insertAtHead(11, "HTC");
	l1.insertAtHead(22, "Asus");
	l1.insertAtHead(33, "Huawei");
	l1.insertAtHead(44, "SamSung");
	l1.insertAtHead(55, "iPhone");

	l1.insertAtRear(66, "Lenovo");
	//cout << l1;

	//l1.deleteAtHead();
	//l1.deleteAtHead();
	//cout << l1;

	//List l2 = l1;
	//cout << "List l2 = l1;" << endl;
	//cout << l2;

	//List l3(l1);
	//cout << "List l3(l1)" << endl;
	//cout << l3;


	// this is working
	//int position = 3;
	//l1.insert(99, "Test Phone", position);
	//cout << l1;

	//int id = 66;
	//l1.deletePhone(id);
	//cout << l1;

	l1.deleteAtRear();
	cout << l1;

	system("pause");
	return 0;
}
