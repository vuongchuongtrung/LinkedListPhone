#include "List.h"


int main()
{
	List l1;
	l1.insert(11, "HTC");
	l1.insert(22, "Asus");
	l1.insert(33, "Huawei");
	l1.insert(44, "SamSung");
	l1.insert(55, "iPhone");
	l1.insert(66, "Lenovo");
	//cout << l1;

	//l1.deleteMostRecent();
	//l1.deleteMostRecent();
	//cout << l1;

	//List l2 = l1;
	//cout << "List l2 = l1;" << endl;
	//cout << l2;

	//List l3(l1);
	//cout << "List l3(l1)" << endl;
	//cout << l3;


	int position = 3;
	l1.insert(99, "Test Phone", position);
	cout << l1;



	system("pause");
	return 0;
}
